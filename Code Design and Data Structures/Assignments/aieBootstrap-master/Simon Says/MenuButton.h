#pragma once
#include "Renderer2D.h"
#include "Font.h"

class MenuButton
{
public:
	MenuButton(const char* buttonText, float x, float y, float width, float height);
	~MenuButton();

	void Draw(aie::Renderer2D* renderer);
private:
	// font and text
	aie::Font* m_font;
	char m_buttonText[64];

	// position, width and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
};