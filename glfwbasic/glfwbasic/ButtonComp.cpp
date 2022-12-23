#include "ButtonComp.h"

AlyfGE::ButtonComp::ButtonComp(GameObj* go) :BaseComp(go) 
{

}

AlyfGE::ButtonComp::~ButtonComp() 
{

}

// attampted button comp.
void AlyfGE::ButtonComp::SetListener(void (*evt)())
{
	onClick = evt;
}

void AlyfGE::ButtonComp::setListener(events* c, void(events::* evt)()) 
{
	onClick = [=]() 
	{
		(c->*evt)();
	};
}