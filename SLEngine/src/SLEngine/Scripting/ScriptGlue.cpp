#include "slpch.h"
#include "ScriptGlue.h"
#include "ScriptEngine.h"

#include "SLEngine/Core/UUID.h"
#include "SLEngine/Core/KeyCodes.h"
#include "SLEngine/Core/Input.h"

#include "SLEngine/Scene/Scene.h"
#include "SLEngine/Scene/Entity.h"

#include "SLEngine/Physics/Physics2D.h"

#include "mono/metadata/object.h"
#include "mono/metadata/reflection.h"

#include "box2d/b2_body.h"

namespace SLEngine {

	static std::unordered_map<MonoType*, std::function<bool(Entity)>> s_EntityHasComponentFuncs;

#define SL_ADD_INTERNAL_CALL(Name) mono_add_internal_call("SLEngine.InternalCalls::" #Name, Name)

	static void NativeLog(MonoString* string, int parameter)
	{
		char* cStr = mono_string_to_utf8(string);
		std::string str(cStr);
		mono_free(cStr);
		std::cout << str << ", " << parameter << std::endl;
	}

	static void NativeLog_Vector(glm::vec3* parameter, glm::vec3* outResult)
	{
		SL_CORE_WARN("Value: ({}, {}, {})", parameter->x, parameter->y, parameter->z);
		*outResult = glm::normalize(*parameter);
	}

	static float NativeLog_VectorDot(glm::vec3* parameter)
	{
		SL_CORE_WARN("Value: ({}, {}, {})", parameter->x, parameter->y, parameter->z);
		return glm::dot(*parameter, *parameter);
	}

	static MonoObject* GetScriptInstance(UUID entityID)
	{
		return ScriptEngine::GetManagedInstance(entityID);
	}

	static bool Entity_HasComponent(UUID entityID, MonoReflectionType* componentType)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		MonoType* managedType = mono_reflection_type_get_type(componentType);
		SL_CORE_ASSERT(s_EntityHasComponentFuncs.find(managedType) != s_EntityHasComponentFuncs.end());
		return s_EntityHasComponentFuncs.at(managedType)(entity);
	}

	static uint64_t Entity_FindEntityByName(MonoString* name)
	{
		char* nameCStr = mono_string_to_utf8(name);

		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->FindEntityByName(nameCStr);
		mono_free(nameCStr);

		if (!entity)
			return 0;

		return entity.GetUUID();
	}

	static void TransformComponent_GetTranslation(UUID entityID, glm::vec3* outTranslation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		*outTranslation = entity.GetComponent<TransformComponent>().Translation;
	}

	static void TransformComponent_SetTranslation(UUID entityID, glm::vec3* translation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		entity.GetComponent<TransformComponent>().Translation = *translation;
	}

	static void Rigidbody2DComponent_ApplyLinearImpulse(UUID entityID, glm::vec2* impulse, glm::vec2* point, bool wake)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->ApplyLinearImpulse(b2Vec2(impulse->x, impulse->y), b2Vec2(point->x, point->y), wake);
	}

	static void Rigidbody2DComponent_ApplyLinearImpulseToCenter(UUID entityID, glm::vec2* impulse, bool wake)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->ApplyLinearImpulseToCenter(b2Vec2(impulse->x, impulse->y), wake);
	}

	static void Rigidbody2DComponent_GetLinearVelocity(UUID entityID, glm::vec2* outLinearVelocity)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		const b2Vec2& linearVelocity = body->GetLinearVelocity();
		*outLinearVelocity = glm::vec2(linearVelocity.x, linearVelocity.y);
	}

	static Rigidbody2DComponent::BodyType Rigidbody2DComponent_GetType(UUID entityID)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		return Utils::Rigidbody2DTypeFromBox2DBody(body->GetType());
	}

	static void Rigidbody2DComponent_SetType(UUID entityID, Rigidbody2DComponent::BodyType bodyType)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		SL_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		SL_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->SetType(Utils::Rigidbody2DTypeToBox2DBody(bodyType));
	}

	static bool Input_IsKeyDown(KeyCode keycode)
	{
		return Input::IsKeyPressed(keycode);
	}

	template<typename... Component>
	static void RegisterComponent()
	{
		([]()
			{
				std::string_view typeName = typeid(Component).name();
				size_t pos = typeName.find_last_of(':');
				std::string_view structName = typeName.substr(pos + 1);
				std::string managedTypename = fmt::format("SLEngine.{}", structName);

				MonoType* managedType = mono_reflection_type_from_name(managedTypename.data(), ScriptEngine::GetCoreAssemblyImage());
				if (!managedType)
				{
					SL_CORE_ERROR("Could not find component type {}", managedTypename);
					return;
				}
				s_EntityHasComponentFuncs[managedType] = [](Entity entity) { return entity.HasComponent<Component>(); };
			}(), ...);
	}

	template<typename... Component>
	static void RegisterComponent(ComponentGroup<Component...>)
	{
		RegisterComponent<Component...>();
	}

	void ScriptGlue::RegisterComponents()
	{
		s_EntityHasComponentFuncs.clear();
		RegisterComponent(AllComponents{});
	}

	void ScriptGlue::RegisterFunctions()
	{
		SL_ADD_INTERNAL_CALL(NativeLog);
		SL_ADD_INTERNAL_CALL(NativeLog_Vector);
		SL_ADD_INTERNAL_CALL(NativeLog_VectorDot);
		
		SL_ADD_INTERNAL_CALL(GetScriptInstance);
		
		SL_ADD_INTERNAL_CALL(Entity_HasComponent);
		SL_ADD_INTERNAL_CALL(Entity_FindEntityByName);
		
		SL_ADD_INTERNAL_CALL(TransformComponent_GetTranslation);
		SL_ADD_INTERNAL_CALL(TransformComponent_SetTranslation);
		
		SL_ADD_INTERNAL_CALL(Rigidbody2DComponent_ApplyLinearImpulse);
		SL_ADD_INTERNAL_CALL(Rigidbody2DComponent_ApplyLinearImpulseToCenter);
		SL_ADD_INTERNAL_CALL(Rigidbody2DComponent_GetLinearVelocity);
		SL_ADD_INTERNAL_CALL(Rigidbody2DComponent_GetType);
		SL_ADD_INTERNAL_CALL(Rigidbody2DComponent_SetType);

		SL_ADD_INTERNAL_CALL(Input_IsKeyDown);
	}

}
