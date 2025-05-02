#include "slpch.h"
#include "SLEngine/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace SLEngine {

    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

    Scope<RendererAPI> RendererAPI::Create()
    {
        switch (s_API)
        {
        case RendererAPI::API::None:    SL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
        }

        SL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}