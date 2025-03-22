workspace "Calyx"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	    -- 全局启用 /utf-8 选项（仅对 MSVC 生效）
	filter { "action:vs*" }  -- 匹配所有 Visual Studio 版本
    	buildoptions { "/utf-8" }
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Calyx/vendor/GLFW/include"

include "Calyx/vendor/GLFW"

project "Calyx"
	location "Calyx"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "clxpch.h"
	pchsource "Calyx/src/clxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CLX_PLATFORM_WINDOWS",
			"CLX_BULID_DLL"
		}

		postbuildcommands
		{
			{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}
	
	filter "configurations:Debug"
		defines "CLX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CLX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CLX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Calyx/vendor/spdlog/include",
		"Calyx/src"
	}

	links
	{
		"Calyx"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CLX_PLATFORM_WINDOWS",
		}

	
	filter "configurations:Debug"
		defines "CLX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CLX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CLX_DIST"
		optimize "On"