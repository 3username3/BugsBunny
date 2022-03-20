#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace BugsBunny {

	class BB_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
