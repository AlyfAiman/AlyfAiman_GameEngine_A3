#include "SceneStateMachine.h"

void SceneStateMachine::render()
{
	curScene->render();
}

void SceneStateMachine::update(float deltaTime)
{
	curScene->update(deltaTime);
}

void SceneStateMachine::loadScene(const std::string name)
{
	std::unordered_map<std::string, AlyfGE::Scene*>::iterator it = scenes.find(name);

	// check if scene list is empty
	// if no, do this
	if (it != scenes.end())
	{
		if (curScene != nullptr)
			curScene->deactivate();
		

		curScene = it->second;
		curScene->activate();
	}
}