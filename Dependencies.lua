
-- SLEngine Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/SLEngine/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/SLEngine/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/SLEngine/vendor/Box2D/include"
IncludeDir["filewatch"] = "%{wks.location}/SLEngine/vendor/filewatch"
IncludeDir["GLFW"] = "%{wks.location}/SLEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/SLEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/SLEngine/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/SLEngine/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/SLEngine/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/SLEngine/vendor/entt/include"
IncludeDir["mono"] = "%{wks.location}/SLEngine/vendor/mono/include"
IncludeDir["shaderc"] = "%{wks.location}/SLEngine/vendor/VulkanSDK/include/shaderc"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/SLEngine/vendor/VulkanSDK/include/spirv_cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}
LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["mono"] = "%{wks.location}/SLEngine/vendor/mono/lib/%{cfg.buildcfg}"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"
Library["mono"] = "%{LibraryDir.mono}/libmono-static-sgen.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"