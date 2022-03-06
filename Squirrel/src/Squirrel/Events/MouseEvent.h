#pragma once


#include "Event.h"

#include <sstream>

namespace Squirrel {

	class SQUIRREL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : mouseX(x), mouseY(y) {}

		inline float GetX() const { return mouseX; }
		inline float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseMoved)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float mouseX, mouseY;
	};

	class SQUIRREL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) {}

		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseScrolled)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float xOffset, yOffset;
	};

	class SQUIRREL_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return button; }

		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : button(button) {}

		int button;
	};

	class SQUIRREL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class SQUIRREL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}