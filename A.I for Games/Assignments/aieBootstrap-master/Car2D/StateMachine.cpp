#include "StateMachine.h"
#include "Renderer2D.h"


StateMachine::StateMachine()
{
	m_pMenuState = new MenuState();
	m_pGameState = new GameState();
	m_pGameOverState = new GameOverState();

	ChangeState(ESTATE_MENU);
}


StateMachine::~StateMachine()
{
	delete m_pMenuState;
	delete m_pGameState;
	delete m_pGameOverState;
}

bool StateMachine::Update(float deltaTime) {
	switch (m_CurrentState) {
	case ESTATE_MENU:
		return m_pMenuState->Update(deltaTime, this);
		break;
	case ESTATE_GAME:
		return m_pGameState->Update(deltaTime, this);
		break;
	case ESTATE_GAMEOVER:
		return m_pGameOverState->Update(deltaTime, this);
		break;
	}
	return false;
}

void StateMachine::Draw(aie::Renderer2D* renderer) {
	switch (m_CurrentState) {
	case ESTATE_MENU:
		m_pMenuState->Draw(rendermanager);
		break;
	case ESTATE_GAME:
		m_pGameState->Draw(rendermanager);
		break;
	case ESTATE_GAMEOVER:
		m_pGameOverState->Draw(rendermanager);
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
	case ESTATE_GAMEOVER:
		m_pGameOverState->Exit();
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
	case ESTATE_GAMEOVER:
		m_pGameOverState->Enter();
		break;
	}
}
