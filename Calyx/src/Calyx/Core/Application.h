#pragma once

#include "Core.h"
#include "Calyx/Events/Event.h"
#include "Calyx/Events/ApplicationEvent.h"

#include "Window.h"

namespace Calyx {

	class CALYX_API Application
	{
	public:
		Application();
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
