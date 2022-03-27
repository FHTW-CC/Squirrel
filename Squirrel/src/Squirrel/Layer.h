// Base class to use for application layers

#pragma once
#include "Squirrel/Core.h"
#include "Squirrel/Events/Event.h"
namespace Squirrel {

	class SQUIRREL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach(){}
		virtual void OnDetach(){}
		virtual void OnUpdate(){}
		virtual void OnEvent(Event& e){}

		inline const std::string GetName() const { return debugName; }
	private:
		std::string debugName;
	};
}

