#include "Car2DApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Node.h"

Car2DApp::Car2DApp() {

}

Car2DApp::~Car2DApp() {

}

bool Car2DApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_pGrid = new Grid(25, 12);
	m_pAI = new AI(m_pGrid);
	m_pAI2 = new AI(m_pGrid);

	m_pGame = new Game(m_2dRenderer, getWindowWidth() / 2, getWindowHeight() / 2, 1280.0f, 720.0f);
	m_timer = 0;
	setVSync(false);

	return true;
}

void Car2DApp::shutdown() {

	delete m_pGame;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete m_pGrid;
	delete m_pAI;
	delete m_pAI2;
}

void Car2DApp::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_2dRenderer->begin();
	m_pGame->Update();
	m_2dRenderer->end();


	m_pAI->Update(deltaTime);
	m_pAI2->Update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Car2DApp::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pGrid->Draw(m_2dRenderer);
	m_pAI->Draw(m_2dRenderer);
	m_pAI2->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->setRenderColour(0.0f, 0.0f, 1.0f);
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}