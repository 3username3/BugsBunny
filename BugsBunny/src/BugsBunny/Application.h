#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "BugsBunny/Events/ApplicationEvent.h"

namespace BugsBunny {

	//If we want to use the Application class in Sandbox, we need to export 
	//it from the Hazel dll. This is done with _declspec(dllexport) as defined 
	//in the BB_API macro.
	class BB_API Application
	{
	public:
		Application();
		//We need to make the destructor virtual, because this class is inherited by Sandbox.
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	Application* CreateApplication();
}
