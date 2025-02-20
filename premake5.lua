workspace "Flapi_Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
	}
	startproject "Flapi_Engine"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["ImGui"] = "vendor/imgui/include"

include "vendor/GLFW"
include "vendor/Glad"
include "vendor/imgui"

project "Flapi_Engine"
	location "Flapi_Engine"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{ "%{prj.name}/src/**.h" , "%{prj.name}/src/**.cpp"}

	includedirs
	{
		"%{prj.name}/src",
		"vendor/",
		"vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
        "ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

		filter "configurations:Debug"
			defines "FL_DEBUG"
			buildoptions "/MTd"
			symbols "On"

		filter "configurations:Release"
			defines "FL_RELEASE"
			buildoptions "/MT"
			optimize "On"			