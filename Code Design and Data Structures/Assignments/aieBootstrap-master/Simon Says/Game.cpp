#include "Game.h"

Game::Game(float x, float y, float width, float height)
{
	// loads the font
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_fontBig = new aie::Font("./font/consolas.ttf", 72);

	// stores location, width and height
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
}

Game::~Game()
{
	delete m_font;
	delete m_fontBig;
}

void Game::Draw(aie::Renderer2D* renderer, float width, float height)
{
	// background
	renderer->setRenderColour(1, 1, 1);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	
	// exit message
	renderer->setRenderColour(1, 0, 0);
	renderer->drawText(m_font, "Press 'Escape' to return to Main Menu", 0, 5);
}

void Game::GameOver(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(1, 1, 1);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);

	renderer->setRenderColour(1, 0, 0);
	renderer->drawText(m_fontBig, "Game Over!", 1280 / 2 - 150, 720 / 2);
}
