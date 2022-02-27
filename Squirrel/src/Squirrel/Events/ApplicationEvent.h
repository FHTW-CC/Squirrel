#pragma once

#include "Event.h"

#include <sstream>

namespace Squirrel {

	class WindowResizeEvent : public Event
	{
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


}