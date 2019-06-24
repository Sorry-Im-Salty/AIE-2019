#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "SpriteObject.h"

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

	SpriteObject		m_tank			=	nullptr;
	SpriteObject		m_turret		=	nullptr;

	float				m_timer			=	0;
};