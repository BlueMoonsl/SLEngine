#pragma once

#include "SLEngine/Core/Core.h"
#include "SLEngine/Core/Window.h"
#include "LayerStack.h"
#include "SLEngine/Events/Event.h"
#include "SLEngine/Events/ApplicationEvent.h"

#include "SLEngine/Core/Timestep.h"
#include "SLEngine/ImGui/ImGuiLayer.h"

namespace SLEngine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

