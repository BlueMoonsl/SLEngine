#include "slpch.h"
#include "Platform/Windows/WindowsInput.h"
#include "SLEngine/Core/Application.h"

#include <GLFW/glfw3.h>

namespace SLEngine {

	bool WindowsInput::IsKeyPressedImpl(KeyCode key) {
		// 获取GLFW原生窗口void*，转为GLFWwindow*
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		// 用已有的GLFW函数来获取按键状态
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsMouseButtonPressedImpl(MouseCode button) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}
	std::pair<float, float> WindowsInput::GetMousePositionImpl() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}
	float WindowsInput::GetMouseXImpl() {
		// C++17写法
		auto [x, y] = GetMousePositionImpl();
		return x;
		// C++14以下
		//auto x = GetMousePositionImpl();
		//return std::get<0>(x);
	}
	float WindowsInput::GetMouseYImpl() {
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}
