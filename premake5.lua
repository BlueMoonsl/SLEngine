include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
 	include "vendor/premake"
	include "SLEngine/vendor/Box2D"
 	include "SLEngine/vendor/GLFW"
 	include "SLEngine/vendor/Glad"
 	include "SLEngine/vendor/imgui"
	include "SLEngine/vendor/yaml-cpp"
group ""

group "Core"
	include "SLEngine"
	include "ScriptCore"
group ""

group "Tools"
	include "Editor"
group ""

group "Misc"
	include "Sandbox"
group ""