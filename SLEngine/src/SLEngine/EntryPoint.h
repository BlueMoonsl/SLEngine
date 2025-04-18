#pragma once

#ifdef SL_PLATFORM_WINDOWS

extern SLEngine::Application* SLEngine::CreateApplication();

int main(int argc, char** argv)
{
	
	SLEngine::Log::Init();
	SL_CORE_WARN("Initialized Log!");
	int a = 5;
	SL_INFO("Hello! Var={0}", a);

	auto app = SLEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif