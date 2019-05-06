#pragma once
#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"


class Arrow
{
public:
	Arrow(aie::Texture* texture, float x, float y, float width, float height, float rotation);
	~Arrow();

	void Draw(aie::Renderer2D* renderer, float width, float height);
	int arrowSelect();

private:
	// position, width and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
	float m_rotation;
	aie::Texture* m_texture;
};