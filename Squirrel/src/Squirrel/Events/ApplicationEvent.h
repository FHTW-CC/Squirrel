#pragma once

#include "Event.h"

#include <sstream>

namespace Squirrel {

	class SQUIRREL_API WindowResizeEvent : public Event {
	public:

		WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(WindowResize)
			DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int width, height;
	};

	class SQUIRREL_API WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() {}

		DEFINE_EVENT_CLASS_TYPE(WindowClose)
			DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};
	class SQUIRREL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		DEFINE_EVENT_CLASS_TYPE(AppTick)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	class SQUIRREL_API AppUpdateEvent : public Event {

		AppUpdateEvent() {}

		DEFINE_EVENT_CLASS_TYPE(AppUpdate)
			DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SQUIRREL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		DEFINE_EVENT_CLASS_TYPE(AppRender)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}