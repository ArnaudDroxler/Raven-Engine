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

		imGuiLayer = new ImGuiLayer();
		PushOverlay(imGuiLayer);


		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		unsigned int indices[3] = { 0, 1, 2 };

		glGenVertexArrays(1, &m_VertexArray);
		glGenBuffers(1, &m_VertexBuffer);
		glGenBuffers(1, &m_IndexBuffer);

		glBindVertexArray(m_VertexArray);
		
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";

		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));

	}


	Application::~Application()
	{

	}

	void Application::OnEvent(Event & e)
	{

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Application::OnWindowResize, this, std::placeholders::_1));

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
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader.get()->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			imGuiLayer->Begin();
			for (Layer* layer : layerStack)
				layer->OnImGUIRender();
			imGuiLayer->End();

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

