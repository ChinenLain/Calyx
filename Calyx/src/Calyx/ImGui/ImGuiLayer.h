#pragma once

#include "Calyx/Core/Layer.h"

#include "Calyx/Events/KeyEvent.h"
#include "Calyx/Events/MouseEvent.h"
#include "Calyx/Events/ApplicationEvent.h"

namespace Calyx {

	class CALYX_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		//virtual void OnEvent(Event& e) override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;

	};
}


