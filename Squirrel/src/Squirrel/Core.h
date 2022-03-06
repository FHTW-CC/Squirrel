#pragma once

#ifdef SQ_PLATFORM_WINDOWS
	#ifdef SQ_BUILD_DLL
		#define SQUIRREL_API _declspec(dllexport)
	#else
		#define SQUIRREL_API _declspec(dllimport)
	#endif // SQ_BUILD_DLL
#else
	#error Only Windows support!

#endif // SQ_PLATFORM_WINDOWS

#ifdef HZ_ENABLE_ASSERTS
	#define SQ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SQ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SQ_ASSERT(x, ...)
	#define SQ_CORE_ASSERT(x, ...)
#endif

//Represents a Bit Position
#define BIT_FIELD(x) (1<<x)