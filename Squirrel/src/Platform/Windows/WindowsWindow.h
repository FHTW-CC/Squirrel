// Implementation for window on the windows platform
#pragma once
#include "Squirrel/Window.h"

#include <GLFW/glfw3.h>

namespace Squirrel {

	class  WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;
		inline unsigned int GetWidth() const override { return data.Width; }
		inline unsigned int GetHeight() const override { return data.Height; }

		virtual void SetEventCallback(const EventCallbackFunction& callback) override { data.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* window;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFunction EventCallback;
		};

		WindowData data;
	};
}

