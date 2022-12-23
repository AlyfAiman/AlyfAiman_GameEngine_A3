#pragma once
#include <vector>
#include "GameObj.h"


class GoCollection
{
public:

	// class used for storing gameObjects. Easier for removal and addition and 
	// other functions. The first function is used to add gameObj to the collection.
	void add(GameObj* go);


	// Update the gameObjectCollection for any additional created gameObjects. 
	// In this case, all will be spawned in the gamescene.h
	void update(float deltaTime);

	// Render the gameObjects in the GOCollection
	void render();

private:

	// Process in waiting gameObjects
	void processNewGameObjs();

	// Marks gameObjects that has been deleted or removed from the list to be removed
	void processRemovals();

	std::vector<GameObj*>gameObjs;
	std::vector<GameObj*>toBeAddedGameObjs;


};