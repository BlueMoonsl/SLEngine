#pragma once

#include "SLEngine/Core/Core.h"

#ifdef SL_PLATFORM_WINDOWS

extern SLEngine::Application* SLEngine::CreateApplication();

int main(int argc, char** argv)
{
	
	SLEngine::Log::Init();
	SL_CORE_WARN("Initialized Log!");

	auto app = SLEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif