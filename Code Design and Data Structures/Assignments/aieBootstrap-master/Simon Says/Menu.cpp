#include "Menu.h"

Menu::Menu(float x, float y, float width, float height)
{
	// loads the font
	m_fontBold = new aie::Font("./font/consolas_bold.ttf", 72);

	// loads the textures
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

Menu::~Menu()
{
	delete m_fontBold;
	delete m_arrowRight;
	delete m_arrowLeft;
	delete m_arrowUp;
	delete m_arrowDown;
}

void Menu::Draw(aie::Renderer2D* renderer, float width, float height)
{
	// background
	renderer->setRenderColour(1, 1, 1);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(0.9f, 0.2f, 0.2f);
	renderer->drawText(m_fontBold, "Simon Says!", m_width / 3.1f, m_height / 1.2f);
	
	// button background
	renderer->setRenderColour(0, 0, 0);
	renderer->drawBox(m_width / 3, m_height / 3, 350, 100);
	renderer->drawBox(m_width / 1.5f, m_height / 3, 350, 100);

	// logo
	renderer->setRenderColour(1, 1, 1);
	renderer->drawSprite(m_arrowRight, m_width / 1.8f, m_height / 1.7f, 100, 100);
	renderer->drawSprite(m_arrowLeft, m_width / 2.25f, m_height / 1.7f, 100, 100, 3.15f);
	renderer->drawSprite(m_arrowUp, m_width / 2, m_height / 1.42f, 100, 100, 1.6f);
	renderer->drawSprite(m_arrowDown, m_width / 2, m_height / 2.1f, 100, 100, 4.7f);
}