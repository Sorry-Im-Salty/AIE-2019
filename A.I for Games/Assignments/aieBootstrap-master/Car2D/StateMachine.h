#pragma once
#include "Renderer2D.h"

class MenuState;
class GameState;
class GameOverState;

enum EState {
	ESTATE_MENU,
	ESTATE_GAME
};

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	bool Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

	void ChangeState(EState currentState);

protected:
	EState m_CurrentState;

	MenuState* m_pMenuState;
	GameState* m_pGameState;
};

