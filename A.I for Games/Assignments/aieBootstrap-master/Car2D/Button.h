#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "Input.h"

class Button {
public:
	Button(const char* buttonText, float x, float y, float width, float height, float r, float g, float b);
	~Button();

	void Draw(aie::Renderer2D* renderer, float width, float height);
	bool Update();

private:
	aie::Font* m_font;
	char m_kButtonText[64];

	// position, width and height
	float m_fPosX;
	float m_fPosY;
	float m_fWidth;
	float m_fHeight;
	float m_fColourRed;
	float m_fColourGreen;
	float m_fColourBlue;

};

