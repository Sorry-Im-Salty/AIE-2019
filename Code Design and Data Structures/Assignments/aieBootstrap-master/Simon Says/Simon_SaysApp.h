#pragma once
#include "Renderer2D.h"
#include "MenuButton.h"
#include "Menu.h"
#include "Game.h"
#include "Arrow.h"

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
	aie::Texture*		m_tArrowRight = nullptr;
	aie::Texture*		m_tArrowLeft = nullptr;
	aie::Texture*		m_tArrowUp = nullptr;
	aie::Texture*		m_tArrowDown = nullptr;
	aie::Font*			m_font = nullptr;
	aie::Font*			m_fontBold = nullptr;
	MenuButton*			m_playButton = nullptr;
	MenuButton*			m_quitButton = nullptr;
	Menu*				m_menu = nullptr;
	Game*				m_game = nullptr;
	Arrow*				m_arrowRight = nullptr;
	Arrow*				m_arrowLeft = nullptr;
	Arrow*				m_arrowUp = nullptr;
	Arrow*				m_arrowDown = nullptr;

	float m_timer = 0;
	int m_score = 0;
	bool m_menuState = true;
	bool m_arrowUpState = false;
	bool m_arrowUpBuffer = false;
	bool m_arrowDownState = false;
	bool m_arrowDownBuffer = false;
	bool m_arrowLeftState = false;
	bool m_arrowLeftBuffer = false;
	bool m_arrowRightState = false;
	bool m_arrowRightBuffer = false;
	bool m_gameOverState = false;
};