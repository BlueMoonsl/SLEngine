#pragma once

#include "SLEngine/Core/Layer.h"
#include "SLEngine/Events/KeyEvent.h"
#include "SLEngine/Events/MouseEvent.h"
#include "SLEngine/Events/ApplicationEvent.h"

namespace SLEngine {

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void Begin();
		void End();
    private:
        float m_Time = 0.0f;
    };

}