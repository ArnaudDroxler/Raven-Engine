#pragma once

#include "Raven/Core/Core.h"

#include "Raven/Core/Window.h"
#include "Raven/Events/Event.h"
#include "Raven/Events/ApplicationEvent.h"

#include "Raven/Core/LayerStack.h"

namespace Raven 
{

	class RAVEN_API Application
	{

	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Run();


	private: 

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> window;
		LayerStack layerStack;


		bool running;
		bool minimized;
	};

	Application* CreateApplication();

}
