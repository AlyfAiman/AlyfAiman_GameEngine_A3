#include "GameObj.h"

GameObj::GameObj(const std::string& name) : name(name), markedForRemoval(false)
{

}


GameObj::~GameObj()
{

	for (auto& c : components)
	{
		delete c;
	}
	components.clear();
}

void GameObj::awake()
{
	printf("GameObject %s is at awake state\n", name.c_str());

	for (auto& c : components)
	{
		c->awake();
	}
}

void GameObj::start()
{
	printf("GameObject %s is at Start state\n", name.c_str());

	for (auto& c : components)
	{
		c->start();
	}
}

void GameObj::update(float deltaTime)
{

	for (auto& c : components)

	{
		c->update(deltaTime);
	}
}

void GameObj::render()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->render();
	}
}

const std::string GameObj::getName()
{
	return name;
}

bool GameObj::mustRemove()
{
	return markedForRemoval;
}

void GameObj::markForRemoval()
{

	markedForRemoval = true;
}