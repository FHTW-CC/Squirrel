#pragma once

#include "sqpch.h"
#include "Squirrel/Core.h"


namespace Squirrel {


	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication =	BIT_FIELD(0),
		EventCategoryInput =		BIT_FIELD(1),
		EventCategoryKeyboard =		BIT_FIELD(2),
		EventCategoryMouse =		BIT_FIELD(3),
		EventCategoryMouseButton =	BIT_FIELD(4)
	};

#define DEFINE_EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define DEFINE_EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class SQUIRREL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	protected:
		bool isProcessed = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFunction = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& ev) : event(ev) {}

		template<typename T>
		bool Dispatch(EventFunction<T> function) {
			if (event.GetEventType() == T::GetStaticType()) {
				event.isProcessed = function(*(T*)&event);
				return true;
			}
			return false;
		}


	private:
		Event& event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}