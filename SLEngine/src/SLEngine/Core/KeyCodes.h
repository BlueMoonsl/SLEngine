#pragma once

namespace SLEngine
 {
 	typedef enum class KeyCode : uint16_t
 	{
 		// From glfw3.h
 		Space               = 32,
 		Apostrophe          = 39, /* ' */
 		Comma               = 44, /* , */
 		Minus               = 45, /* - */
 		Period              = 46, /* . */
 		Slash               = 47, /* / */
 
 		D0                  = 48, /* 0 */
 		D1                  = 49, /* 1 */
 		D2                  = 50, /* 2 */
 		D3                  = 51, /* 3 */
 		D4                  = 52, /* 4 */
 		D5                  = 53, /* 5 */
 		D6                  = 54, /* 6 */
 		D7                  = 55, /* 7 */
 		D8                  = 56, /* 8 */
 		D9                  = 57, /* 9 */
 
 		Semicolon           = 59, /* ; */
 		Equal               = 61, /* = */
 
 		A                   = 65,
 		B                   = 66,
 		C                   = 67,
 		D                   = 68,
 		E                   = 69,
 		F                   = 70,
 		G                   = 71,
 		H                   = 72,
 		I                   = 73,
 		J                   = 74,
 		K                   = 75,
 		L                   = 76,
 		M                   = 77,
 		N                   = 78,
 		O                   = 79,
 		P                   = 80,
 		Q                   = 81,
 		R                   = 82,
 		S                   = 83,
 		T                   = 84,
 		U                   = 85,
 		V                   = 86,
 		W                   = 87,
 		X                   = 88,
 		Y                   = 89,
 		Z                   = 90,
 
 		LeftBracket         = 91,  /* [ */
 		Backslash           = 92,  /* \ */
 		RightBracket        = 93,  /* ] */
 		GraveAccent         = 96,  /* ` */
 
 		World1              = 161, /* non-US #1 */
 		World2              = 162, /* non-US #2 */
 
 		/* Function keys */
 		Escape              = 256,
 		Enter               = 257,
 		Tab                 = 258,
 		Backspace           = 259,
 		Insert              = 260,
 		Delete              = 261,
 		Right               = 262,
 		Left                = 263,
 		Down                = 264,
 		Up                  = 265,
 		PageUp              = 266,
 		PageDown            = 267,
 		Home                = 268,
 		End                 = 269,
 		CapsLock            = 280,
 		ScrollLock          = 281,
 		NumLock             = 282,
 		PrintScreen         = 283,
 		Pause               = 284,
 		F1                  = 290,
 		F2                  = 291,
 		F3                  = 292,
 		F4                  = 293,
 		F5                  = 294,
 		F6                  = 295,
 		F7                  = 296,
 		F8                  = 297,
 		F9                  = 298,
 		F10                 = 299,
 		F11                 = 300,
 		F12                 = 301,
 		F13                 = 302,
 		F14                 = 303,
 		F15                 = 304,
 		F16                 = 305,
 		F17                 = 306,
 		F18                 = 307,
 		F19                 = 308,
 		F20                 = 309,
 		F21                 = 310,
 		F22                 = 311,
 		F23                 = 312,
 		F24                 = 313,
 		F25                 = 314,
 
 		/* Keypad */
 		KP0                 = 320,
 		KP1                 = 321,
 		KP2                 = 322,
 		KP3                 = 323,
 		KP4                 = 324,
 		KP5                 = 325,
 		KP6                 = 326,
 		KP7                 = 327,
 		KP8                 = 328,
 		KP9                 = 329,
 		KPDecimal           = 330,
 		KPDivide            = 331,
 		KPMultiply          = 332,
 		KPSubtract          = 333,
 		KPAdd               = 334,
 		KPEnter             = 335,
 		KPEqual             = 336,
 
 		LeftShift           = 340,
 		LeftControl         = 341,
 		LeftAlt             = 342,
 		LeftSuper           = 343,
 		RightShift          = 344,
 		RightControl        = 345,
 		RightAlt            = 346,
 		RightSuper          = 347,
 		Menu                = 348
 	} Key;
 
 	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
 	{
 		os << static_cast<int32_t>(keyCode);
 		return os;
 	}
 }

// From glfw3.h	
#define SL_KEY_SPACE           ::SLEngine::Key::Space
#define SL_KEY_APOSTROPHE      ::SLEngine::Key::Apostrophe    /* ' */
#define SL_KEY_COMMA           ::SLEngine::Key::Comma         /* , */
#define SL_KEY_MINUS           ::SLEngine::Key::Minus         /* - */
#define SL_KEY_PERIOD          ::SLEngine::Key::Period        /* . */
#define SL_KEY_SLASH           ::SLEngine::Key::Slash         /* / */
#define SL_KEY_0               ::SLEngine::Key::D0
#define SL_KEY_1               ::SLEngine::Key::D1
#define SL_KEY_2               ::SLEngine::Key::D2
#define SL_KEY_3               ::SLEngine::Key::D3
#define SL_KEY_4               ::SLEngine::Key::D4
#define SL_KEY_5               ::SLEngine::Key::D5
#define SL_KEY_6               ::SLEngine::Key::D6
#define SL_KEY_7               ::SLEngine::Key::D7
#define SL_KEY_8               ::SLEngine::Key::D8
#define SL_KEY_9               ::SLEngine::Key::D9
#define SL_KEY_SEMICOLON       ::SLEngine::Key::Semicolon     /* ; */
#define SL_KEY_EQUAL           ::SLEngine::Key::Equal         /* = */
#define SL_KEY_A               ::SLEngine::Key::A
#define SL_KEY_B               ::SLEngine::Key::B
#define SL_KEY_C               ::SLEngine::Key::C
#define SL_KEY_D               ::SLEngine::Key::D
#define SL_KEY_E               ::SLEngine::Key::E
#define SL_KEY_F               ::SLEngine::Key::F
#define SL_KEY_G               ::SLEngine::Key::G
#define SL_KEY_H               ::SLEngine::Key::H
#define SL_KEY_I               ::SLEngine::Key::I
#define SL_KEY_J               ::SLEngine::Key::J
#define SL_KEY_K               ::SLEngine::Key::K
#define SL_KEY_L               ::SLEngine::Key::L
#define SL_KEY_M               ::SLEngine::Key::M
#define SL_KEY_N               ::SLEngine::Key::N
#define SL_KEY_O               ::SLEngine::Key::O
#define SL_KEY_P               ::SLEngine::Key::P
#define SL_KEY_Q               ::SLEngine::Key::Q
#define SL_KEY_R               ::SLEngine::Key::R
#define SL_KEY_S               ::SLEngine::Key::S
#define SL_KEY_T               ::SLEngine::Key::T
#define SL_KEY_U               ::SLEngine::Key::U
#define SL_KEY_V               ::SLEngine::Key::V
#define SL_KEY_W               ::SLEngine::Key::W
#define SL_KEY_X               ::SLEngine::Key::X
#define SL_KEY_Y               ::SLEngine::Key::Y
#define SL_KEY_Z               ::SLEngine::Key::Z
#define SL_KEY_LEFT_BRACKET    ::SLEngine::Key::LeftBracket   /* [ */
#define SL_KEY_BACKSLASH       ::SLEngine::Key::Backslash     /* \ */
#define SL_KEY_RIGHT_BRACKET   ::SLEngine::Key::RightBracket  /* ] */
#define SL_KEY_GRAVE_ACCENT    ::SLEngine::Key::GraveAccent   /* ` */
#define SL_KEY_WORLD_1         ::SLEngine::Key::World1        /* non-US #1 */
#define SL_KEY_WORLD_2         ::SLEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define SL_KEY_ESCAPE          ::SLEngine::Key::Escape
#define SL_KEY_ENTER           ::SLEngine::Key::Enter
#define SL_KEY_TAB             ::SLEngine::Key::Tab
#define SL_KEY_BACKSPACE       ::SLEngine::Key::Backspace
#define SL_KEY_INSERT          ::SLEngine::Key::Insert
#define SL_KEY_DELETE          ::SLEngine::Key::Delete
#define SL_KEY_RIGHT           ::SLEngine::Key::Right
#define SL_KEY_LEFT            ::SLEngine::Key::Left
#define SL_KEY_DOWN            ::SLEngine::Key::Down
#define SL_KEY_UP              ::SLEngine::Key::Up
#define SL_KEY_PAGE_UP         ::SLEngine::Key::PageUp
#define SL_KEY_PAGE_DOWN       ::SLEngine::Key::PageDown
#define SL_KEY_HOME            ::SLEngine::Key::Home
#define SL_KEY_END             ::SLEngine::Key::End
#define SL_KEY_CAPS_LOCK       ::SLEngine::Key::CapsLock
#define SL_KEY_SCROLL_LOCK     ::SLEngine::Key::ScrollLock
#define SL_KEY_NUM_LOCK        ::SLEngine::Key::NumLock
#define SL_KEY_PRINT_SCREEN    ::SLEngine::Key::PrintScreen
#define SL_KEY_PAUSE           ::SLEngine::Key::Pause
#define SL_KEY_F1              ::SLEngine::Key::F1
#define SL_KEY_F2              ::SLEngine::Key::F2
#define SL_KEY_F3              ::SLEngine::Key::F3
#define SL_KEY_F4              ::SLEngine::Key::F4
#define SL_KEY_F5              ::SLEngine::Key::F5
#define SL_KEY_F6              ::SLEngine::Key::F6
#define SL_KEY_F7              ::SLEngine::Key::F7
#define SL_KEY_F8              ::SLEngine::Key::F8
#define SL_KEY_F9              ::SLEngine::Key::F9
#define SL_KEY_F10             ::SLEngine::Key::F10
#define SL_KEY_F11             ::SLEngine::Key::F11
#define SL_KEY_F12             ::SLEngine::Key::F12
#define SL_KEY_F13             ::SLEngine::Key::F13
#define SL_KEY_F14             ::SLEngine::Key::F14
#define SL_KEY_F15             ::SLEngine::Key::F15
#define SL_KEY_F16             ::SLEngine::Key::F16
#define SL_KEY_F17             ::SLEngine::Key::F17
#define SL_KEY_F18             ::SLEngine::Key::F18
#define SL_KEY_F19             ::SLEngine::Key::F19
#define SL_KEY_F20             ::SLEngine::Key::F20
#define SL_KEY_F21             ::SLEngine::Key::F21
#define SL_KEY_F22             ::SLEngine::Key::F22
#define SL_KEY_F23             ::SLEngine::Key::F23
#define SL_KEY_F24             ::SLEngine::Key::F24
#define SL_KEY_F25             ::SLEngine::Key::F25

/* Keypad */
#define SL_KEY_KP_0            ::SLEngine::Key::KP0
#define SL_KEY_KP_1            ::SLEngine::Key::KP1
#define SL_KEY_KP_2            ::SLEngine::Key::KP2
#define SL_KEY_KP_3            ::SLEngine::Key::KP3
#define SL_KEY_KP_4            ::SLEngine::Key::KP4
#define SL_KEY_KP_5            ::SLEngine::Key::KP5
#define SL_KEY_KP_6            ::SLEngine::Key::KP6
#define SL_KEY_KP_7            ::SLEngine::Key::KP7
#define SL_KEY_KP_8            ::SLEngine::Key::KP8
#define SL_KEY_KP_9            ::SLEngine::Key::KP9
#define SL_KEY_KP_DECIMAL      ::SLEngine::Key::KPDecimal
#define SL_KEY_KP_DIVIDE       ::SLEngine::Key::KPDivide
#define SL_KEY_KP_MULTIPLY     ::SLEngine::Key::KPMultiply
#define SL_KEY_KP_SUBTRACT     ::SLEngine::Key::KPSubtract
#define SL_KEY_KP_ADD          ::SLEngine::Key::KPAdd
#define SL_KEY_KP_ENTER        ::SLEngine::Key::KPEnter
#define SL_KEY_KP_EQUAL        ::SLEngine::Key::KPEqual
                            
#define SL_KEY_LEFT_SHIFT      ::SLEngine::Key::LeftShift
#define SL_KEY_LEFT_CONTROL    ::SLEngine::Key::LeftControl
#define SL_KEY_LEFT_ALT        ::SLEngine::Key::LeftAlt
#define SL_KEY_LEFT_SUPER      ::SLEngine::Key::LeftSuper
#define SL_KEY_RIGHT_SHIFT     ::SLEngine::Key::RightShift
#define SL_KEY_RIGHT_CONTROL   ::SLEngine::Key::RightControl
#define SL_KEY_RIGHT_ALT       ::SLEngine::Key::RightAlt
#define SL_KEY_RIGHT_SUPER     ::SLEngine::Key::RightSuper
#define SL_KEY_MENU            ::SLEngine::Key::Menu