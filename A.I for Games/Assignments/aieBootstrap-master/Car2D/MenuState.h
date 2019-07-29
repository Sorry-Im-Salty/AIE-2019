#pragma once
#include "BaseState.h"

class MenuState : public BaseState
{
public:
	MenuState();
	~MenuState();

	void Enter();
	bool Update(float deltaTime, StateMachine* pStateMachine);
	void Draw(aie::Renderer2D* renderer);
	void Exit();

private:
	StateMachine* m_pStateMachine;
	Button* m_PlayButton;
	Button* m_QuitButton;
	aie::Font* m_Font;
	
	float m_fWindowWidth;
	float m_fWindowHeight;
};

