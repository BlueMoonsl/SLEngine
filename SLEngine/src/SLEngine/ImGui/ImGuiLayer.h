#pragma once

#include "SLEngine/Layer.h"
#include "SLEngine/Events/KeyEvent.h"
#include "SLEngine/Events/MouseEvent.h"
#include "SLEngine/Events/ApplicationEvent.h"

namespace SLEngine {

    class SLENGINE_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
		void End();
    private:
        float m_Time = 0.0f;
    };

}