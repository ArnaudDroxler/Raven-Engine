#include "ravenpch.h"
#include "Debug.h"


namespace Raven
{
	
	std::shared_ptr<spdlog::logger> Debug::CoreLogger;
	std::shared_ptr<spdlog::logger> Debug::ClientLogger;


	//bool Debug::enableCoreLog;
	//bool Debug::enableClientLog;

	void Debug::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		CoreLogger = spdlog::stdout_color_mt("RavenCore");
		CoreLogger->set_level(spdlog::level::trace);

		ClientLogger = spdlog::stdout_color_mt("Application");
		ClientLogger->set_level(spdlog::level::trace);

		//enableCoreLog = true;
		//enableClientLog = true;
	}


	/*void Debug::DisableCoreLogging()
	{
		enableCoreLog = false;
	}

	void Debug::DisableClientLogging()
	{
		enableClientLog = false;
	}

	void Debug::CoreLog(char * str)
	{
		if (enableCoreLog) {
			CoreLogger->trace(str);
		}
	}

	void Debug::CoreInfo(char * str)
	{
		if (enableCoreLog) {
			CoreLogger->info(str);
		}
	}

	void Debug::CoreWarning(char * str)
	{
		if (enableCoreLog) {
			CoreLogger->warn(str);
		}
	}

	void Debug::CoreError(char * str)
	{
		if (enableCoreLog) {
			CoreLogger->error(str);
		}
	}

	void Debug::CoreCritical(char * str)
	{
		if (enableCoreLog) {
			CoreLogger->critical(str);
		}
	}

	void Debug::Log(char * str)
	{
		if (enableClientLog) {
			CoreLogger->trace(str);
		}
	}

	void Debug::Info(char * str)
	{
		if (enableClientLog) {
			CoreLogger->info(str);
		}
	}

	void Debug::Warning(char * str)
	{
		if (enableClientLog) {
			CoreLogger->warn(str);
		}
	}

	void Debug::Error(char * str)
	{
		if(enableClientLog) {
			CoreLogger->error(str);
		}
	}

	void Debug::Critical(char * str)
	{
		if (enableClientLog) {
			CoreLogger->critical(str);
		}
	}*/

}
