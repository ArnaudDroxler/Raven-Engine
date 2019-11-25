#pragma once

#include "Raven/Core/Core.h"

#include "Raven/Core/Window.h"
#include "Raven/Events/Event.h"
#include "Raven/Events/ApplicationEvent.h"
#include "Raven/ImGui/ImGuiLayer.h"

#include "Raven/Core/LayerStack.h"

namespace Raven 
{

	class  Application
	{

	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Run();

		inline Window& GetWindow() { return *window; }

		inline static Application& Get() { return *Instance; }

	private: 

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> window;
		LayerStack layerStack;
		ImGuiLayer* imGuiLayer;

		static Application* Instance;

		bool running;
		bool minimized;
	};

	Application* CreateApplication();

}
