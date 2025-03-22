#pragma once

#include "Core.h"
#include "Calyx/Events/Event.h"
#include "Window.h"

namespace Calyx {

	class CALYX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}
