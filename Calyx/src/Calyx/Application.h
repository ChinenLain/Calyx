#pragma once

#include "Core.h"

namespace Calyx {

	class CALYX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
