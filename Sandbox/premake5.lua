project "Sandbox"
 	kind "ConsoleApp"
 	language "C++"
 	cppdialect "C++17"
 	staticruntime "off"
 
 	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
 	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
 
 	files
 	{
 		"src/**.h",
 		"src/**.cpp"
 	}
 
 	includedirs
 	{
 		"%{wks.location}/SLEngine/vendor/spdlog/include",
 		"%{wks.location}/SLEngine/src",
 		"%{wks.location}/SLEngine/vendor",
 		"%{IncludeDir.glm}",
 		"%{IncludeDir.entt}"
 	}
 
 	links
 	{
 		"SLEngine"
 	}
 
 	filter "system:windows"
 		systemversion "latest"
 
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
 		defines "Sl_DIST"
		buildoptions "/MD"
 		--runtime "Release"
 		optimize "on"