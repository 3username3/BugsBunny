--used to generate project files

workspace "BugsBunny"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "BugsBunny"

		location "BugsBunny" 
		kind"SharedLib"
		language"C++"

		targetdir ("bin/" ..outputdir .. "/%{prj.name}")
		objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

		files 
		{

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

		}

		includedirs
		{
			"%{prj.name}/vendor/spdlog/include"
		}


		filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest" 

		defines
		{
		"BB_BUILD_DLL",
		"BB_PLATFORM_WINDOWS",   	
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "BB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BB_DIST"
		symbols "On"
 
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

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

		--link BugsBunny

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
		symbols "On"

	filter "configurations:Release"
		defines "BB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BB_DIST"
		symbols "On"