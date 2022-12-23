#pragma once
#include "BaseComp.h"
#include "GoCollection.h"
#include "GameObj.h"
#include <stdio.h>
#include "InputSystem.h"

namespace mainComp
{

	// Custom Comp that inherits form baseComp
	class BarComp :public AlyfGE::BaseComp
	{
	public:
		BarComp(GameObj* go) : BaseComp(go) {}

		~BarComp()
		{
			printf("Destroying BarComp on %s\n", owner->getName().c_str());
		}

		void update(float deltaTime)override
		{
			if (Input::InputSystem::GetKey(A))
			{
				printf("A is being pressed, GameObject %s\n", owner->getName().c_str());
			}
			if (Input::InputSystem::GetKeyUp(D))
			{
				printf("GameObj %s has been removed\n", owner->getName().c_str());
				owner->markForRemoval();
			}
			if (Input::InputSystem::GetKey(S)) 
			{
				
			}
			if (Input::InputSystem::GetKey(Q))
			{

			}
			if (Input::InputSystem::GetKey(E))
			{

			}

			/*if (Input::InputSystem::GetMouseDown(RightMouse))
			{
				printf("RMB is pressed at %f, %f\n", Input::InputSystem::getMouseX(), Input::InputSystem::getMouseY());
			}
			if (Input::InputSystem::GetMouseDown(LeftMouse))
			{
				printf("LMB is pressed at %.2f, %.2f\n", Input::InputSystem::getMouseX(), Input::InputSystem::getMouseY());
			}*/
		}


	};
}
