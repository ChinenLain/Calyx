#include <Calyx.h>

#include "imgui/imgui.h"

class ExampleLayer : public Calyx::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}


	void OnUpdate() override
	{
		if (Calyx::Input::IsKeyPressed(CLX_KEY_TAB))
			CLX_TRACE("Tab�������� (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Calyx::Event& event) override
	{
		if (event.GetEventType() == Calyx::EventType::KeyPressed)
		{
			Calyx::KeyPressedEvent& e = (Calyx::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CLX_KEY_TAB)
				CLX_TRACE("Tab�������� (event)!");
			CLX_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Calyx::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

Calyx::Application* Calyx::CreateApplication()
{
	return new Sandbox();
}