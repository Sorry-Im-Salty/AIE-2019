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
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_fontBold = new aie::Font("./font/consolas_bold.ttf", 72);
	return true;
}

void Simon_SaysApp::shutdown() {

	delete m_font;
	delete m_fontBold;
	delete m_arrowRight;
	delete m_arrowLeft;
	delete m_arrowUp;
	delete m_2dRenderer;
}

void Simon_SaysApp::update(float deltaTime) {

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
	// black outline
	m_2dRenderer->setRenderColour(0, 0, 0);
	// left box
	m_2dRenderer->drawBox(getWindowWidth() / 3, getWindowHeight() / 3, 350, 100);
	// right box
	m_2dRenderer->drawBox(getWindowWidth() / 1.5f, getWindowHeight() / 3, 350, 100);
	// grey interior
	m_2dRenderer->setRenderColour(0.9f, 0.9f, 0.9f);
	m_2dRenderer->drawBox(getWindowWidth() / 3, getWindowHeight() / 3, 335, 85);
	m_2dRenderer->drawBox(getWindowWidth() / 1.5f, getWindowHeight() / 3, 335, 85);
	// text - drawText(Font* font, const char* text, float xPos, float yPos, float depth = 0.0f);
	m_2dRenderer->setRenderColour(0.1f, 0.9f, 0.1f);
	m_2dRenderer->drawText(m_font, "Play", getWindowWidth() / 3.3f, getWindowHeight() / 3.1f);
	m_2dRenderer->setRenderColour(0.9f, 0.2f, 0.2f);
	m_2dRenderer->drawText(m_font, "Quit", getWindowWidth() / 1.57f, getWindowHeight() / 3.1f);
	m_2dRenderer->drawText(m_fontBold, "Simon Says!", getWindowWidth()/ 3.1f, getWindowHeight() / 1.2f);
	// logo - drawSprite(Texture* texture, float xPos, float yPos, float width = 0.0f, float height = 0.0f, float rotation = 0.0f, float depth = 0.0f, float xOrigin = 0.5f, float yOrigin = 0.5f);
	m_2dRenderer->setRenderColour(1, 1, 1);
	m_2dRenderer->drawSprite(m_arrowRight, getWindowWidth() / 1.75f, getWindowHeight() / 1.5f, 100, 100);
	m_2dRenderer->drawSprite(m_arrowLeft, getWindowWidth() / 2.25f, getWindowHeight() / 1.5f, 100, 100, 3.15f);
	m_2dRenderer->drawSprite(m_arrowUp, getWindowWidth() / 2, getWindowHeight() / 1.3f, 100, 100, 360);
	/*==============================================================================================================================*/

	// output some text
	m_2dRenderer->setRenderColour(1, 0, 0);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}