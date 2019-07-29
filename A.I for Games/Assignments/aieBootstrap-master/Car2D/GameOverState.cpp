#include "GameOverState.h"
#include "StateMachine.h"

GameOverState::GameOverState() {
	m_font = nullptr;
	m_QuitButton = nullptr;
	m_PlayButton = nullptr;
	m_fWindowWidth = 1280.0f;
	m_fWindowHeight = 720.0f;
}


GameOverState::~GameOverState() {
	if (m_font) {
		delete m_font;
		m_font = nullptr;
	}
	if (m_QuitButton) {
		delete m_QuitButton;
		m_QuitButton = nullptr;
	}
	if (m_PlayButton) {
		delete m_PlayButton;
		m_PlayButton = nullptr;
	}
}

void GameOverState::Enter() {
	m_PlayButton = new Button("Try Again", m_fWindowWidth / 3.0f, m_fWindowHeight / 3.0f, 255, 85, 0, 255, 0);
	m_QuitButton = new Button("Quit", m_fWindowWidth / 1.5f, m_fWindowHeight / 3.0f, 255, 85, 0, 255, 0);
	m_font = new aie::Font("./font/consolas_bold.ttf", 32);
}

bool GameOverState::Update(float deltaTime, StateMachine* pStateMachine) {
	m_pStateMachine = pStateMachine;
	if (m_PlayButton->Update()) {
		m_pStateMachine->ChangeState(ESTATE_GAME);
		return false;
	}
	else if (m_QuitButton->Update())
		return true;
	else
		return false;
}

void GameOverState::Draw(aie::Renderer2D* renderer) {

}

void GameOverState::Exit() {
	if (m_font) {
		delete m_font;
		m_font = nullptr;
	}
	if (m_QuitButton) {
		delete m_QuitButton;
		m_QuitButton = nullptr;
	}
	if (m_PlayButton) {
		delete m_PlayButton;
		m_PlayButton = nullptr;
	}
}