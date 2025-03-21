#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Calyx {
	class CALYX_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define CLX_CORE_TRACE(...)    ::Calyx::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CLX_CORE_INFO(...)     ::Calyx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CLX_CORE_WARN(...)     ::Calyx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CLX_CORE_ERROR(...)    ::Calyx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CLX_CORE_FATAL(...)    ::Calyx::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CLX_TRACE(...)  ::Calyx::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLX_INFO(...)   ::Calyx::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLX_WARN(...)   ::Calyx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLX_ERROR(...)  ::Calyx::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLX_FATAL(...)  ::Calyx::Log::GetClientLogger()->fatal(__VA_ARGS__)