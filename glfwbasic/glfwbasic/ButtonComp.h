#pragma once
#include <functional>
#include <stdio.h>
#include "BaseComp.h"
#include "GameObj.h"
#include "GOCollection.h"
#include "InputSystem.h"
#include "Signal.h"
#include "Signal.h"
#include "Transformation.h"
#include "Window.h"

namespace AlyfGE
{
	// Attempt to create button Component

	typedef std::function<void()> clickEvt;

	class events 
	{
		void SpawnObj();

	private:
		GoCollection collection;
	};


	class ButtonComp :public AlyfGE::BaseComp 
	{
		ButtonComp(GameObj* go);
		~ButtonComp();

		void SetListener(void (*evt)());

		void setListener(events* c, void(events::* evt)());

	private:
		clickEvt onClick;
	};
}