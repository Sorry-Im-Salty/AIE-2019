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

	
	m_tArrowRight = new aie::Texture("./textures/arrow_right.png");
	m_tArrowLeft = new aie::Texture("./textures/arrow_left.png");
	m_tArrowUp = new aie::Texture("./textures/arrow_up.png");
	m_tArrowDown = new aie::Texture("./textures/arrow_down.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_fontBold = new aie::Font("./font/consolas_bold.ttf", 72);
	m_playButton = new MenuButton("Play", 1280 / 3, 720 / 3, 335, 85, 0, 1, 0);
	m_quitButton = new MenuButton("Quit", 1280 / 1.5f, 720 / 3, 335, 85, 1, 0, 0);
	m_menu = new Menu(1280 / 2, 720 / 2, 1280, 720);
	m_game = new Game(1280 / 2, 720 / 2, 1280, 720);
	m_arrowRight = new Arrow(m_tArrowRight, 1280 / 2, 720 / 2, 200, 200, 0);
	m_arrowLeft = new Arrow(m_tArrowLeft, 1280 / 2, 720 / 2, 200, 200, 3.15f);
	m_arrowUp = new Arrow(m_tArrowUp, 1280 / 2, 720 / 2, 200, 200, 1.6f);
	m_arrowDown = new Arrow(m_tArrowDown, 1280 / 2, 720 / 2, 200, 200, 4.7f);

	assert(m_tArrowRight != nullptr);
	assert(m_tArrowLeft != nullptr);
	assert(m_tArrowUp != nullptr);
	assert(m_tArrowDown != nullptr);
	assert(m_font != nullptr);
	assert(m_fontBold != nullptr);
	assert(m_playButton != nullptr);
	assert(m_quitButton != nullptr);
	assert(m_menu != nullptr);
	assert(m_game != nullptr);
	assert(m_arrowRight != nullptr);
	assert(m_arrowLeft != nullptr);
	assert(m_arrowUp != nullptr);
	assert(m_arrowDown != nullptr);

	m_score;
	m_timer;
	m_menuState;
	m_arrowUpState;
	m_arrowUpBuffer;
	m_arrowDownState;
	m_arrowDownBuffer;
	m_arrowLeftState;
	m_arrowLeftBuffer;
	m_arrowRightState;
	m_arrowRightBuffer;
	m_gameOverState;

	return true;
}

void Simon_SaysApp::shutdown() {

	delete m_font;
	delete m_fontBold;
	delete m_tArrowRight;
	delete m_tArrowLeft;
	delete m_tArrowUp;
	delete m_tArrowDown;
	delete m_playButton;
	delete m_quitButton;
	delete m_menu;
	delete m_game;
	delete m_arrowRight;
	delete m_arrowLeft;
	delete m_arrowUp;
	delete m_arrowDown;
	delete m_2dRenderer;
}

void Simon_SaysApp::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// quit button
	if (m_quitButton->Update())
		quit();

	// return to menu
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		m_menuState = true;
		m_arrowUpState = false;
		m_arrowUpBuffer = false;
		m_arrowDownState = false;
		m_arrowDownBuffer = false;
		m_arrowRightState = false;
		m_arrowRightBuffer = false;
		m_arrowLeftState = false;
		m_arrowLeftBuffer = false;
		m_gameOverState = false;
		m_score = 0;
	}

	// up arrow state
	if (m_arrowUpState == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_UP))
		{
			m_score++;
			m_arrowUpState = false;
			m_arrowUpBuffer = true;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_LEFT))
		{
			m_gameOverState = true;
			m_arrowUpState = false;
		}
	}
	
	// up arrow buffer
	if (m_arrowUpBuffer == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_SPACE))
		{
			m_arrowUpBuffer = false;
			m_arrowRightState = true;
		}
	}

	// right arrow state
	if (m_arrowRightState == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_RIGHT) )
		{
			m_score++;
			m_arrowRightState = false;
			m_arrowRightBuffer = true;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_LEFT))
		{
			m_gameOverState = true;
			m_arrowRightState = false;
		}
	}

	// right arrow buffer
	if (m_arrowRightBuffer == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_SPACE))
		{
			m_arrowRightBuffer = false;
			m_arrowLeftState = true;
		}
	}

	// left arrow state
	if (m_arrowLeftState == true)
	{
		if (input->isKeyUp(aie::INPUT_KEY_RIGHT))
		{
			if (input->isKeyDown(aie::INPUT_KEY_LEFT))
			{
				m_score++;
				m_arrowLeftState = false;
				m_arrowLeftBuffer = true;
			}
			else if (input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_RIGHT))
			{
				m_gameOverState = true;
				m_arrowLeftState = false;
			}
		}
	}

	// left arrow buffer
	if (m_arrowLeftBuffer == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_SPACE))
		{
			m_arrowLeftBuffer = false;
			m_arrowDownState = true;
		}
	}

	// down arrow state
	if (m_arrowDownState == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		{
			m_score++;
			m_arrowDownState = false;
			m_arrowDownBuffer = true;

		}
		else if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_RIGHT))
		{
			m_gameOverState = true;
			m_arrowDownState = false;
		}
	}

	// down arrow buffer
	if (m_arrowDownBuffer == true)
	{
		if (input->isKeyDown(aie::INPUT_KEY_SPACE))
		{
			m_arrowDownBuffer = false;
			m_arrowUpState = true;
		}
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
			m_arrowUpState = true;
			m_menuState = false;
		}
	}

	if (m_gameOverState == true)
	{
		m_game->GameOver(m_2dRenderer);
	}

	if (m_arrowUpState == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowUp->Draw(m_2dRenderer, 1280, 720);
	}
	if (m_arrowUpBuffer == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowUp->Draw(m_2dRenderer, 1280, 720);
		m_2dRenderer->setRenderColour(1, 0, 0);
		m_2dRenderer->drawText(m_font, "Press 'Space' To Continue", 1280 / 2 - 180, 200);
	}

	if (m_arrowRightState == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowRight->Draw(m_2dRenderer, 1280, 720);
	}
	if (m_arrowRightBuffer == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowRight->Draw(m_2dRenderer, 1280, 720);
		m_2dRenderer->setRenderColour(1, 0, 0);
		m_2dRenderer->drawText(m_font, "Press 'Space' To Continue", 1280 / 2 - 180, 200);
	}

	if (m_arrowLeftState == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowLeft->Draw(m_2dRenderer, 1280, 720);
	}
	if (m_arrowLeftBuffer == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowLeft->Draw(m_2dRenderer, 1280, 720);
		m_2dRenderer->setRenderColour(1, 0, 0);
		m_2dRenderer->drawText(m_font, "Press 'Space' To Continue", 1280 / 2 - 180, 200);
	}

	if (m_arrowDownState == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowDown->Draw(m_2dRenderer, 1280, 720);
	}
	if (m_arrowDownBuffer == true)
	{
		m_game->Draw(m_2dRenderer, 1280 / 2, 720 / 2);
		m_arrowDown->Draw(m_2dRenderer, 1280, 720);
		m_2dRenderer->setRenderColour(1, 0, 0);
		m_2dRenderer->drawText(m_font, "Press 'Space' To Continue", 1280 / 2 - 180, 200);
	}

	// fps counter
	char fps[32];
	m_2dRenderer->setRenderColour(1, 0, 0);
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// score
	char score[32];
	m_2dRenderer->setRenderColour(1, 0, 0);
	sprintf_s(score, 32, "Score: %i", m_score);
	m_2dRenderer->drawText(m_font, score, 1280 - 200, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}