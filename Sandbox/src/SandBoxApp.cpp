
#include "RavenEngine.h"


class ExempleLayer : public Raven::Layer
{
public: 
	ExempleLayer() : Layer("Exemple")
	{

	}

	void OnEvent(Raven::Event& event) {

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

