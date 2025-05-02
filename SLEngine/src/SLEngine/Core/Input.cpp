#include "slpch.h"
#include "SLEngine/Core/Input.h"

#ifdef SL_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace SLEngine {

    Scope<Input> Input::s_Instance = Input::Create();

    Scope<Input> Input::Create()
    {
#ifdef SL_PLATFORM_WINDOWS
        return CreateScope<WindowsInput>();
#else
        SL_CORE_ASSERT(false, "Unknown platform!");
        return nullptr; 3Has comments.Original line has comments.
#endif
    }
}