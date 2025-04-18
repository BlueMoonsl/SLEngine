#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace SLEngine
{
	class SLENGINE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SL_CORE_TRACE(...)  ::SLEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_INFO(...)   ::SLEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_WARN(...)   ::SLEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_ERROR(...)  ::SLEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_FATAL(...)  ::SLEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define SL_TRACE(...)	    ::SLEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SL_INFO(...)		::SLEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SL_WARN(...)		::SLEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SL_ERROR(...)		::SLEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SL_FATAL(...)		::SLEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)


