#pragma once
#include "BaseState.h"
class GameOverState : public BaseState {
public:
	GameOverState();
	~GameOverState();

	void Enter();
	bool Update(float deltaTime, StateMachine* pStateMachine);
	void Draw(aie::Renderer2D* renderer);
	void Exit();

private:
	StateMachine* m_pStateMachine;
	aie::Font* m_font;
	Button* m_QuitButton;
	Button* m_PlayButton;
	float m_fWindowWidth;
	float m_fWindowHeight;
};

