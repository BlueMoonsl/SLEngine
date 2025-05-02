#pragma once

#include "SLEngine/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace SLEngine
{
	class Log
	{
	public:
		static void Init();
		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SL_CORE_TRACE(...)    ::SLEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_INFO(...)     ::SLEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_WARN(...)     ::SLEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_ERROR(...)    ::SLEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_CRITICAL(...) ::SLEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SL_TRACE(...)	    ::SLEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SL_INFO(...)		::SLEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SL_WARN(...)		::SLEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SL_ERROR(...)		::SLEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SL_CRITICAL(...)    ::SLEngine::Log::GetClientLogger()->critical(__VA_ARGS__)


