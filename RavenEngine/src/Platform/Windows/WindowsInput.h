#pragma once

#include "Raven/Core/Input.h"

namespace Raven
{

	class WindowsInput : public Input
	{
	protected:

		virtual bool GetKeyDownImpl(int keycode) override;
		virtual bool GetMouseButtonImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMousePosXImpl() override;
		virtual float GetMousePosYImpl() override;
	};

}
