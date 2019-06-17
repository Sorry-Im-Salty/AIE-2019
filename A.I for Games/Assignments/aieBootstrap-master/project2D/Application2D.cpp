#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Node.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_pGrid = new Grid(50, 50);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete m_pGrid;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	Vector2 v2MousePos;
	v2MousePos.x = input->getMouseX();
	v2MousePos.y = input->getMouseY();

	// Pathfinding
	if (input->isMouseButtonDown(0)) {
		Node* pMouseMode = m_pGrid->GetNodeByPos(v2MousePos);
		if (pMouseMode)
			pMouseMode->m_bBlocked = true;
	}

	if (input->isMouseButtonDown(1)) {
		Node* pMouseMode = m_pGrid->GetNodeByPos(v2MousePos);
		if (pMouseMode)
			pMouseMode->m_bBlocked = false;
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_S)) {
		m_v2StartPos = v2MousePos;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_E)) {
		m_v2EndPos = v2MousePos;
	}

	m_pGrid->FindPath(m_v2StartPos, m_v2EndPos, m_Path);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	m_pGrid->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(0.0f, 1.0f, 1.0f);
	m_2dRenderer->drawCircle(m_v2StartPos.x, m_v2StartPos.y, 10.0f);
	m_2dRenderer->drawCircle(m_v2EndPos.x, m_v2EndPos.y, 10.0f);
	for (int i = 1; i < m_Path.size(); ++i) {
		m_2dRenderer->drawLine(m_Path[i - 1].x, m_Path[i - 1].y, m_Path[i].x, m_Path[i].y, 5.0f);
	}
	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}