#include "SpriteObject.h"
#pragma once


class Tank : public SceneObject{
public:
	Tank();
	~Tank();

	void initialize();
	void turretRotate(float deltaTime);
	void tankRotate(float deltaTime);
	void tankForward(int forward);
	void draw(aie::Renderer2D* renderer);
	void update(float deltaTime);

private:
	SpriteObject m_tank;
	SpriteObject m_turret;
};

