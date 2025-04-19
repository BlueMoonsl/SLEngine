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
        // �����Ǵ��ڵ�����������Ϊ��ǰ�̵߳���������
        glfwMakeContextCurrent(m_WindowHandle);
        // ��ȡ�Կ�OpenGL��������ĵ�ַ
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SL_CORE_ASSERT(status, "Failed to initialize Glad!");
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }

}