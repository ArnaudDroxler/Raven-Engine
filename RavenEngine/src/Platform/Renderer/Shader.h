#pragma once


namespace Raven
{
	class Shader {

	public : 
		Shader(const std::string& vertexShader, const std::string& fragmentShader);
		~Shader();

		void Bind();
		void UnBind();

	private : 

		uint32_t rendererID;
		
	};

}

