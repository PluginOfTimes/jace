workspace "Snowflax"
	architecture "x64"

	configurations {
		"Debug",
		"Release"
	}

	files {
		"premake5.lua",
		".gitignore"
	}

	startproject "jace"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "jace"
	location "jace"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"jace/src"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

	filter "configurations:Debug"
		defines "JACE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JACE_RELEASE"
		optimize "On"