#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "Texture.h"

class Game
{
public:
	Game(float x, float y, float width, float height);
	~Game();

	void Draw(aie::Renderer2D* renderer, float width, float height);
private:
	// font
	aie::Font* m_font;

	// textures
	aie::Texture* m_arrowRight;
	aie::Texture* m_arrowLeft;
	aie::Texture* m_arrowUp;
	aie::Texture* m_arrowDown;

	// position, width and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;

};