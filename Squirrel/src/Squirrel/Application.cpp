#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Squirrel {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {

		WindowResizeEvent e(800, 600);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SQ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SQ_TRACE(e);
		}
		
		while (true) {

		}
	}

}
