#pragma once

#include "Raven/Core/Core.h"
#include "Raven/Events/Event.h"

namespace Raven
{

	class RAVEN_API Layer
	{
	public:
		Layer(const std::string& debugName);
		virtual ~Layer() = default;


		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event&  event) {};
		virtual void OnImGUIRender() {};

		inline const std::string& GetName() const { return debugName; }

	private: 
		std::string debugName = "";
	};


}
