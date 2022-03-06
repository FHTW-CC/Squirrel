#include "sqpch.h"
#include "Application.h"
#include "Events/MouseEvent.h"
#include "Log.h"

namespace Squirrel {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {

		MouseMovedEvent e(10, 15);
		if (e.IsInCategory(EventCategoryMouse))
		{
			SQ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SQ_WARN(e);
		}
		
		while (true) {

		}
	}

}
