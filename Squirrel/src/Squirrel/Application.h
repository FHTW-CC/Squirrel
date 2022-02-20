#pragma once

#include "Core.h"

namespace Squirrel{

	class SQUIRREL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

