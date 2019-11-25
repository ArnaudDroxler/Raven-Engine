#pragma once

#include "ravenpch.h"

#include "Event.h"

namespace Raven
{
	class  WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResize: " << width << ", " << height;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowResize; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char * GetName() const override { return "WindowResize"; }

		int GetCategoryFlags() const override { return EventCategoryApplication; }
	private:
		unsigned int width, height;
	};

	class  WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		static EventType GetStaticType() { return EventType::WindowClose; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char * GetName() const override { return "WindowClose"; }

		int GetCategoryFlags() const override { return EventCategoryApplication; }
	};

	class  AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		static EventType GetStaticType() { return EventType::AppTick; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char * GetName() const override { return "AppTick"; }

		int GetCategoryFlags() const override { return EventCategoryApplication; }
	};

	class  AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}
		static EventType GetStaticType() { return EventType::AppUpdate; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char * GetName() const override { return "AppUpdate"; }

		int GetCategoryFlags() const override { return EventCategoryApplication; }
	};

	class  AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		static EventType GetStaticType() { return EventType::AppRender; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char * GetName() const override { return "AppRender"; }

		int GetCategoryFlags() const override { return EventCategoryApplication; }
	};
}
