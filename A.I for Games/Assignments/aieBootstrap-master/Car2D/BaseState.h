#pragma once
#include "Renderer2D.h"
#include "Button.h"

class StateMachine;
class BaseState {
public:
	BaseState() { };
	virtual ~BaseState() { };
	virtual void Enter() { };
	virtual bool Update(float deltaTime, StateMachine* pStateMachine) {
		m_pStateMachine = pStateMachine;
		return false;
	};
	virtual void Draw(aie::Renderer2D* renderer) { };
	virtual void Exit() { };

private:
	StateMachine* m_pStateMachine;
};