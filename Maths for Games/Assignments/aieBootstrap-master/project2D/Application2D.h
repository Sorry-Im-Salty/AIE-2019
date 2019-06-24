#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "SpriteObject.h"
#include "SceneObject.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer	=	nullptr;
	aie::Font*			m_font			=	nullptr;

	SpriteObject		m_tank;
	SpriteObject		m_turret;
	SpriteObject		m_background;

	float				m_timer			=	0;
};