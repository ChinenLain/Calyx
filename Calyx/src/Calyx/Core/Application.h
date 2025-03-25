#pragma once

#include "Core.h"

#include "Window.h"
#include "Calyx/Core/LayerStack.h"
#include "Calyx/Events/Event.h"
#include "Calyx/Events/ApplicationEvent.h"

#include "Calyx/Core/Timestep.h"

#include "Calyx/ImGui/ImGuiLayer.h"

namespace Calyx {

	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
