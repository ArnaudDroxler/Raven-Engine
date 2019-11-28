#pragma once

#include "Raven/Core/Core.h"
#include "Raven/Core/Window.h"
#include "Platform/Renderer/GraphicContext.h"

#include <GLFW/glfw3.h>

namespace Raven 
{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperty& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		inline unsigned int GetWidth() const override { return windowData.Width; };
		inline unsigned int GetHeight() const override { return windowData.Height; };
		inline std::string GetName() const override { return windowData.Title; };

		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return windowData.VSync; };

		inline void  SetEventCallback(const EventCallback& callback) { windowData.eventCallback = callback;  };

		inline virtual void* GetNativeWindow() const { return window; }

	private:

		void Init(const WindowProperty& property);
		void Shutdown();

		GLFWwindow* window;
		GraphicContext* context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallback eventCallback;
		};

		WindowData windowData;



	};


}

