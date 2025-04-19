#pragma once

#include "SLEngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace SLEngine {

    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow* m_WindowHandle;
    };

}