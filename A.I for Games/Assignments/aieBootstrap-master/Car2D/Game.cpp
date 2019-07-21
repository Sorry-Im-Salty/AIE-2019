#include "Game.h"

Game::Game(aie::Renderer2D* renderer, float xPos, float yPos, float Width, float Height) {
	m_eCurrentState = EGAMESTATE_MENU;
	m_2dRenderer = renderer;

	m_fPosX = xPos;
	m_fPosY = yPos;
	m_fWidth = Width;
	m_fHeight = Height;

	m_fontBold = new aie::Font("./font/consolas_bold.ttf", 72);
}

Game::~Game() {
		delete m_fontBold;
}

void Game::Update() {
	switch (m_eCurrentState) {
	case EGAMESTATE_MENU:
		Menu(m_2dRenderer);
		break;

	case EGAMESTATE_CONTROLS:
		Controls(m_2dRenderer);
		break;

	case EGAMESTATE_GAME:
		GamePlay(m_2dRenderer);
		break;
	}
}

void Game::Menu(aie::Renderer2D* renderer) {
	// background
	renderer->setRenderColour(1, 1, 1);
	renderer->drawBox(m_fPosX, m_fPosY, m_fWidth, m_fHeight);
	renderer->setRenderColour(0.9f, 0.2f, 0.2f);
	renderer->drawText(m_fontBold, "Car2D!", m_fWidth / 3.1f, m_fHeight / 1.2f);

	// button background
	renderer->setRenderColour(0, 0, 0);
	renderer->drawBox(m_fWidth / 3, m_fHeight / 3, 350, 100);
	renderer->drawBox(m_fWidth / 1.5f, m_fHeight / 3, 350, 100);
}

void Game::Controls(aie::Renderer2D* renderer) {

}

void Game::GamePlay(aie::Renderer2D* renderer) {

}