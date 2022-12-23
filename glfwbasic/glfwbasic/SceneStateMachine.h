#pragma once
#include "Scene.h"
#include <unordered_map>


namespace AlyfGE
{
	
}


class SceneStateMachine
{

public:
	template<typename T>
	// SFINAE substitution failure is not an Error
	// Enable the template/function if the base class of T is a Scene
	typename std::enable_if<std::is_base_of<AlyfGE::Scene, T>::value>::type addScene(unsigned int& out)
	{

		T* newScene = new T();

		auto pair = scenes.insert(std::make_pair(newScene->getName(), newScene));

		// first part of the pair has (string) and value (Scene*)
		// second is boolean if it fails or succeed being added to map

		if (pair.second == true)
		{
			// assign to scenemanager and initialize the scene
			// trace scenes
			pair.first->second->setStateMachine(this);
			pair.first->second->initialize();

			out = SceneIdCounter;
			SceneIdCounter++;
		}
		else
		{
			// avoid memory leak
			delete newScene;
		}
	}
	void loadScene(const std::string name);

	void update(float deltaTime);

	void render();
private:
	// sceneMap
	std::unordered_map<std::string, AlyfGE::Scene*>scenes;

	AlyfGE::Scene* curScene;

	unsigned int SceneIdCounter;
};