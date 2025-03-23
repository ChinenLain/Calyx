#pragma once
#ifdef CLX_PLATFORM_WINDOWS
	#ifdef CLX_BULID_DLL
		#define CALYX_API _declspec(dllexport)
	#else
		#define CALYX_API _declspec(dllimport)
	#endif
#else
	#error Calyx only support Windows!
#endif

#ifdef CLX_ENABLE_ASSERTS
	//���ԣ����x��ʾ������������У�{0}ռλ��"__VA_ARGS__"����"..."���������䣩
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
