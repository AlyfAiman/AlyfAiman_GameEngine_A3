#pragma once
#include <iostream>
#include "Scene.h"
#include "InputSystem.h"
#include "GoCollection.h"
#include "GameObj.h"
#include "BarComp.h"
#include "Guid.h"
#include <glad/glad.h>
#include "SpriteRenderer.h"



AlyfGE::Window* window;

class GameScene : public AlyfGE::Scene
{
public:


	void initialize()override
	{
		for (int i = 0; i < 1; i++)
		{
			GameObj* testingGo = new GameObj("GameObject_1" + std::to_string(i));
			testingGo->GameObj::addComp<mainComp::BarComp>();
			auto spr = testingGo->addComp<AlyfGE::SpriteRenderer>();

			spr->loadTexture("../Assets/SpaceShip.png");
			testingGo->transformation->Position.x = i * 50;
			testingGo->transformation->Position.y = 300;

			objCollection.add(testingGo);
		}

		for (int i = 0; i < 1; i++) 
		{

			GameObj* buzzGO = new GameObj("GameObject_2" + std::to_string(i));
			buzzGO->GameObj::addComp<mainComp::BarComp>();
			auto spr = buzzGO->addComp<AlyfGE::SpriteRenderer>();

			spr->loadTexture("../Assets/Buzzsaw.png");
			buzzGO->transformation->Position.x = 200;
			buzzGO->transformation->Position.y = 300;
			

			objCollection.add(buzzGO);
		}
		

	}

	void dispose()override {}


	// Shows the user that the gameScene has been activated and that the splashScene is over
	void activate() override
	{
		printf("GameScene activated\n");

		auto Guid1 = Guid::createGUID();
		auto Guid2 = Guid::createGUID();
		auto Guid3 = Guid::createGUID();
		auto Guid4 = Guid::createGUID();
		auto Guid5 = Guid::createGUID();

		std::cout << "GUID1: " << Guid1.getString() << std::endl;
		std::cout << "GUID2: " << Guid2.getString() << std::endl;
		std::cout << "GUID3: " << Guid3.getString() << std::endl;
		std::cout << "GUID4: " << Guid4.getString() << std::endl;
		std::cout << "GUID5: " << Guid5.getString() << std::endl;

		std::cout << std::endl;
		glClearColor(153 / 255.f, 0 / 154.f, 76 / 1.f, 1.0f);

		glMatrixMode(GL_PROJECTION);
		glOrtho(0, 600, 0, 600, -0.1, 1000);
		glMatrixMode(GL_MODELVIEW);
	}

	void deactivate() override
	{
		printf("Game Scene successfully deactivated!\n");
	}
	const std::string getName()
	{
		return "GameScene";
	}

	void update(float deltaTime)override
	{
		objCollection.update(deltaTime);
	}

	void render() override
	{
		objCollection.render();
	}

private:

	GoCollection objCollection;
};