#include "SpriteObject.h"
#pragma once


class Tank {
public:
	Tank();
	~Tank();

	void initializeChild(SpriteObject Child);

private:
	SpriteObject m_tank;
	SpriteObject m_turret;
};

