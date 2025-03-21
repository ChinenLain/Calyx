#pragma once

#ifdef CLX_PLATFORM_WINDOWS

extern Calyx::Application* Calyx::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Calyx::CreateApplication();
	app->Run();
	delete app;
}
#endif
