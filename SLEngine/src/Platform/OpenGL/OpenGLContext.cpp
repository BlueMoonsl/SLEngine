#include "slpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace SLEngine {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        SL_CORE_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        SL_PROFILE_FUNCTION();

        // 将我们窗口的上下文设置为当前线程的主上下文
        glfwMakeContextCurrent(m_WindowHandle);
        // 获取显卡OpenGL函数定义的地址
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SL_CORE_ASSERT(status, "Failed to initialize Glad!");
        // 输出显卡信息
        SL_CORE_INFO("OpenGL Info:");
        SL_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        SL_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        SL_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		SL_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "SLEngine requires at least OpenGL version 4.5!");
    }

    void OpenGLContext::SwapBuffers()
    {
        SL_PROFILE_FUNCTION();

        glfwSwapBuffers(m_WindowHandle);
    }

}
