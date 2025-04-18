#include <SLEngine.h>

class ExampleLayer : public SLEngine::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
		if (SLEngine::Input::IsKeyPressed(SL_KEY_TAB))
			SL_TRACE("Tab key is pressed (poll)!");
    }

    void OnEvent(SLEngine::Event& event) override
    {
		if (event.GetEventType() == SLEngine::EventType::KeyPressed)
		{
			SLEngine::KeyPressedEvent& e = (SLEngine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SL_KEY_TAB)
				SL_TRACE("Tab key is pressed (event)!");
			SL_TRACE("{0}", (char)e.GetKeyCode());
		}
    }

};

class Sandbox : public SLEngine::Application {
public:
	Sandbox()
	{
        PushLayer(new ExampleLayer());
        PushOverlay(new SLEngine::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

SLEngine::Application* SLEngine::CreateApplication() {
	return new Sandbox();
}