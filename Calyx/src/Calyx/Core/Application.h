#pragma once

#include "Core.h"

#include "Window.h"
#include "Calyx/Core/LayerStack.h"
#include "Calyx/Events/Event.h"
#include "Calyx/Events/ApplicationEvent.h"

#include "Calyx/ImGui/ImGuiLayer.h"

#include "Calyx/Renderer/Shader.h"
#include "Calyx/Renderer/Buffer.h"
#include "Calyx/Renderer/VertexArray.h"

#include "Calyx/Renderer/OrthographicCamera.h"

namespace Calyx {

	class CALYX_API Application
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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
