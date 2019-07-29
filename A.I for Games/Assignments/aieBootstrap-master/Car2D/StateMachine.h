#pragma once

class MenuState;
class GameState;
class GameOverState;

enum EState {
	ESTATE_MENU,
	ESTATE_GAME,
	ESTATE_GAMEOVER
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
	GameOverState* m_pGameOverState;
};

