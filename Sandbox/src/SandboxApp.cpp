#include <SLEngine.h>
#include <SLEngine/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public SLEngine::Application {
public:
	Sandbox(const SLEngine::ApplicationSpecification& specification)
		: SLEngine::Application(specification)
	{
        // PushLayer(new ExampleLayer());
        PushLayer(new Sandbox2D());
	}
	~Sandbox()
	{

	}
};

SLEngine::Application* SLEngine::CreateApplication(SLEngine::ApplicationCommandLineArgs args) {
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../Editor";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
