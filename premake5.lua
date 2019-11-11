workspace "RavenEngine"
	architecture "x64"
	startproject "Sandbox"
    configurations { "Debug", "Release" }


outputdir = "%{cfg.buildcfg}-%{cfg.system}"

IncludeDir = {}
IncludeDir["GLFW"] = "RavenEngine/vendor/GLFW/include"
IncludeDir["GLAD"] = "RavenEngine/vendor/GLAD/include"


group "Dependencies"
	include "RavenEngine/vendor/GLFW"
	include "RavenEngine/vendor/GLAD"

group ""

project "RavenEngine"
	location "RavenEngine"
	language "C++"
	kind "SharedLib"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "ravenpch.h"
	pchsource "Raven/src/ravenpch.cpp"

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}"
	}

		
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	
	links 
	{ 
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"RAVEN_PLATFORM_WINDOWS",
			"RAVEN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") }

	filter "configurations:Debug"
		defines "RAVEN_DEBUG"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
	
	includedirs
	{
		"RavenEngine/src",
		"RavenEngine/vendor/spdlog/include",
		"RavenEngine/vendor",
	}


	links "RavenEngine"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"RAVEN_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "RAVEN_DEBUG"
		symbols "On"