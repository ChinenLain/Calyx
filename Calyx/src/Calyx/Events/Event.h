#pragma once

#include "clxpch.h"

#include "Calyx/Core/Core.h"

namespace Calyx {

	//ENUM----------------------------------------------------------------------------
	enum class EventType {								//事件类型
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved
	};

	enum EventCategory {								//事件类别
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	//宏定义（文本替换）自动化以下的重写操作---------------------------------------------------
#define EVENT_CLASS_TYPE(type) \
			static EventType GetStaticType(){ return EventType::type; }\
			virtual EventType GetEventType() const override { return GetStaticType(); }\
			virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)\
			virtual int GetCategoryFlags() const override { return category; }

	//CLASS--------------------------------------------------------------------------------
	class Event
	{
		friend class EventDispatcher;										
	public:
		virtual ~Event() = default;

		bool Handled = false;												

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }			

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;														
		}
	};


	class EventDispatcher
	{
	private:
		Event& m_Event;

		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}
		template<typename T>										
		bool Dispatch(EventFn<T> func) {							
			if (m_Event.GetEventType() == T::GetStaticType())		
			{
				m_Event.Handled = func( static_cast<T&>(m_Event) );	
				return true;												
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& ev)
	{
		return os << ev.ToString();
	}
}