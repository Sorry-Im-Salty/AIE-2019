#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_background.Load("./textures/background.png");

	m_background.setPosition(getWindowWidth() / 2.0f, getWindowHeight() / 2.0f);

	m_tank.initialize();

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_tank.update(deltaTime);
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();


	// Rotate left and right
	if (input->isKeyDown(aie::INPUT_KEY_A)) {
		m_tank.tankRotate(deltaTime);
		//m_tank.tankForward(deltaTime, -0);
	}
		
	if (input->isKeyDown(aie::INPUT_KEY_D)) {
		m_tank.tankRotate(-deltaTime);
		//m_tank.tankForward(deltaTime, -0);
	}

	// Movement
	//if (input->isKeyDown(aie::INPUT_KEY_W)) {
	//	m_tank.tankForward(1, deltaTime);
	//}
	//if (input->isKeyDown(aie::INPUT_KEY_S)) {
	//	m_tank.tankForward(-1, deltaTime);
	//}

	// Rotation of turret
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_tank.turretRotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_tank.turretRotate(-deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Draw background
	m_background.draw(m_2dRenderer);

	// Draw tank
	m_tank.draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}