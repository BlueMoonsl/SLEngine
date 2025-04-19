#include "slpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace SLEngine {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        SL_CORE_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        // 将我们窗口的上下文设置为当前线程的主上下文
        glfwMakeContextCurrent(m_WindowHandle);
        // 获取显卡OpenGL函数定义的地址
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SL_CORE_ASSERT(status, "Failed to initialize Glad!");
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }

}