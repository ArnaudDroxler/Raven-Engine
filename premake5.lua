workspace "RavenEngine"
	architecture "x64"
	startproject "Sandbox"
    configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}"

IncludeDir = {}
IncludeDir["GLFW"] = "RavenEngine/vendor/GLFW/include"
IncludeDir["GLAD"] = "RavenEngine/vendor/GLAD/include"
IncludeDir["ImGui"] = "RavenEngine/vendor/imgui"
IncludeDir["glm"] = "RavenEngine/vendor/glm"

group "Dependencies"
	include "RavenEngine/vendor/GLFW"
	include "RavenEngine/vendor/GLAD"
	include "RavenEngine/vendor/imgui"

group ""

project "RavenEngine"
	location "RavenEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "ravenpch.h"
	pchsource "RavenEngine/src/ravenpch.cpp"

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

		
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	
	links 
	{ 
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}


	filter "system:windows"
		systemversion "latest"

		defines 
		{
			"RAVEN_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "RAVEN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RAVEN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RAVEN_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
	
	includedirs
	{
		"RavenEngine/src",
		"RavenEngine/vendor/spdlog/include",
		"RavenEngine/vendor",
		"%{IncludeDir.glm}"
	}

	defines 
	{
		"RAVEN_PLATFORM_WINDOWS"
	}

	links 
	{
		"RavenEngine"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "RAVEN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RAVEN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RAVEN_DIST"
		runtime "Release"
		optimize "on"