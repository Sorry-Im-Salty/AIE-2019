#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "Texture.h"
#include "Application.h"

class Menu
{
public:
	Menu(float x, float y, float width, float height);
	~Menu();

	void Draw(aie::Renderer2D* renderer, float width, float height);
private:
	// font
	aie::Font* m_fontBold;

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