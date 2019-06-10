#pragma once


#ifdef RAVEN_PLATFORM_WINDOWS
		#ifdef RAVEN_BUILD_DLL
			#define RAVEN_API __declspec(dllexport)
		#else
			#define RAVEN_API __declspec(dllimport)
		#endif
#else
	#error Hazel only supports Windows!
#endif