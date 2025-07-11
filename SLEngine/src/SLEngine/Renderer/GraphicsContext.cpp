#include "slpch.h"
#include "SLEngine/Renderer/GraphicsContext.h"

#include "SLEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace SLEngine {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    SL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        SL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}