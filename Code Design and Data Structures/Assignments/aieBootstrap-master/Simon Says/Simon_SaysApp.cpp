#include "Simon_SaysApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <assert.h>

Simon_SaysApp::Simon_SaysApp() {

}

Simon_SaysApp::~Simon_SaysApp() {

}

bool Simon_SaysApp::startup() {
	
	setVSync(true);

	m_2dRenderer = new aie::Renderer2D();

	m_arrowRight = new aie::Texture("./textures/arrow_right.png");
	m_arrowLeft = new aie::Texture("./textures/arrow_left.png");
	m_arrowUp = new aie::Texture("./textures/arrow_up.png");
	m_arrowDown = new aie::Texture("./textures/arrow_down.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_fontBold = new aie::Font("./font/consolas_bold.ttf", 72);
	m_playButton = new MenuButton("Play", 1280 / 3, 720 / 3, 335, 85, 0, 1, 0);
	m_quitButton = new MenuButton("Quit", 1280 / 1.5f, 720 / 3, 335, 85, 1, 0, 0);
	m_menu = new Menu(1280 / 2, 720 / 2, 1280, 720);
	m_game = new Game(1280 / 2, 720 / 2, 1280, 720);

	m_score;
	m_timer;
	m_menuState;

	return true;
}

void Simon_SaysApp::shutdown() {

	delete m_font;
	delete m_fontBold;
	delete m_arrowRight;
	delete m_arrowLeft;
	delete m_arrowUp;
	delete m_arrowDown;
	delete m_playButton;
	delete m_quitButton;
	delete m_menu;
	delete m_game;
	delete m_2dRenderer;
}

void Simon_SaysApp::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// quit button
	if (m_quitButton->Update())
		m_gameOver = true;

	// return to menu
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		m_menuState = true;
	}
}

void Simon_SaysApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	// start menu
	if (m_menuState == true)
	{
		m_menu->Draw(m_2dRenderer, 1280 / 2, 720 / 2);

		// play and exit buttons
		m_playButton->Draw(m_2dRenderer, 1280, 720);
		m_quitButton->Draw(m_2dRenderer, 1280, 720);

		if (m_playButton->Update())
		{
			m_menuState = false;
		}

	}
	else if (m_menuState == false)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
	}
	
	

	

	// fps counter
	char fps[32];
	m_2dRenderer->setRenderColour(1, 0, 0);
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}