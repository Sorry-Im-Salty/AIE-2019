#include "StateMachine.h"
#include "Renderer2D.h"
#include "MenuState.h"
#include "GameState.h"

StateMachine::StateMachine()
{
	m_pMenuState = new MenuState();
	m_pGameState = new GameState();

	ChangeState(ESTATE_MENU);
}


StateMachine::~StateMachine()
{
	delete m_pMenuState;
	delete m_pGameState;
}

bool StateMachine::Update(float deltaTime) {
	switch (m_CurrentState) {
	case ESTATE_MENU:
		return m_pMenuState->Update(deltaTime, this);
		break;
	case ESTATE_GAME:
		return m_pGameState->Update(deltaTime, this);
		break;
	}
	return false;
}

void StateMachine::Draw(aie::Renderer2D* renderer) {
	switch (m_CurrentState) {
	case ESTATE_MENU:
		m_pMenuState->Draw(renderer);
		break;
	case ESTATE_GAME:
		m_pGameState->Draw(renderer);
		break;
	}
}

void StateMachine::ChangeState(EState currentState) {
	switch (m_CurrentState) {
	case ESTATE_MENU:
		m_pMenuState->Exit();
		break;
	case ESTATE_GAME:
		m_pGameState->Exit();
		break;
	}

	m_CurrentState = currentState;

	switch (m_CurrentState) {
	case ESTATE_MENU:
		m_pMenuState->Enter();
		break;
	case ESTATE_GAME:
		m_pGameState->Enter();
		break;
	}
}
