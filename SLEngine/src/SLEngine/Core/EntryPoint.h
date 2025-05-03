#pragma once

#include "SLEngine/Core/Base.h"

#ifdef SL_PLATFORM_WINDOWS

extern SLEngine::Application* SLEngine::CreateApplication();

int main(int argc, char** argv)
{
	
	SLEngine::Log::Init();

    SL_PROFILE_BEGIN_SESSION("Startup", "SLEngineProfile-Startup.json");
    auto app = SLEngine::CreateApplication();
    SL_PROFILE_END_SESSION();

    SL_PROFILE_BEGIN_SESSION("Runtime", "SLEngineProfile-Runtime.json");
    app->Run();
    SL_PROFILE_END_SESSION();

    SL_PROFILE_BEGIN_SESSION("Startup", "SLEngineProfile-Shutdown.json");
    delete app;
    SL_PROFILE_END_SESSION();
}

#endif