#pragma once

#ifdef SL_PLATFORM_WINDOWS
#if SL_DYNAMIC_LINK
	#ifdef SL_BUILD_DLL
		#define SLENGINE_API __declspec(dllexport)
	#else
		#define SLENGINE_API __declspec(dllimport)
	#endif
#else
	#define SLENGINE_API
#endif
#else
	#error Hazel only supports Windows!
#endif


#ifdef SL_DEBUG
	#define SL_ENABLE_ASSERTS
#endif

#ifdef SL_ENABLE_ASSERTS
	#define SL_ASSERT(x, ...) { if(!(x)) { SL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SL_CORE_ASSERT(x, ...) { if(!(x)) { SL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SL_ASSERT(x, ...)
	#define SL_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define SL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
