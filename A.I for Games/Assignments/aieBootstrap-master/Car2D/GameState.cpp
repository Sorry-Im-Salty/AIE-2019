#include "GameState.h"
#include "Button.h"
#include "StateMachine.h"

GameState::GameState() {
	m_pGrid = nullptr;
	for (int i = 0; i <= 10; ++i)
		m_pAI[i] = nullptr;
	m_pPauseButton = nullptr;
	m_pResetButton = nullptr;
	m_pAddAIButton = nullptr;

	m_fWindowWidth = 1280.0f;
	m_fWindowHeight = 720.0f;
	m_bPause = false;
	m_nAICount = 0;
}


GameState::~GameState() {
	if (m_pGrid) {
		delete m_pGrid;
		m_pGrid = nullptr;
	}
	if (m_pAI[0]) {
		delete m_pAI[0];
		m_pAI[0] = nullptr;
	}
	if (m_pAI[1]) {
		delete m_pAI[1];
		m_pAI[1] = nullptr;
	}
	if (m_pAI[2]) {
		delete m_pAI[2];
		m_pAI[2] = nullptr;
	}
	if (m_pAI[3]) {
		delete m_pAI[3];
		m_pAI[3] = nullptr;
	}
	if (m_pAI[4]) {
		delete m_pAI[4];
		m_pAI[4] = nullptr;
	}
	if (m_pAI[5]) {
		delete m_pAI[5];
		m_pAI[5] = nullptr;
	}
	if (m_pAI[6]) {
		delete m_pAI[6];
		m_pAI[6] = nullptr;
	}
	if (m_pAI[7]) {
		delete m_pAI[7];
		m_pAI[7] = nullptr;
	}
	if (m_pAI[8]) {
		delete m_pAI[8];
		m_pAI[8] = nullptr;
	}
	if (m_pAI[9]) {
		delete m_pAI[9];
		m_pAI[9] = nullptr;
	}
	m_nAICount = 0;
	if (m_pPauseButton) {
		delete m_pPauseButton;
		m_pPauseButton = nullptr;
	}
	if (m_pResetButton) {
		delete m_pResetButton;
		m_pResetButton = nullptr;
	}
	if (m_pAddAIButton) {
		delete m_pAddAIButton;
		m_pAddAIButton = nullptr;
	}
}

void GameState::Enter() {
	m_pGrid = new Grid(25, 12);
	m_pAI[0] = new AI(m_pGrid);
	m_nAICount = 0;
	m_pPauseButton = new Button("Pause", m_fWindowWidth / 2.0f, m_fWindowHeight - 55.0f, 320, 85, 204, 0, 0);
	m_pResetButton = new Button("Reset", m_fWindowWidth / 1.4f, m_fWindowHeight - 55.0f, 100, 85, 204, 0, 0);
	m_pAddAIButton = new Button("Add AI", m_fWindowWidth / 1.25f, m_fWindowHeight - 55.0f, 100, 85, 204, 0, 0);
}

bool GameState::Update(float deltaTime, StateMachine* pStateMachine) {
	m_pStateMachine = pStateMachine;

	if (m_bPause == false) {

		m_pAI[0]->Update(deltaTime);
		if (m_pAI[1] != nullptr)
			m_pAI[1]->Update(deltaTime);
		if (m_pAI[2] != nullptr)
			m_pAI[2]->Update(deltaTime);
		if (m_pAI[3] != nullptr)
			m_pAI[3]->Update(deltaTime);
		if (m_pAI[4] != nullptr)
			m_pAI[4]->Update(deltaTime);
		if (m_pAI[5] != nullptr)
			m_pAI[5]->Update(deltaTime);
		if (m_pAI[6] != nullptr)
			m_pAI[6]->Update(deltaTime);
		if (m_pAI[7] != nullptr)
			m_pAI[7]->Update(deltaTime);
		if (m_pAI[8] != nullptr)
			m_pAI[8]->Update(deltaTime);
		if (m_pAI[9] != nullptr)
			m_pAI[9]->Update(deltaTime);
		
		if (m_pPauseButton->Update())
			m_bPause = true;
	}
	else {
		if (m_pPauseButton->Update())
			m_bPause = false;
	}

	if (m_pResetButton->Update()) {
		m_pStateMachine->ChangeState(ESTATE_GAME);
	}
	
	if (m_pAddAIButton->Update()) {
		if (m_nAICount < 10) {
			m_nAICount++;
			for (int i = m_nAICount; i < m_nAICount + 1; ++i) {
				m_pAI[i] = new AI(m_pGrid);

			}
		}
	}

	m_pGrid->Update(deltaTime);

	return false;
}

void GameState::Draw(aie::Renderer2D* renderer) {
	m_pGrid->Draw(renderer);
	m_pAI[0]->Draw(renderer);
	if (m_pAI[1] != nullptr)
		m_pAI[1]->Draw(renderer);
	if (m_pAI[2] != nullptr)
		m_pAI[2]->Draw(renderer);
	if (m_pAI[3] != nullptr)
		m_pAI[3]->Draw(renderer);
	if (m_pAI[4] != nullptr)
		m_pAI[4]->Draw(renderer);
	if (m_pAI[5] != nullptr)
		m_pAI[5]->Draw(renderer);
	if (m_pAI[6] != nullptr)
		m_pAI[6]->Draw(renderer);
	if (m_pAI[7] != nullptr)
		m_pAI[7]->Draw(renderer);
	if (m_pAI[8] != nullptr)
		m_pAI[8]->Draw(renderer);
	if (m_pAI[9] != nullptr)
		m_pAI[9]->Draw(renderer);

	m_pPauseButton->Draw(renderer);
	m_pResetButton->Draw(renderer);
	m_pAddAIButton->Draw(renderer);
}

void GameState::Exit() {
	if (m_pGrid) {
		delete m_pGrid;
		m_pGrid = nullptr;
	}
	if (m_pAI[0]) {
		delete m_pAI[0];
		m_pAI[0] = nullptr;
	}
	if (m_pAI[1]) {
		delete m_pAI[1];
		m_pAI[1] = nullptr;
	}
	if (m_pAI[2]) {
		delete m_pAI[2];
		m_pAI[2] = nullptr;
	}
	if (m_pAI[3]) {
		delete m_pAI[3];
		m_pAI[3] = nullptr;
	}
	if (m_pAI[4]) {
		delete m_pAI[4];
		m_pAI[4] = nullptr;
	}
	if (m_pAI[5]) {
		delete m_pAI[5];
		m_pAI[5] = nullptr;
	}
	if (m_pAI[6]) {
		delete m_pAI[6];
		m_pAI[6] = nullptr;
	}
	if (m_pAI[7]) {
		delete m_pAI[7];
		m_pAI[7] = nullptr;
	}
	if (m_pAI[8]) {
		delete m_pAI[8];
		m_pAI[8] = nullptr;
	}
	if (m_pAI[9]) {
		delete m_pAI[9];
		m_pAI[9] = nullptr;
	}
	m_nAICount = 0;
	if (m_pPauseButton) {
		delete m_pPauseButton;
		m_pPauseButton = nullptr;
	}
	if (m_pResetButton) {
		delete m_pResetButton;
		m_pResetButton = nullptr;
	}
	if (m_pAddAIButton) {
		delete m_pAddAIButton;
		m_pAddAIButton = nullptr;
	}
}