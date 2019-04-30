#include "Simon_SaysApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Simon_SaysApp::Simon_SaysApp() {

}

Simon_SaysApp::~Simon_SaysApp() {

}

bool Simon_SaysApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_arrowRight = new aie::Texture("./textures/arrow_right.png");
	m_arrowLeft = new aie::Texture("./textures/arrow_left.png");
	m_arrowUp = new aie::Texture("./textures/arrow_up.png");
	m_arrowDown = new aie::Texture("./textures/arrow_down.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_fontBold = new aie::Font("./font/consolas_bold.ttf", 72);
	m_playButton = new MenuButton("Play", getWindowWidth() / 3.3f, getWindowHeight() / 3.1f, 120, 50);
	m_quitButton = new MenuButton("Quit", getWindowWidth() / 1.57f, getWindowHeight() / 3.1f, 120, 50);

	m_score = 0;
	m_timer = 0;

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
	delete m_2dRenderer;
}

void Simon_SaysApp::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Simon_SaysApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	// background
	m_2dRenderer->drawBox(getWindowWidth() / 2, getWindowHeight() / 2, getWindowWidth(), getWindowHeight());
	
	/* Start Menu ===================================================================================================================*/
	// play and exit buttons - drawBox(float xPos, float yPos, float width, float height, float rotation = 0.0f, float depth = 0.0f);
	m_playButton->Draw(m_2dRenderer);
	m_quitButton->Draw(m_2dRenderer);
	// black outline
	m_2dRenderer->setRenderColour(0, 0, 0);
	// left box
	m_2dRenderer->drawBox(getWindowWidth() / 3, getWindowHeight() / 3, 350, 100);
	// right box
	m_2dRenderer->drawBox(getWindowWidth() / 1.5f, getWindowHeight() / 3, 350, 100);
	// grey interior
	//m_2dRenderer->setRenderColour(0.9f, 0.9f, 0.9f);
	//m_2dRenderer->drawBox(getWindowWidth() / 3, getWindowHeight() / 3, 335, 85);
	//m_2dRenderer->drawBox(getWindowWidth() / 1.5f, getWindowHeight() / 3, 335, 85);
	// text - drawText(Font* font, const char* text, float xPos, float yPos, float depth = 0.0f);
	//m_2dRenderer->setRenderColour(0.1f, 0.9f, 0.1f);
	//m_2dRenderer->drawText(m_font, "Play", getWindowWidth() / 3.3f, getWindowHeight() / 3.1f);
	//m_2dRenderer->setRenderColour(0.9f, 0.2f, 0.2f);
	//m_2dRenderer->drawText(m_font, "Quit", getWindowWidth() / 1.57f, getWindowHeight() / 3.1f);
	//->drawText(m_fontBold, "Simon Says!", getWindowWidth()/ 3.1f, getWindowHeight() / 1.2f);
	// logo - drawSprite(Texture* texture, float xPos, float yPos, float width = 0.0f, float height = 0.0f, float rotation = 0.0f, float depth = 0.0f, float xOrigin = 0.5f, float yOrigin = 0.5f);
	m_2dRenderer->setRenderColour(1, 1, 1);
	m_2dRenderer->drawSprite(m_arrowRight, getWindowWidth() / 1.8f, getWindowHeight() / 1.7f, 100, 100);
	m_2dRenderer->drawSprite(m_arrowLeft, getWindowWidth() / 2.25f, getWindowHeight() / 1.7f, 100, 100, 3.15f);
	m_2dRenderer->drawSprite(m_arrowUp, getWindowWidth() / 2, getWindowHeight() / 1.42f, 100, 100, 1.6f);
	m_2dRenderer->drawSprite(m_arrowDown, getWindowWidth() / 2, getWindowHeight() / 2.1f, 100, 100, 4.7f);
	/*==============================================================================================================================*/

	// fps counter and quit
	char fps[32];
	m_2dRenderer->setRenderColour(1, 0, 0);
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}