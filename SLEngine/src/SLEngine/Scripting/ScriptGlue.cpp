#include "slpch.h"
#include "ScriptGlue.h"

#include "mono/metadata/object.h"

namespace SLEngine {

#define SL_ADD_INTERNAL_CALL(Name) mono_add_internal_call("SLEngine.InternalCalls::" #Name, Name)

	static void NativeLog(MonoString* string, int parameter)
	{
		char* cStr = mono_string_to_utf8(string);
		std::string str(cStr);
		mono_free(cStr);
		std::cout << str << ", " << parameter << std::endl;
	}

	/*static void NativeLog_Vector(glm::vec3* parameter, glm::vec3* outResult)
	{
		SL_CORE_WARN("Value: {0}", *parameter);
		*outResult = glm::normalize(*parameter);
	}

	static float NativeLog_VectorDot(glm::vec3* parameter)
	{
		SL_CORE_WARN("Value: {0}", *parameter);
		return glm::dot(*parameter, *parameter);
	}*/

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

	void ScriptGlue::RegisterFunctions()
	{
		SL_ADD_INTERNAL_CALL(NativeLog);
		SL_ADD_INTERNAL_CALL(NativeLog_Vector);
		SL_ADD_INTERNAL_CALL(NativeLog_VectorDot);
	}

}
