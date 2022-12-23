#include "GoCollection.h"

void GoCollection::add(GameObj* go)
{
	toBeAddedGameObjs.push_back(go);
}

void GoCollection::update(float deltaTime)
{
	processRemovals();
	processNewGameObjs();
	for (auto& go : gameObjs)
	{
		go->update(deltaTime);
	}
}

void GoCollection::render()
{
	for (auto& go : gameObjs)
	{
		go->render();
	}
}

void GoCollection::processNewGameObjs()
{

	if (toBeAddedGameObjs.size() > 0)
	{
		for (auto& go : toBeAddedGameObjs)
		{
			go->awake();
		}

		for (auto& go : toBeAddedGameObjs)
		{
			go->start();
		}

		//add to list
		gameObjs.insert(gameObjs.end(), toBeAddedGameObjs.begin(), toBeAddedGameObjs.end());

		//cleanup gameobjs to be added
		toBeAddedGameObjs.clear();
	}
}


bool CheckGameObjRemove(GameObj* go)
{
	bool mustremove = go->mustRemove();

	if (mustremove)
	{
		delete go;
	}

	return mustremove;
}

void GoCollection::processRemovals()
{
	//Find all gameObjs that have been marked for removal
	auto it = std::remove_if(gameObjs.begin(), gameObjs.end(), CheckGameObjRemove);

	gameObjs.erase(it, gameObjs.end());
}