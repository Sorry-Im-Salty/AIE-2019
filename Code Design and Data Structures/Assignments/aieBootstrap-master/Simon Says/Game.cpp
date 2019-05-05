#include "Game.h"

Game::Game(float x, float y, float width, float height)
{
	// loads the font
	m_font = new aie::Font("./font/consolas.ttf", 32);

	// loads the testures
	m_arrowRight = new aie::Texture("./textures/arrow_right.png");
	m_arrowLeft = new aie::Texture("./textures/arrow_left.png");
	m_arrowUp = new aie::Texture("./textures/arrow_up.png");
	m_arrowDown = new aie::Texture("./textures/arrow_down.png");


	// stores location, width and height
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
}

Game::~Game()
{
	delete m_font;
	delete m_arrowRight;
	delete m_arrowLeft;
	delete m_arrowUp;
	delete m_arrowDown;
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