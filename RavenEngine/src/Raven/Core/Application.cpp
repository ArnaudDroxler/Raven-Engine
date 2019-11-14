#include "ravenpch.h"
#include "Application.h"
#include "Debug.h"
#include "Raven/Events/ApplicationEvent.h"
#include "Raven/Events/Event.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Raven 
{

	Application* Application::Instance = nullptr;

	Application::Application()
	{
		Raven::Debug::Init();

		RAVEN_CORE_ASSERT(!Instance, "Application already exists!");
		Instance = this;

		RAVEN_CORE_INFO("Raven Engine Init");

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

		for (auto it = layerStack.end(); it != layerStack.begin(); )
		{
			--it;
			(*it)->OnEvent(e);
			if (e.Handled)
				break;
		}

	}

	void Application::PushLayer(Layer * layer)
	{
		layerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer * layer)
	{
		layerStack.PushOverlay(layer);
	}

	void Application::Run()
	{

		while (running)
		{
			for (Layer* layer : layerStack)
				layer->OnUpdate();

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

