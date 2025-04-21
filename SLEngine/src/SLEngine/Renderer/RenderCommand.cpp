#include "slpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace SLEngine {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}