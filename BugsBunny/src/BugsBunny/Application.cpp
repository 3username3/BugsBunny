#include "bbpch.h"
#include "Application.h"

#include "BugsBunny/Events/ApplicationEvent.h"
#include "Log.h"

namespace BugsBunny {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run(){

		WindowResizeEvent e(1280, 720);
		

		if (e.IsInCategory(EventCategoryApplication)) {
			BB_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {
			BB_TRACE(e);
		}

		while (true); 

	}
}
