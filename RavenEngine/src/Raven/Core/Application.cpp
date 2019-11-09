#include "ravenpch.h"
#include "Application.h"
#include "Debug.h"
#include "Raven/Events/ApplicationEvent.h"
#include "Raven/Events/Event.h"

#include <GLFW/glfw3.h>


namespace Raven 
{

	Application::Application()
	{
		Raven::Debug::Init();

		RAVEN_CORE_INFO("Raven Engine Init");

		//WindowProperty windowProperty("Toto", 450, 650);

		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

	}


	Application::~Application()
	{

	}

	void Application::OnEvent(Event & e)
	{

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Application::OnWindowResize, this, std::placeholders::_1));

		RAVEN_CORE_INFO(e);

	}

	void Application::Run()
	{

		while (running)
		{

			window->OnUpdate();

		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			minimized = true;
			return false;
		}

		minimized = false;

		return false;
	}

}

