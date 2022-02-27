workspace "Squirrel"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Squirrel"
	location "Squirrel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/third_party/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"SQ_PLATFORM_WINDOWS",
			"SQ_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SQ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "SQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SQ_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Squirrel/third_party/spdlog/include",
		"Squirrel/src"
	}

	links{
		"Squirrel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"SQ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SQ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "SQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SQ_DIST"
		optimize "On"
