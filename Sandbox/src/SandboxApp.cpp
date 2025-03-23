#include <Calyx.h>

class ExampleLayer : public Calyx::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}


	void OnUpdate() override
	{
		CLX_INFO("ExampleLayer::Update");
	}

	void OnEvent(Calyx::Event& event) override
	{
		CLX_TRACE("{0}", event.ToString());
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