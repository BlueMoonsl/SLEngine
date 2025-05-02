#include "slpch.h"
#include "SLEngine/Core/Window.h"

#ifdef SL_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace SLEngine
{

    Scope<Window> Window::Create(const WindowProps& props)
    {
#ifdef SL_PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(props);
#else
        SL_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif
    }

}