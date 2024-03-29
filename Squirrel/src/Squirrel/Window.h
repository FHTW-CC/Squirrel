// �bstract base class for application windows
#pragma once
#include "sqpch.h"
#include "Squirrel/Core.h"
#include "Events/Event.h"

namespace Squirrel {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Squirrel Engine", unsigned int width = 1280, unsigned int height = 720) 
			: Title(title),Width(width),Height(height){}

	};

	class SQUIRREL_API Window {
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window(){}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}