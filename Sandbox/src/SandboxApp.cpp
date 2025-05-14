#include <SLEngine.h>
#include <SLEngine/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public SLEngine::Application {
public:
	Sandbox(SLEngine::ApplicationCommandLineArgs args)
	{
        // PushLayer(new ExampleLayer());
        PushLayer(new Sandbox2D());
	}
	~Sandbox()
	{

	}
};

SLEngine::Application* SLEngine::CreateApplication(SLEngine::ApplicationCommandLineArgs args) {
	return new Sandbox(args);
}
