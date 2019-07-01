#include "ravenpch.h"
#include "Application.h"
#include "Log.h"

namespace Raven 
{

	Application::Application()
	{

	}


	Application::~Application()
	{

	}

	void Application::Run()
	{

		Raven::Log::Init();

		RAVEN_CORE_TRACE("Raven Engine Init");
		RAVEN_CORE_INFO("Raven Engine Init");
		RAVEN_CORE_WARN("Raven Engine Init");
		RAVEN_CORE_CRITICAL("Raven Engine Init");
		RAVEN_CORE_ERROR("Raven Engine Init");

		RAVEN_CLIENT_TRACE("Raven Engine Init");
		RAVEN_CLIENT_INFO("Raven Engine Init");
		RAVEN_CLIENT_WARN("Raven Engine Init");
		RAVEN_CLIENT_CRITICAL("Raven Engine Init");
		RAVEN_CLIENT_ERROR("Raven Engine Init");



		while (true)
		{

		}
	}

}

