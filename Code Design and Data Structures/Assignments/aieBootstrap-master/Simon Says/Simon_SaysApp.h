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

	aie::Renderer2D*	m_2dRenderer = nullptr;
	aie::Texture*		m_arrowRight = nullptr;
	aie::Texture*		m_arrowLeft = nullptr;
	aie::Texture*		m_arrowUp = nullptr;
	aie::Texture*		m_arrowDown = nullptr;
	aie::Font*			m_font = nullptr;
	aie::Font*			m_fontBold = nullptr;
	MenuButton*			m_playButton = nullptr;
	MenuButton*			m_quitButton = nullptr;
	Menu*				m_menu = nullptr;

	float m_timer = 0;
	int m_score = 0;
};