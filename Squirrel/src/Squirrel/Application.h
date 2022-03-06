#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Squirrel{

	class SQUIRREL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> window;
		bool running = true;
	};

	Application* CreateApplication();
}

