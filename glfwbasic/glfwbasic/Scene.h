#pragma once
#include<string>
#include "GoCollection.h"

//circular dependency!
class SceneStateMachine;

namespace AlyfGE
{
	class Scene
	{
	public:
		virtual void initialize() = 0;
		virtual void dispose() = 0;
		virtual void activate() {};
		virtual void deactivate() {};
		virtual void update(float deltaTime) {};
		virtual void render() {};

		void setStateMachine(SceneStateMachine* sm)
		{
			stateMachine = sm;
		}

		virtual const std::string getName() = 0;

	private:
		GoCollection objCollection;

	protected:
		SceneStateMachine* stateMachine;
	};
}
