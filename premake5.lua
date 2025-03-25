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
IncludeDir["Glad"] = "Calyx/vendor/Glad/include"
IncludeDir["ImGui"] = "Calyx/vendor/imgui"
IncludeDir["glm"] = "Calyx/vendor/glm"
IncludeDir["stb_image"] = "Calyx/vendor/stb_image"

include "Calyx/vendor/GLFW"
include "Calyx/vendor/Glad"
include "Calyx/vendor/imgui"

project "Calyx"
	location "Calyx"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "clxpch.h"
	pchsource "Calyx/src/clxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
 		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
 		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
 	{
 		"_CRT_SECURE_NO_WARNINGS"
 	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CLX_PLATFORM_WINDOWS",
			"CLX_BULID_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}
	
	filter "configurations:Debug"
		defines "CLX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CLX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CLX_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Calyx/src",
		"Calyx/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Calyx"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CLX_PLATFORM_WINDOWS",
		}

	
	filter "configurations:Debug"
		defines "CLX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CLX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CLX_DIST"
		runtime "Release"
		optimize "on"