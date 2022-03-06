#pragma once
#include "Event.h"

namespace Squirrel {

	class SQUIRREL_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const {
			return keyCode;
		}

		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : keyCode(keycode) {}

		int keyCode;
	};

	class SQUIRREL_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keyCode), repeatCount(repeatCount) {}

		inline int GetRepeatCount() { return repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(KeyPressed)

	private:
		int repeatCount;
	};

	class SQUIRREL_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(KeyReleased)
	};
}