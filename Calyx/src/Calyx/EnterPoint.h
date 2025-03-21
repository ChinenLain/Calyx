#pragma once

#ifdef CLX_PLATFORM_WINDOWS

extern Calyx::Application* Calyx::CreateApplication();

int main(int argc, char** argv)
{
	Calyx::Log::Init();
	CLX_CORE_WARN("Initialized Log!");
	int a = 5;
	CLX_INFO("Hell0! Var={0}",a);

	auto app = Calyx::CreateApplication();
	app->Run();
	delete app;
}
#endif
