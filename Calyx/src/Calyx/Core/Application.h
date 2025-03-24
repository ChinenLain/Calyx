#pragma once

#include "Core.h"

#include "Window.h"
#include "Calyx/Core/LayerStack.h"
#include "Calyx/Events/Event.h"
#include "Calyx/Events/ApplicationEvent.h"

#include "Calyx/ImGui/ImGuiLayer.h"

#include "Calyx/Renderer/Shader.h"
#include "Calyx/Renderer/Buffer.h"

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

		unsigned int m_VertexArray;

		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
