#pragma once
#include "BaseState.h"
#include "AI.h"
#include "Grid.h"
class GameState : public BaseState {
public:
	GameState();
	~GameState();

	void Enter();
	void Exit();

	bool Update(float deltaTime, StateMachine* pStateMachine);
	void Draw(aie::Renderer2D* renderer);

private:
	Grid* m_pGrid;
	AI* m_pAI;
	AI* m_pAI2;
	StateMachine* m_pStateMachine;
	Button* m_pPauseButton;

	float m_fWindowWidth;
	float m_fWindowHeight;
	bool m_bPause;
};

