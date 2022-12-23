#pragma once

// GameObj holds comp
// Comp has GameObj as owner
// Result in circular dependency

class GameObj;

namespace AlyfGE
{
	class BaseComp
	{
	public:

		BaseComp(GameObj* go);
		virtual ~BaseComp();

		virtual void awake() {}
		virtual void start() {}
		virtual void update(float deltaTime) {}
		virtual void OnEnable() {}
		virtual void OnDisable() {}
		virtual void render() {}

	protected:
		// keeping track of the owner allows to use the getComp func.
		// allows us to change codes inside the comp.
		GameObj* owner;
	};
}

