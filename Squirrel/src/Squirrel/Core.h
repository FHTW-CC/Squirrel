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
