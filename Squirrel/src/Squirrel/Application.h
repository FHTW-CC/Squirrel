#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Squirrel/Events/ApplicationEvent.h"

#include "Window.h"

namespace Squirrel{

	class SQUIRREL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> window;
		bool running = true;
	};

	Application* CreateApplication();
}

