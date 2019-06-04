#include <RavenEngine.h>

class SandboxApp : public Raven::Application
{
public:	
	SandboxApp()
	{

	}

	~SandboxApp()
	{

	}

};

Raven::Application* Raven::CreateApplication() 
{
	return new SandboxApp();
}

