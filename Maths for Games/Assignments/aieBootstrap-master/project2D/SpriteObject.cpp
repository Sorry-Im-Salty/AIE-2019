#include "SpriteObject.h"
#include "Texture.h"
#include "Renderer2D.h"


SpriteObject::SpriteObject() {

}

SpriteObject::SpriteObject(const char* filename) {
	Load(filename);
}


SpriteObject::~SpriteObject() {
	delete m_texture;
}

bool SpriteObject::Load(const char* filename) {
	delete m_texture;
	m_texture = nullptr;
	m_texture = new aie::Texture(filename);
	return m_texture != nullptr;
}

void SpriteObject::Draw(aie::Renderer2D* renderer) {
	renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
}