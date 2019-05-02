#pragma once
#include "Renderer2D.h"
#include "MenuButton.h"
#include "Menu.h"

class Simon_SaysApp : public aie::Application {
public:

	Simon_SaysApp();
	virtual ~Simon_SaysApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_arrowRight;
	aie::Texture*		m_arrowLeft;
	aie::Texture*		m_arrowUp;
	aie::Texture*		m_arrowDown;
	aie::Font*			m_font;
	aie::Font*			m_fontBold;
	MenuButton*			m_playButton;
	MenuButton*			m_quitButton;
	Menu*				m_menu;

	float m_timer;
	int m_score;
};