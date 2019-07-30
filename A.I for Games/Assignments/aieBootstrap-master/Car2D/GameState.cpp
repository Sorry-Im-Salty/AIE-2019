#include "GameState.h"

GameState::GameState() {
	m_pGrid = nullptr;
	m_pAI = nullptr;
	m_pAI2 = nullptr;
}


GameState::~GameState() {
	if (m_pGrid) {
		delete m_pGrid;
		m_pGrid = nullptr;
	}
	if (m_pAI) {
		delete m_pAI;
		m_pAI = nullptr;
	}
	if (m_pAI2) {
		delete m_pAI2;
		m_pAI2 = nullptr;
	}
}

void GameState::Enter() {
	m_pGrid = new Grid(25, 12);
	m_pAI = new AI(m_pGrid);
	m_pAI2 = new AI(m_pGrid);
}

bool GameState::Update(float deltaTime, StateMachine* pStateMachine) {
	m_pStateMachine = pStateMachine;
	
	m_pAI->Update(deltaTime);
	m_pAI2->Update(deltaTime);
	
	return false;
}

void GameState::Draw(aie::Renderer2D* renderer) {
	m_pGrid->Draw(renderer);
	m_pAI->Draw(renderer);
	m_pAI2->Draw(renderer);
}

void GameState::Exit() {
	if (m_pGrid) {
		delete m_pGrid;
		m_pGrid = nullptr;
	}
	if (m_pAI) {
		delete m_pAI;
		m_pAI = nullptr;
	}
	if (m_pAI2) {
		delete m_pAI2;
		m_pAI2 = nullptr;
	}
}