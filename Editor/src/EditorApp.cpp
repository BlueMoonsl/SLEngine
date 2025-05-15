#include <SLEngine.h>
#include <SLEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace SLEngine {

    class Editor : public Application
    {
    public:
		Editor(const ApplicationSpecification& spec)
			: Application(spec)
        {
            PushLayer(new EditorLayer());
        }
    };

	Application* CreateApplication(ApplicationCommandLineArgs args)
    {
		ApplicationSpecification spec;
		spec.Name = "Editor";
		spec.CommandLineArgs = args;

		return new Editor(spec);
    }

}
