#pragma once

#include "SLEngine/Core/KeyCodes.h"
#include "SLEngine/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace SLEngine {
	class Input {
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
