#pragma once


#ifdef RAVEN_PLATFORM_WINDOWS
	#define RAVEN_EXPORT __declspec(dllexport)
	#define RAVEN_IMPORT __declspec(dllimport)
#endif