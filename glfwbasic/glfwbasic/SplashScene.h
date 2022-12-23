#pragma once
#include <iostream>
#include "Scene.h"
#include"SceneStateMachine.h"


class SplashScene : public AlyfGE::Scene
{
public:
	SceneStateMachine* stateMachine;

	void initialize()override {}
	void dispose()override {}

	void activate() override
	{
		glClearColor(0 / 255.f, 36 / 154.f, 100 / 1.f, 100);
		printf("Splash Scene successfully activated!\n");
	}
	void deactivate() override
	{
		printf("Splash Scene successfully deactivated!\n");
	}

	const std::string getName()
	{
		return "SplashScene";
	}

	void update(float deltaTime)override
	{
		durationInScene += deltaTime;

		if (durationInScene >= 4.0f)
		{
			// Scene manager load scene
			stateMachine->loadScene("GameScene");
		}
	}

private:
	float durationInScene = 0.0f;
};