#pragma once

namespace SLEngine
{
    typedef enum class MouseCode : uint16_t
    {
        // From glfw3.h
        Button0 = 0,
        Button1 = 1,
        Button2 = 2,
        Button3 = 3,
        Button4 = 4,
        Button5 = 5,
        Button6 = 6,
        Button7 = 7,

        ButtonLast = Button7,
        ButtonLeft = Button0,
        ButtonRight = Button1,
        ButtonMiddle = Button2
    } Mouse;

    inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
    {
        os << static_cast<int32_t>(mouseCode);
        return os;
    }
}

#define SL_MOUSE_BUTTON_0      ::SLEngine::Mouse::Button0
#define SL_MOUSE_BUTTON_1      ::SLEngine::Mouse::Button1
#define SL_MOUSE_BUTTON_2      ::SLEngine::Mouse::Button2
#define SL_MOUSE_BUTTON_3      ::SLEngine::Mouse::Button3
#define SL_MOUSE_BUTTON_4      ::SLEngine::Mouse::Button4
#define SL_MOUSE_BUTTON_5      ::SLEngine::Mouse::Button5
#define SL_MOUSE_BUTTON_6      ::SLEngine::Mouse::Button6
#define SL_MOUSE_BUTTON_7      ::SLEngine::Mouse::Button7
#define SL_MOUSE_BUTTON_LAST   ::SLEngine::Mouse::ButtonLast
#define SL_MOUSE_BUTTON_LEFT   ::SLEngine::Mouse::ButtonLeft
#define SL_MOUSE_BUTTON_RIGHT  ::SLEngine::Mouse::ButtonRight
#define SL_MOUSE_BUTTON_MIDDLE ::SLEngine::Mouse::ButtonMiddle3