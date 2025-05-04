#pragma once

#include "SLEngine/Core/Base.h"
#include "SLEngine/Core/KeyCodes.h"
#include "SLEngine/Core/MouseCodes.h"

namespace SLEngine {
	class Input {
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
