#pragma once

#include "GraphicContext.h"
#include "GLFW/glfw3.h" 

namespace Raven
{
	class OpenglContext : public GraphicContext
	{
	public:
		OpenglContext(GLFWwindow* window);
		
		virtual void Init() override;
		virtual void SwapBuffer() override;

	private: 
		GLFWwindow* window;
	};



}