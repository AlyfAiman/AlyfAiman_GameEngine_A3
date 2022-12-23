#include "InputSystem.h"


bool currentKeyA = false; bool prevKeyA = false;
bool currentKeyB = false; bool prevKeyB = false;
bool currentKeyC = false; bool prevKeyC = false;
bool currentKeyD = false; bool prevKeyD = false;
bool currentKeyE = false; bool prevKeyE = false;
bool currentKeyF = false; bool prevKeyF = false;
bool currentKeyG = false; bool prevKeyG = false;
bool currentKeyH = false; bool prevKeyH = false;
bool currentKeyI = false; bool prevKeyI = false;
bool currentKeyJ = false; bool prevKeyJ = false;
bool currentKeyK = false; bool prevKeyK = false;
bool currentKeyL = false; bool prevKeyL = false;
bool currentKeyM = false; bool prevKeyM = false;
bool currentKeyN = false; bool prevKeyN = false;
bool currentKeyO = false; bool prevKeyO = false;
bool currentKeyP = false; bool prevKeyP = false;
bool currentKeyQ = false; bool prevKeyQ = false;
bool currentKeyR = false; bool prevKeyR = false;
bool currentKeyS = false; bool prevKeyS = false;
bool currentKeyT = false; bool prevKeyT = false;
bool currentKeyU = false; bool prevKeyU = false;
bool currentKeyV = false; bool prevKeyV = false;
bool currentKeyW = false; bool prevKeyW = false;
bool currentKeyX = false; bool prevKeyX = false;
bool currentKeyY = false; bool prevKeyY = false;
bool currentKeyZ = false; bool prevKeyZ = false;
bool currentKey1 = false; bool prevKey1 = false;
bool currentKey2 = false; bool prevKey2 = false;
bool currentKey3 = false; bool prevKey3 = false;
bool currentKey4 = false; bool prevKey4 = false;
bool currentKey5 = false; bool prevKey5 = false;
bool currentKey6 = false; bool prevKey6 = false;
bool currentKey7 = false; bool prevKey7 = false;
bool currentKey8 = false; bool prevKey8 = false;
bool currentKey9 = false; bool prevKey9 = false;
bool currentKey0 = false; bool prevKey0 = false;

bool currentKeyUP = false; bool prevKeyUP = false;
bool currentKeyDOWN = false; bool prevKeyDOWN = false;
bool currentKeyLEFT = false; bool prevKeyLEFT = false;
bool currentKeyRIGHT = false; bool prevKeyRIGHT = false;
bool currentKeyShiftR = false; bool prevKeyShiftR = false;
bool currentKeyShiftL = false; bool prevKeyShiftL = false;
bool currentKeyAltR = false; bool prevKeyAltR = false;
bool currentKeyAltL = false; bool prevKeyAltL = false;
bool currentKeyCtrlR = false; bool prevKeyCtrlR = false;
bool currentKeyCtrlL = false; bool prevKeyCtrlL = false;
bool currentKeySpace = false; bool prevKeySpace = false;
bool currentLeftLoc = false; bool prevLeftLoc = false;
bool currentRightLoc = false; bool prevRightLoc = false;


// Key dictionary
std::map<int, bool>currentStates =
{
		{ A, false },
		{ B, false },
		{ C, false },
		{ D, false },
		{ E, false },
		{ F, false },
		{ G, false },
		{ H, false },
		{ I, false },
		{ J, false },
		{ K, false },
		{ L, false },
		{ M, false },
		{ N, false },
		{ O, false },
		{ P, false },
		{ Q, false },
		{ R, false },
		{ S, false },
		{ T, false },
		{ U, false },
		{ V, false },
		{ W, false },
		{ X, false },
		{ Y, false },
		{ Z, false },
		{ ArrowLeft, false },
		{ ArrowRight, false },
		{ ArrowUp, false },
		{ ArrowDown, false },
		{ Alpha0, false },
		{ Alpha1, false },
		{ Alpha2, false },
		{ Alpha3, false },
		{ Alpha4, false },
		{ Alpha5, false },
		{ Alpha6, false },
		{ Alpha7, false },
		{ Alpha8, false },
		{ Alpha9, false },
		{ ShiftR, false },
		{ ShiftL, false },
		{ AltR, false },
		{ AltL, false },
		{ Space, false },
		{ CtrlR, false },
		{ CtrlL, false }
};

std::map<int, bool>prevStates = currentStates;

std::map<int, bool>currentLoc =
{
	{RightMouse,false},
	{LeftMouse, false}
};

std::map<int, bool>prevLoc = currentLoc;


void Input::InputSystem::Setup(GLFWwindow* window)
{

	glfwGetCursorPos(window, &x, &y);
	std::map<int, bool>::iterator it;

	for (it = prevStates.begin(); it != prevStates.end(); it++)
	{
		// set the the value of prevStates item to value of currentStates item
		it->second = currentStates[it->first];

	}

	for (it = currentStates.begin(); it != currentStates.end(); it++)
	{
		// Get state from GLFW,then set value to item
		it->second = glfwGetKey(window, it->first);

	}

	for (it = prevLoc.begin(); it != prevLoc.end(); it++)
	{
		// set the the value of prevStates item to value of currentStates item
		it->second = currentLoc[it->first];

	}

	for (it = currentLoc.begin(); it != currentLoc.end(); it++)
	{
		// Get state from GLFW,then set value to item
		it->second = glfwGetMouseButton(window, it->first);

	}

}

bool Input::InputSystem::GetKey(Keycode key)
{
	bool result = false;

	std::map<int, bool>::iterator it = currentStates.find(key);

	if (it != currentStates.end())
	{
		result = currentStates[key];
	}

	return result;
}

bool Input::InputSystem::GetKeyUp(Keycode key)
{
	bool prevVal;
	bool currVal;

	std::map<int, bool>::iterator it = prevStates.find(key);

	if (it != prevStates.end())
	{
		prevVal = prevStates[key];
	}
	it = currentStates.find(key);

	if (it != currentStates.end())
	{
		currVal = currentStates[key];
	}

	// return result;
	return prevVal == true && currVal == false;
}

bool Input::InputSystem::GetKeyDown(Keycode key)
{
	bool prevVal;
	bool curVal;

	std::map<int, bool>::iterator it = currentStates.find(key);
	if (it != currentStates.end())
	{
		curVal = currentStates[key];
	}

	it = prevStates.find(key);
	if (it != prevStates.end())
	{
		prevVal = prevStates[key];
	}

	// return result;
	return prevVal == false && curVal == true;
}

bool Input::InputSystem::GetMouse(MouseButton click)
{
	bool result = false;

	std::map<int, bool>::iterator it = currentLoc.find(click);

	if (it != currentLoc.end())
	{
		result = currentLoc[click];
	}

	return result;
}

bool Input::InputSystem::GetMouseUp(MouseButton click)
{
	bool prevClick;
	bool curClick;

	std::map<int, bool>::iterator it = prevLoc.find(click);

	if (it != prevLoc.end())
	{
		prevClick = prevLoc[click];
	}
	it = currentLoc.find(click);

	if (it != currentLoc.end())
	{
		curClick = currentLoc[click];
	}

	// return result;
	return prevClick == true && curClick == false;
}

bool::Input::InputSystem::GetMouseDown(MouseButton click)
{
	bool prevClick;
	bool curClick;

	std::map<int, bool>::iterator it = currentLoc.find(click);

	if (it != currentLoc.end())
	{
		curClick = currentLoc[click];
	}
	it = prevLoc.find(click);

	if (it != prevLoc.end())
	{
		prevClick = prevLoc[click];
	}
	// return result;
	return prevClick == false && curClick == true;
}

double Input::InputSystem::getMouseX() {
	return x;
}

double Input::InputSystem::getMouseY() {
	return y;
}