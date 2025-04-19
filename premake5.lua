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

include "SLEngine/vendor/GLFW"
include "SLEngine/vendor/Glad"
include "SLEngine/vendor/imgui"

project "SLEngine"		
	location "SLEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "slpch.h"
	pchsource "SLEngine/src/slpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	links { 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"	

		defines{
			"SL_PLATFORM_WINDOWS",
			"SL_BUILD_DLL",
			"GLFW_INCLUDE_NONE" 
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SL_DEBUG"
		buildoptions "/MDd"
		--runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		buildoptions "/MD"
		--runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		buildoptions "/MD"
		--runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"	

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
		cppdialect "C++17"
		systemversion "latest"

		defines{
			"SL_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "SL_DEBUG"
		buildoptions "/MDd"
		--runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		buildoptions "/MD"
		--runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		buildoptions "/MD"
		--runtime "Release"
		optimize "On"
