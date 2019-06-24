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

	m_tank.Load("./textures/tank.png");
	m_turret.Load("./textures/gunTurret.png");
	
	m_tank.addChild(&m_turret);

	m_tank.setPosition(getWindowWidth() / 2.0f, getWindowHeight() / 2.0f);

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
	if (input->isKeyDown(aie::INPUT_KEY_A))
		m_tank.rotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_D))
		m_tank.rotate(-deltaTime);

	// Movement
	if (input->isKeyDown(aie::INPUT_KEY_W)) {
		auto facing = m_tank.getLocalTransform()[1] * deltaTime * 100;
		m_tank.translate(facing.x, facing.y);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S)) {
		auto facing = m_tank.getLocalTransform()[1] * deltaTime * -100;
		m_tank.translate(facing.x, facing.y);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Draw tank
	m_tank.draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}