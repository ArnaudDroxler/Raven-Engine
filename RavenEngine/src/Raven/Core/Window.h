#pragma once

#include "ravenpch.h"
#include "Core.h"
#include "Raven/Events/Event.h"

namespace Raven
{

	struct WindowProperty
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperty(const std::string& title = "Hazel Engine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height)
		{
		}

	};

	class RAVEN_API Window
	{
	public:

		virtual ~Window() = default;

		using EventCallback = std::function<void(Event&)>;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual std::string GetName() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		virtual void SetEventCallback(const EventCallback& callback) = 0;

		static Window* Create(const WindowProperty& props = WindowProperty());
	};
}
