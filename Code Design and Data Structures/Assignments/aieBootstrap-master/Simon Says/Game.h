#pragma once
#include "Renderer2D.h"
#include "Font.h"

class Game
{
public:
	Game(float x, float y, float width, float height);
	~Game();

	void Draw(aie::Renderer2D* renderer, float width, float height);
	void GameOver(aie::Renderer2D* renderer);
private:
	// font
	aie::Font* m_font;
	aie::Font* m_fontBig;

	// position, width and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
};