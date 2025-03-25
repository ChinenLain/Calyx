#pragma once

#include<memory>

#ifdef CLX_PLATFORM_WINDOWS
#if CLX_DYNAMIC_LINK
	#ifdef CLX_BULID_DLL
		#define CALYX_API _declspec(dllexport)
	#else
		#define CALYX_API _declspec(dllimport)
	#endif
#else
#define CALYX_API
#endif
#else
	#error Calyx only support Windows!
#endif


#ifdef CLX_DEBUG
#define CLX_ENABLE_ASSERTS
#endif

#ifdef CLX_ENABLE_ASSERTS
	//断言（如果x表示错误则语句运行，{0}占位的"__VA_ARGS__"代表"..."所输入的语句）
	#define CLX_CORE_ASSERT(x, ...) \
			{if(!x){\
				CLX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
				__debugbreak();}\
			}
	#define CLX_ASSERT(x, ...)\
			{if(!x){\
				CLX_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
				__debugbreak();}\
			}
#else
	#define CLX_CORE_ASSERT(x, ...)
	#define CLX_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define CLX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Calyx {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}