#include "GameState.h"
#include "Button.h"

GameState::GameState() {
	m_pGrid = nullptr;
	m_pAI = nullptr;
	m_pAI2 = nullptr;
	m_pPauseButton = nullptr;

	m_fWindowWidth = 1280.0f;
	m_fWindowHeight = 720.0f;
	m_bPause = false;
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
	if (m_pPauseButton) {
		delete m_pPauseButton;
		m_pPauseButton = nullptr;
	}
}

void GameState::Enter() {
	m_pGrid = new Grid(25, 12);
	m_pAI = new AI(m_pGrid);
	m_pAI2 = new AI(m_pGrid);
	m_pPauseButton = new Button("Pause", m_fWindowWidth / 2.0f, m_fWindowHeight - 55.0f, 320, 85, 204, 0, 0);
}

bool GameState::Update(float deltaTime, StateMachine* pStateMachine) {
	m_pStateMachine = pStateMachine;
	if (m_bPause == false) {
		m_pAI->Update(deltaTime);
		m_pAI2->Update(deltaTime);
		if (m_pPauseButton->Update())
			m_bPause = true;
	}
	else {
		if (m_pPauseButton->Update())
			m_bPause = false;
	}

	m_pGrid->Update(deltaTime);

	return false;
}

void GameState::Draw(aie::Renderer2D* renderer) {
	m_pGrid->Draw(renderer);
	m_pAI->Draw(renderer);
	m_pAI2->Draw(renderer);
	m_pPauseButton->Draw(renderer);
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
	if (m_pPauseButton) {
		delete m_pPauseButton;
		m_pPauseButton = nullptr;
	}
}