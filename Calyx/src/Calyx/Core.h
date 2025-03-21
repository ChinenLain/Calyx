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
