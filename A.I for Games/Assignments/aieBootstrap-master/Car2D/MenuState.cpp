#include "MenuState.h"
#include "Font.h"
#include "StateMachine.h"
#include "Texture.h"
#include "Application.h"

MenuState::MenuState() {
	m_PlayButton = nullptr;
	m_QuitButton = nullptr;
	m_Font = nullptr;

	m_fWindowWidth = 1280.0f;
	m_fWindowHeight = 720.0f;
}


MenuState::~MenuState(){
	if (m_PlayButton) {
		delete m_PlayButton;
		m_PlayButton = nullptr;
	}
	if (m_QuitButton) {
		delete m_QuitButton;
		m_QuitButton = nullptr;
	}
	if (m_Font) {
		delete m_Font;
		m_Font = nullptr;
	}
}

void MenuState::Enter() {
	m_PlayButton = new Button("Play", m_fWindowWidth / 3.0f, m_fWindowHeight / 3.0f, 320, 85, 0, 255, 0);
	m_QuitButton = new Button("Quit", m_fWindowWidth / 1.5f, m_fWindowHeight / 3.0f, 320, 85, 255, 0, 0);
	m_Font = new aie::Font("./font/consolas_bold.ttf", 72);

}

bool MenuState::Update(float deltaTime, StateMachine* pStateMachine) {
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

void MenuState::Draw(aie::Renderer2D* renderer) {
	// Background
	renderer->setRenderColour(255, 255, 255, 200);
	renderer->drawBox(m_fWindowWidth / 2.0f, m_fWindowHeight / 2.0f, m_fWindowWidth, m_fWindowHeight);

	// Button Background
	renderer->setRenderColour(0, 0, 0, 255);
	renderer->drawBox(m_fWindowWidth / 3.0f, m_fWindowHeight / 3.0f, 350, 100);
	renderer->drawBox(m_fWindowWidth / 1.5f, m_fWindowHeight / 3.0f, 350, 100);

	renderer->setRenderColour(255, 255, 255);
	m_PlayButton->Draw(renderer);
	m_QuitButton->Draw(renderer);

	// Text
	renderer->drawText(m_Font, "Car2D!", m_fWindowWidth / 2.4f, m_fWindowHeight / 1.4f);
}

void MenuState::Exit() {
	if (m_PlayButton) {
		delete m_PlayButton;
		m_PlayButton = nullptr;
	}
	if (m_QuitButton) {
		delete m_QuitButton;
		m_QuitButton = nullptr;
	}
	if (m_Font) {
		delete m_Font;
		m_Font = nullptr;
	}
}