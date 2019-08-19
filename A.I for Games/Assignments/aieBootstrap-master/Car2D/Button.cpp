#include "Button.h"
#include <string.h>
Button::Button(const char* buttonText, float x, float y, float width, float height)
{
	// stores copy of the text
	strcpy_s(m_kButtonText, 64, buttonText);

	// loads the font
	m_font = new aie::Font("./font/consolas.ttf", 24);

	// stores position, width, height and colour
	m_fPosX = x;
	m_fPosY = y;
	m_fWidth = width;
	m_fHeight = height;
}

Button::~Button()
{
	if (m_font) {
		delete m_font;
		m_font = nullptr;
	}
}

void Button::Draw(aie::Renderer2D* renderer, float r, float g, float b)
{
	// grey interior
	renderer->setRenderColour(0.9f, 0.9f, 0.9f);
	renderer->drawBox(m_fPosX, m_fPosY, m_fWidth, m_fHeight);
	renderer->setRenderColour(r, g, b);

	// calculating centered text
	float textWidth = m_font->getStringWidth(m_kButtonText);
	float textHeight = m_font->getStringHeight(m_kButtonText);
	float centredPosX = m_fPosX - (textWidth * 0.5f) + 2;
	float centredPosY = m_fPosY - (textHeight * 0.5f) + 5;

	// draw text
	renderer->drawText(m_font, m_kButtonText, centredPosX, centredPosY);
}

bool Button::Update()
{
	aie::Input* input = aie::Input::getInstance();

	// gets mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	// calculates the four sides of the button
	float left = m_fPosX - (m_fWidth * 0.5f);
	float right = m_fPosX + (m_fWidth * 0.5f);
	float bottom = m_fPosY - (m_fHeight * 0.5f);
	float top = m_fPosY + (m_fHeight * 0.5f);

	// checks if the mouse is inside of the box
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		// return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}

	return false;
}