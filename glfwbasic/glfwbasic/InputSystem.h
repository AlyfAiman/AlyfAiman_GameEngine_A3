#pragma once
#include <glfw/glfw3.h>
#include <vector>
#include <map>

enum Keycode
{
	A = GLFW_KEY_A,
	B = GLFW_KEY_B,
	C = GLFW_KEY_C,
	D = GLFW_KEY_D,
	E = GLFW_KEY_E,
	F = GLFW_KEY_F,
	G = GLFW_KEY_G,
	H = GLFW_KEY_H,
	I = GLFW_KEY_I,
	J = GLFW_KEY_J,
	K = GLFW_KEY_K,
	L = GLFW_KEY_L,
	M = GLFW_KEY_M,
	N = GLFW_KEY_N,
	O = GLFW_KEY_O,
	P = GLFW_KEY_P,
	Q = GLFW_KEY_Q,
	R = GLFW_KEY_R,
	S = GLFW_KEY_S,
	T = GLFW_KEY_T,
	U = GLFW_KEY_U,
	V = GLFW_KEY_V,
	W = GLFW_KEY_W,
	X = GLFW_KEY_X,
	Y = GLFW_KEY_Y,
	Z = GLFW_KEY_Z,
	ArrowLeft = GLFW_KEY_LEFT,
	ArrowRight = GLFW_KEY_RIGHT,
	ArrowUp = GLFW_KEY_UP,
	ArrowDown = GLFW_KEY_DOWN,
	Alpha1 = GLFW_KEY_1,
	Alpha2 = GLFW_KEY_2,
	Alpha3 = GLFW_KEY_3,
	Alpha4 = GLFW_KEY_4,
	Alpha5 = GLFW_KEY_5,
	Alpha6 = GLFW_KEY_6,
	Alpha7 = GLFW_KEY_7,
	Alpha8 = GLFW_KEY_8,
	Alpha9 = GLFW_KEY_9,
	Alpha0 = GLFW_KEY_0,
	ShiftR = GLFW_KEY_RIGHT_SHIFT,
	ShiftL = GLFW_KEY_LEFT_SHIFT,
	AltR = GLFW_KEY_RIGHT_ALT,
	AltL = GLFW_KEY_LEFT_ALT,
	Space = GLFW_KEY_SPACE,
	CtrlR = GLFW_KEY_RIGHT_CONTROL,
	CtrlL = GLFW_KEY_LEFT_CONTROL
};


enum MouseButton
{
	RightMouse = GLFW_MOUSE_BUTTON_RIGHT,
	LeftMouse = GLFW_MOUSE_BUTTON_LEFT
};


namespace Input
{

	extern std::vector<Keycode> keys;
	extern std::vector<MouseButton> mouse;

	static double x, y;
	class InputSystem
	{

	public:
		static void Setup(GLFWwindow* window);

		static bool GetKey(Keycode key);
		static bool GetKeyUp(Keycode key);
		static bool GetKeyDown(Keycode key);

		static bool GetMouse(MouseButton click);
		static bool GetMouseUp(MouseButton click);
		static bool GetMouseDown(MouseButton click);

		static double getMouseX();
		static double getMouseY();

	private:
		InputSystem();

		static InputSystem instance;

		GLFWwindow* windowRef;
	};

}