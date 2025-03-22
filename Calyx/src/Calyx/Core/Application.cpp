#include "clxpch.h"
#include "Application.h"

#include "Calyx/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Calyx {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() 
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.7f, 0.878f, 0.901f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
}
