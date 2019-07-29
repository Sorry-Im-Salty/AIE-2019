#pragma once
#include "BaseState.h"
class GameState : public BaseState {
public:
	GameState();
	virtual ~GameState();

	void Enter();
	void Exit();

	virtual bool Update(float deltaTime, StateMachine* pStateMachine);
	virtual void Draw(aie::Renderer2D* renderer);

private:

};

