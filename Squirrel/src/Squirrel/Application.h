#pragma once

#include "Core.h"
#include "Window.h"
#include "Squirrel/LayerStack.h"
#include "Events/Event.h"
#include "Squirrel/Events/ApplicationEvent.h"


namespace Squirrel{

	class SQUIRREL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> window;
		bool running = true;
		LayerStack layerStack;
	};

	Application* CreateApplication();
}

