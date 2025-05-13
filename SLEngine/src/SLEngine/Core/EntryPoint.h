#pragma once

#include "SLEngine/Core/Base.h"
#include "SLEngine/Core/Application.h"

#ifdef SL_PLATFORM_WINDOWS

extern SLEngine::Application* SLEngine::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	
	SLEngine::Log::Init();

    SL_PROFILE_BEGIN_SESSION("Startup", "SLEngineProfile-Startup.json");
	auto app = SLEngine::CreateApplication({ argc, argv });
    SL_PROFILE_END_SESSION();

    SL_PROFILE_BEGIN_SESSION("Runtime", "SLEngineProfile-Runtime.json");
    app->Run();
    SL_PROFILE_END_SESSION();

    SL_PROFILE_BEGIN_SESSION("Shutdown", "SLEngineProfile-Shutdown.json");
    delete app;
    SL_PROFILE_END_SESSION();
}

#endif
