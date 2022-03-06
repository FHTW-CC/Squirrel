#include "sqpch.h"
#include "Application.h"
#include "Log.h"
#include <GLFW/glfw3.h>



namespace Squirrel {

	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run() {

		while (running) {
			glClearColor(1, 0.5f, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			window->OnUpdate();
		}
	}

}
