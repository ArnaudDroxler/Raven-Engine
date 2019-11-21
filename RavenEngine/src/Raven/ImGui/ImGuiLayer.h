#pragma once
#include "Raven/Core/Layer.h"
#include "Raven/Events/Event.h"
#include "Raven/Events/ApplicationEvent.h"
#include "Raven/Events/KeyEvent.h"
#include "Raven/Events/MouseEvent.h"

namespace Raven
{
	class RAVEN_API ImGuiLayer : public Layer
	{

	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnImGUIRender() override;

		void Begin();
		void End();

	};


}
