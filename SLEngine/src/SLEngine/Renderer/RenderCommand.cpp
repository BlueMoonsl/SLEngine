#include "slpch.h"
#include "SLEngine/Renderer/RenderCommand.h"

namespace SLEngine {

    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}