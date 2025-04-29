#include "slpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace SLEngine {

    Shader* Shader::Create(const std::string& filepath)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    SL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLShader(filepath);
        }

        SL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    SL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLShader(vertexSrc, fragmentSrc);
        }

        SL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}