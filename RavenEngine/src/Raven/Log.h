#pragma once

#include "ravenpch.h"

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Raven 
{

	class RAVEN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }


	private: 
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};

}

#define RAVEN_CORE_TRACE(...)	::Raven::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RAVEN_CORE_INFO(...)	::Raven::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RAVEN_CORE_WARN(...)	::Raven::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RAVEN_CORE_ERROR(...)	::Raven::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RAVEN_CORE_CRITICAL(...)::Raven::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define RAVEN_CLIENT_TRACE(...) ::Raven::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RAVEN_CLIENT_INFO(...) ::Raven::Log::GetClientLogger()->info(__VA_ARGS__)
#define RAVEN_CLIENT_WARN(...) ::Raven::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RAVEN_CLIENT_ERROR(...) ::Raven::Log::GetClientLogger()->error(__VA_ARGS__)
#define RAVEN_CLIENT_CRITICAL(...) ::Raven::Log::GetClientLogger()->critical(__VA_ARGS__)