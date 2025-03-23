#pragma once

#include "Calyx/Core/Layer.h"

namespace Calyx {

	class CALYX_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:

	private:
		float m_Time = 0.0f;

	};
}


