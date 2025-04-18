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
        SL_INFO("ExampleLayer::Update");
    }

    void OnEvent(SLEngine::Event& event) override
    {
        SL_TRACE("{0}", event.ToString());
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