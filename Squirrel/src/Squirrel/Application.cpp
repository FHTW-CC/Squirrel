#include "sqpch.h"
#include "Application.h"
#include "Log.h"
#include <glad/glad.h>



namespace Squirrel {

	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(std::bind(&Application::OnEvent,this,std::placeholders::_1));
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

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClosed, this, std::placeholders::_1));
		SQ_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		running = false;
		return false;
	}

}
