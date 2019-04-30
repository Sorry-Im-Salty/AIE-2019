#include "MenuButton.h"
#include <string.h>
MenuButton::MenuButton(const char* buttonText, float x, float y, float width, float height)
{
	// stores copy of the text
	strcpy_s(m_buttonText, 64, buttonText);

	// loads the font
	m_font = new aie::Font("./font/consolas.ttf", 24);

	// stores position, width and height
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
}

MenuButton::~MenuButton()
{
	delete m_font;
}

void MenuButton::Draw(aie::Renderer2D* renderer)
{
	// black outline
	renderer->setRenderColour(0, 0, 0);
	// left box
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	// right box
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	// grey interior
	renderer->setRenderColour(0.9f, 0.9f, 0.9f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);

	// calculating centered text
	float textWidth = m_font->getStringWidth(m_buttonText);
	float textHeight = m_font->getStringHeight(m_buttonText);
	float centredPosX = m_posX - (textWidth * 0.5f) + 2;
	float centredPosY = m_posY - (textHeight * 0.5f) + 5;

	// draw text
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
}