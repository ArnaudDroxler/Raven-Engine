#include "ravenpch.h"
#include "WindowsWindow.h"

#include "Raven/Events/Event.h"
#include "Raven/Events/KeyEvent.h"
#include "Raven/Events/MouseEvent.h"
#include "Raven/Events/ApplicationEvent.h"



namespace Raven
{


	static unsigned int GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description)
	{
		RAVEN_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProperty& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperty& props)
	{
		Init(props);


	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();


		glClearColor(1.0, 0.0, 1.0, 1.0);

		glfwSwapBuffers(window);


	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
			
		windowData.VSync = enabled;
	}

	void WindowsWindow::Init(const WindowProperty& props)
	{
		windowData.Title = props.Title;
		windowData.Height = props.Height;
		windowData.Width = props.Width;

		RAVEN_CORE_INFO("Creating window {0} ({1},{2})" ,windowData.Title ,windowData.Width, windowData.Height);

		if (GLFWWindowCount == 0)
		{
			RAVEN_CORE_INFO("Initializing GLFW");
			int success = glfwInit();
			RAVEN_CORE_ASSERT(success, "Could not intialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		window = glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str(), nullptr, nullptr);

		GLFWWindowCount++;

		glfwMakeContextCurrent(window);

		glfwSetWindowUserPointer(window, &windowData);

		SetVSync(true);

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}


		});

		glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(keycode);
			data.eventCallback(event);
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.eventCallback(event);
		});

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);

		if (--GLFWWindowCount == 0)
		{
			RAVEN_CORE_INFO("Terminating GLFW");
			glfwTerminate();
		}
	}

}