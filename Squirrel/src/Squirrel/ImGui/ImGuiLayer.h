#pragma once
#include "Squirrel/Layer.h"

namespace Squirrel
{
	class SQUIRREL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		float time = 0.0f;
	};
}

