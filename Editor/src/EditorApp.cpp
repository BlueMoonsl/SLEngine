#include <SLEngine.h>
#include <SLEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace SLEngine {

    class HazelEditor : public Application
    {
    public:
        HazelEditor()
            : Application("Hazel Editor")
        {
            PushLayer(new EditorLayer());
        }

        ~HazelEditor()
        {
        }
    };

    Application* CreateApplication()
    {
        return new HazelEditor();
    }

}