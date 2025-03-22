#pragma once

#ifdef CLX_PLATFORM_WINDOWS

extern Calyx::Application* Calyx::CreateApplication();

int main(int argc, char** argv)
{
	Calyx::Log::Init();
	CLX_CORE_WARN("Initialized Log!");

	auto app = Calyx::CreateApplication();
	app->Run();
	delete app;
}
#endif
