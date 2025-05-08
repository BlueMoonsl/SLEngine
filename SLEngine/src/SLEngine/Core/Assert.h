#pragma once

#include "SLEngine/Core/Base.h"
#include "SLEngine/Core/Log.h"
#include <filesystem>

#ifdef SL_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define SL_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { SL##type##ERROR(msg, __VA_ARGS__); SL_DEBUGBREAK(); } }
	#define SL_INTERNAL_ASSERT_WITH_MSG(type, check, ...) SL_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define SL_INTERNAL_ASSERT_NO_MSG(type, check) SL_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", SL_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)
		
	#define SL_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define SL_INTERNAL_ASSERT_GET_MACRO(...) SL_EXPAND_MACRO( SL_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, SL_INTERNAL_ASSERT_WITH_MSG, SL_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define SL_ASSERT(...) SL_EXPAND_MACRO( SL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define SL_CORE_ASSERT(...) SL_EXPAND_MACRO( SL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else	
	#define SL_ASSERT(...)
	#define SL_CORE_ASSERT(...)
#endif
