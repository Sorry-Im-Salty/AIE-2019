#pragma once
#include "BaseState.h"
class GameState : public BaseState {
public:
	GameState();
	~GameState();

	void Enter();
	void Exit();

	bool Update(float deltaTime, StateMachine* pStateMachine);
	void Draw(aie::Renderer2D* renderer);

private:

};

