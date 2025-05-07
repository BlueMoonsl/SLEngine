#pragma once

#include "SLEngine/Core/Base.h"
#include "SLEngine/Core/Log.h"
#include "SLEngine/Scene/Scene.h"
#include "SLEngine/Scene/Entity.h"

namespace SLEngine {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}
