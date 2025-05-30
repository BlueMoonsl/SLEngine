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
        virtual void OnEvent(Event& e) override;

        void Begin();
		void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();

		uint32_t GetActiveWidgetID() const;
    private:
        bool m_BlockEvents = true;
    };

}
