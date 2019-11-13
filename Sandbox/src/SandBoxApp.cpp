
#include "RavenEngine.h"
#include "Raven/Core/EntryPoint.h"

class ExempleLayer : public Raven::Layer
{
public: 
	ExempleLayer() : Layer("Exemple")
	{

	}

	void OnEvent(Raven::Event& event) {

		std::cout << event.GetName();
		RAVEN_CLIENT_TRACE("Yolo");
		RAVEN_CLIENT_TRACE(event);
	}


private:

};

class SandboxApp : public Raven::Application
{
public:	
	SandboxApp()
	{
		PushLayer(new ExempleLayer());
	}

	~SandboxApp()
	{

	}

};

Raven::Application* Raven::CreateApplication() 
{
	return new SandboxApp();
}

