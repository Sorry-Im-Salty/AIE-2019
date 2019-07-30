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

	m_pStateMachine = new StateMachine();

	m_timer = 0;
	setVSync(false);

	return true;
}

void Car2DApp::shutdown() {

	delete m_pStateMachine;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Car2DApp::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (m_pStateMachine->Update(deltaTime))
		quit();
}

void Car2DApp::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pStateMachine->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->setRenderColour(0.0f, 0.0f, 1.0f);
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}