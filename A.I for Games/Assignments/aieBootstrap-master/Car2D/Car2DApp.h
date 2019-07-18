#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Car2DApp : public aie::Application {
public:

	Car2DApp();
	virtual ~Car2DApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};