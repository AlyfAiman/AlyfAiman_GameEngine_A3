#pragma once
#include <string>
#include <vector>
#include "BaseComp.h"
#include "Transformation.h"

class GameObj
{
public:
	Transformation* transformation = new Transformation();
	GameObj(const std::string& name);
	~GameObj();

	void awake();
	void start();
	void update(float deltaTime);
	void render();

	const std::string getName();

	// Used in GameObjcectCollection
	bool mustRemove();

	void markForRemoval();

	// AddComponent
	// Reminder, in c++, template funcs have to be declared in header files
	template<typename T>

	// typename std::enable_if<std::is_base_of<BaseComp, T>::value>::type
	T* addComp() {

		// Constuct wanted component
		// Pass in curr GameObj as the owner
		// Add to the list of comps
		// Return to comp

		T* newComp = new T(this);
		components.push_back(newComp);

		return newComp;
	}

	// GetComponent
	template<typename T>

	// typename std::enable_if<std::is_base_of<BaseComp, T>::value>::type
	T* getComp()
	{

		for (auto& c : components)
		{
			// find component that matches type
			// return the first item found
			if (typeid(*c) == typeid(T))
			{
				return (T*)c;
			}
		}

		return nullptr;
	}

	float angle;

private:
	bool markedForRemoval = false;

	std::vector < AlyfGE:: BaseComp* > components;

	std::string name;
};