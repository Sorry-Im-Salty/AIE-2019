#include "Arrow.h"

Arrow::Arrow(aie::Texture* texture, float x, float y, float width, float height, float rotation)
{
	// stores position, width and height
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
	m_texture = texture;
	m_rotation = rotation;
}

Arrow::~Arrow()
{
}

void Arrow::Draw(aie::Renderer2D* renderer, float width, float height)
{
	renderer->setRenderColour(1, 1, 1);
	renderer->drawSprite(m_texture, m_posX, m_posY, m_width, m_height, m_rotation);
}