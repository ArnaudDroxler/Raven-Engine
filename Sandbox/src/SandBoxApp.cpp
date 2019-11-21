
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

