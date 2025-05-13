#include <SLEngine.h>
#include <SLEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace SLEngine {

    class Editor : public Application
    {
    public:
		Editor(ApplicationCommandLineArgs args)
			: Application("Editor", args)
        {
            PushLayer(new EditorLayer());
        }

        ~Editor()
        {
        }
    };

	Application* CreateApplication(ApplicationCommandLineArgs args)
    {
		return new Editor(args);
    }

}
