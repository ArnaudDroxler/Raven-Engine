#pragma once

#include "Core.h"

namespace Raven 
{

	class RAVEN_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
