#pragma once

#include "slpch.h"
#include "SLEngine/Core/Core.h"
#include "SLEngine/Events/Event.h"

namespace SLEngine {

    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "SLEngine",
            unsigned int width = 1280,
            unsigned int height = 720)
            : Title(title), Width(width), Height(height) {
        }
    };

    class SLENGINE_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        //Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
        //平台类型应该在编译时期就确定的，所以创建对应平台的窗口函数应为静态
        static Window* Create(const WindowProps& props = WindowProps());
    };
}
