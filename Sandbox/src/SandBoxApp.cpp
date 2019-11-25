
#include "RavenEngine.h"
#include "Raven/Core/EntryPoint.h"
#include "imgui/imgui.h"

class ExempleLayer : public Raven::Layer
{
public: 
	ExempleLayer() : Layer("Exemple")
	{

	}

	void OnEvent(Raven::Event& event) 
	{

	}

	void OnImGUIRender() 
	{
		ImGui::ShowMetricsWindow();
		
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

