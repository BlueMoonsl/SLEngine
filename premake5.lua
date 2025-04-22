workspace "SLEngine"	
	architecture "x64"	
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

	filter "files:**.cpp"
        buildoptions { "-utf-8" }

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "SLEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "SLEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "SLEngine/vendor/imgui"
IncludeDir["glm"] = "SLEngine/vendor/glm"
IncludeDir["stb_image"] = "SLEngine/vendor/stb_image"

include "SLEngine/vendor/GLFW"
include "SLEngine/vendor/Glad"
include "SLEngine/vendor/imgui"

project "SLEngine"		
	location "SLEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "slpch.h"
	pchsource "SLEngine/src/slpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
 		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
 		"%{IncludeDir.stb_image}"
	}
	links { 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"	

		defines{
			"SL_PLATFORM_WINDOWS",
			"SL_BUILD_DLL",
			"GLFW_INCLUDE_NONE" 
		}

	filter "configurations:Debug"
		defines "SL_DEBUG"
		buildoptions "/MDd"
		--runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SL_RELEASE"
		buildoptions "/MD"
		--runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SL_DIST"
		buildoptions "/MD"
		--runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"	

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"SLEngine/vendor/spdlog/include",
		"SLEngine/src",
		"SLEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links{
		"SLEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"SL_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "SL_DEBUG"
		buildoptions "/MDd"
		--runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SL_RELEASE"
		buildoptions "/MD"
		--runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SL_DIST"
		buildoptions "/MD"
		--runtime "Release"
		optimize "on"
