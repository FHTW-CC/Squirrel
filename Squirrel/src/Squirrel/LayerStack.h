#pragma once

#include "Squirrel/Core.h"
#include "Layer.h"

namespace Squirrel
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		//insert before overlays
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		//insert at the very end
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }

	private:
		std::vector<Layer*> layers;
		//represents the point where layers are inserted i.e. before the overlays
		std::vector<Layer*>::iterator layerInsert;
	};

}
