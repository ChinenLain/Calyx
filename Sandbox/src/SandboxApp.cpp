#include <Calyx.h>

class Sandbox : public Calyx::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Calyx::Application* Calyx::CreateApplication()
{
	return new Sandbox();
}