
#include "RavenEngine.h"
#include "Raven/Core/EntryPoint.h"

class ExempleLayer : public Raven::Layer
{
public: 
	ExempleLayer() : Layer("Exemple")
	{

	}

	void OnEvent(Raven::Event& event) 
	{

	}

	void OnUpdate() 
	{
		RAVEN_CLIENT_INFO(Raven::Input::GetMousePosX());
	}

private:

};

class SandboxApp : public Raven::Application
{
public:	
	SandboxApp()
	{
		PushLayer(new ExempleLayer());
		PushOverlay(new Raven::ImGuiLayer());
	}

	~SandboxApp()
	{

	}



};

Raven::Application* Raven::CreateApplication() 
{
	return new SandboxApp();
}

