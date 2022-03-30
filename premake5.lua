--used to generate project files

workspace "BugsBunny"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "BugsBunny/vendor/GLFW/include"
 
include "BugsBunny/vendor/GLFW"

project "BugsBunny"
	location "BugsBunny" 
	kind"SharedLib"
	language"C++" 

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")
		 
	--specify which header file is our pch header
	pchheader "bbpch.h" 
	--only needed vor VisualStudio to create pch file
	pchsource "BugsBunny/src/bbpch.cpp" 

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
		
	--link GLFW to BugsBunny
	links {
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest" 
		
		defines	{
			"BB_BUILD_DLL",
			"BB_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "BB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "BB_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "BB_DIST"
		buildoptions "/MD"
		symbols "On"
 
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files 
		{

		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		}

		includedirs
		{
			"BugsBunny/vendor/spdlog/include",
			"BugsBunny/src"
		}

		--link BugsBunny to Sandbox
		links 
		{
			"BugsBunny"
		}

		filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest" 

		defines
		{ 
		"BB_PLATFORM_WINDOWS",
		}
	
	filter "configurations:Debug"
		defines "BB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "BB_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "BB_DIST"
		buildoptions "/MD"
		optimize "On"