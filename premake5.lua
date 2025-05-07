include "./vendor/premake/premake_customization/solution_items.lua"

workspace "SLEngine"	
	architecture "x86_64"	
	startproject "Editor"
	
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
 	{
 		".editorconfig"
 	}

	filter "files:**.cpp"
        buildoptions { "-utf-8" }

	flags
 	{
 		"MultiProcessorCompile"
 	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/SLEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/SLEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/SLEngine/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/SLEngine/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/SLEngine/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/SLEngine/vendor/entt/include"

group "Dependencies"
 	include "vendor/premake"
 	include "SLEngine/vendor/GLFW"
 	include "SLEngine/vendor/Glad"
 	include "SLEngine/vendor/imgui"
group ""

include "SLEngine"
include "Sandbox"
include "Editor"