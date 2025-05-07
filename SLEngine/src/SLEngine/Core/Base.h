#pragma once

#include <memory>

#include "SLEngine/Core/PlatformDetection.h"

#ifdef SL_DEBUG
	#if defined(SL_PLATFORM_WINDOWS)
		#define SL_DEBUGBREAK() __debugbreak()
	#elif defined(SL_PLATFORM_LINUX)
		#include <signal.h>
		#define SL_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define SL_ENABLE_ASSERTS
#else
	#define SL_DEBUGBREAK()
#endif

// TODO: Make this macro able to take in no arguments except condition
#ifdef SL_ENABLE_ASSERTS
	#define SL_ASSERT(x, ...) { if(!(x)) { SL_ERROR("Assertion Failed: {0}", __VA_ARGS__); SL_DEBUGBREAK(); } }
	#define SL_CORE_ASSERT(x, ...) { if(!(x)) { SL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); SL_DEBUGBREAK(); } }
#else
	#define SL_ASSERT(x, ...)
	#define SL_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define SL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace SLEngine {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
