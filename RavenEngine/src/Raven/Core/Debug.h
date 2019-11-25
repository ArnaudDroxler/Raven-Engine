#pragma once

#include "ravenpch.h"

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Raven 
{

	class  Debug
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

		/*static void DisableCoreLogging();
		static void DisableClientLogging();

		static void CoreLog(char* str);
		static void CoreInfo(char* str);
		static void CoreWarning(char* str);
		static void CoreError(char* str);
		static void CoreCritical(char* str);

		static void Log(char* str);
		static void Info(char* str);
		static void Warning(char* str);
		static void Error(char* str);
		static void Critical(char* str);*/

	private: 
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;

		//static bool enableCoreLog;
		//static bool enableClientLog;

	};

}

#define RAVEN_CORE_TRACE(...)	::Raven::Debug::GetCoreLogger()->trace(__VA_ARGS__)
#define RAVEN_CORE_INFO(...)	::Raven::Debug::GetCoreLogger()->info(__VA_ARGS__)
#define RAVEN_CORE_WARN(...)	::Raven::Debug::GetCoreLogger()->warn(__VA_ARGS__)
#define RAVEN_CORE_ERROR(...)	::Raven::Debug::GetCoreLogger()->error(__VA_ARGS__)
#define RAVEN_CORE_CRITICAL(...)::Raven::Debug::GetCoreLogger()->critical(__VA_ARGS__)

#define RAVEN_CLIENT_TRACE(...) ::Raven::Debug::GetClientLogger()->trace(__VA_ARGS__)
#define RAVEN_CLIENT_INFO(...) ::Raven::Debug::GetClientLogger()->info(__VA_ARGS__)
#define RAVEN_CLIENT_WARN(...) ::Raven::Debug::GetClientLogger()->warn(__VA_ARGS__)
#define RAVEN_CLIENT_ERROR(...) ::Raven::Debug::GetClientLogger()->error(__VA_ARGS__)
#define RAVEN_CLIENT_CRITICAL(...) ::Raven::Debug::GetClientLogger()->critical(__VA_ARGS__)

#define RAVEN_CORE_ASSERT(x, ...) { if(!(x)) { RAVEN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }