#pragma once

#include <glm/glm.hpp>
#include "SLEngine/Core/KeyCodes.h"
#include "SLEngine/Core/MouseCodes.h"

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
