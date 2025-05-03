#pragma once

#include "SLEngine/Core/Base.h"
#include "SLEngine/Core/Window.h"
#include "LayerStack.h"
#include "SLEngine/Events/Event.h"
#include "SLEngine/Events/ApplicationEvent.h"

#include "SLEngine/Core/Timestep.h"
#include "SLEngine/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace SLEngine
{
	class Application
	{
	public:
		Application(const std::string& name = "SLEngine App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
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
		friend int ::main(int argc, char** argv);
	};

	Application* CreateApplication();
}

