#pragma once

#include "Core.h"

#include "Window.h"
#include "Raven/Events/Event.h"
#include "Raven/Events/ApplicationEvent.h"

namespace Raven 
{

	class RAVEN_API Application
	{

	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		
		void Run();


	private: 

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> window;

		bool running;
		bool minimized;
	};

	Application* CreateApplication();

}
