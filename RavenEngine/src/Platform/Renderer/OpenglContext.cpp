#include "ravenpch.h"
#include "OpenglContext.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Raven 
{

	OpenglContext::OpenglContext(GLFWwindow* window) : window(window)
	{

	}
	void OpenglContext::Init()
	{
		glfwMakeContextCurrent(window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		RAVEN_CORE_ASSERT(status, "Could not intialize GLAD!");
	}

	void OpenglContext::SwapBuffer()
	{
		glfwSwapBuffers(window);
	}

}
