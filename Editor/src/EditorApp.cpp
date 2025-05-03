#include <SLEngine.h>
#include <SLEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace SLEngine {

    class Editor : public Application
    {
    public:
        Editor()
            : Application("SLEngine Editor")
        {
            PushLayer(new EditorLayer());
        }

        ~Editor()
        {
        }
    };

    Application* CreateApplication()
    {
        return new Editor();
    }

}