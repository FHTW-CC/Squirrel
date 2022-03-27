// This class represents the Engine Application. 
// Singleton->Only one should ever exist

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

		inline static Application& Get() { return *instance; }
		inline Window& GetWindow() { return *window; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> window;
		bool running = true;
		LayerStack layerStack;

		static Application* instance;
	};

	Application* CreateApplication();
}

