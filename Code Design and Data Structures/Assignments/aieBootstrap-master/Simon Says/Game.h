#pragma once
#include "Renderer2D.h"
#include "Font.h"

class Game
{
public:
	Game(float x, float y, float width, float height);
	~Game();

	void Draw(aie::Renderer2D* renderer, float width, float height);
private:
	// font
	aie::Font* m_font;

	// position, width and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
};