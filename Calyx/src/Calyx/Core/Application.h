#pragma once

#include "Core.h"

#include "Window.h"
#include "Calyx/Core/LayerStack.h"
#include "Calyx/Events/Event.h"
#include "Calyx/Events/ApplicationEvent.h"


namespace Calyx {

	class CALYX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}
