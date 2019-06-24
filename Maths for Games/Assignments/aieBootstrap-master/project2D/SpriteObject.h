#pragma once
#include "SceneObject.h"

class SpriteObject : public SceneObject {
public:
	SpriteObject();
	SpriteObject(const char* filename);
	virtual ~SpriteObject();

	bool Load(const char* filename);
	virtual void Draw(aie::Renderer2D* renderer);


protected:
	aie::Texture* m_texture = nullptr;
};

