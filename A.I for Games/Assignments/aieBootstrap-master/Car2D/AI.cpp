#include "AI.h"



AI::AI(Grid* pGrid) {
	// Load sprite
	m_texture = new aie::Texture("./textures/car.png");

	// Set position
	m_v2Position.x = 600;
	m_v2Position.y = 400;

	m_pGrid = pGrid;
	m_eCurrentState = EAISTATE_WANDER;
}


AI::~AI() {
	// Delete the sprite
	delete m_texture;
	m_texture = nullptr;
}

void AI::Update(float deltaTime) {
	// Update input
	aie::Input* input = aie::Input::getInstance();

	switch (m_eCurrentState) {
	case EAISTATE_WANDER:
		Wander(deltaTime);
		break;

	case EAISTATE_CHASE:
		Chase(deltaTime);
		break;

	case EAISTATE_FLEE:
		Flee(deltaTime);
		break;
	}

	// Move AI
	Vector2 v2MousePos;
	v2MousePos.x = (float)input->getMouseX();
	v2MousePos.y = (float)input->getMouseY();

	// Pathfinding

	if (input->wasKeyPressed(aie::INPUT_KEY_S)) {
		m_v2StartPos = v2MousePos;
		m_bRecalculate = true;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_E)) {
		m_v2EndPos = v2MousePos;
		m_bRecalculate = true;
	}

	if (m_bRecalculate) {
		if (m_pGrid->FindPath(m_v2Position, m_v2EndPos, m_Path)) {
			m_bRecalculate = false;
		}
	}

	if (m_Path.size() > 1) {
		Vector2 dest = m_Path[1];

		// Move AI
		Vector2 direction = dest - m_v2Position;
		direction.normalise();
		m_v2Position = m_v2Position + direction * 100 * deltaTime;

		m_fRotation = atan2f(direction.y, direction.x) - 1.5700f;

		// Check if close to wall
		if ((dest - m_v2Position).magnitude() < 10)
			m_bRecalculate = true;
	}
	else
		m_v2EndPos = Vector2((float)(rand() % 1000), (float)(rand() % 500));
}

void AI::Draw(aie::Renderer2D* renderer) {
	renderer->setRenderColour(1.0f, 1.0f, 1.0f);
	renderer->drawSprite(m_texture, m_v2Position.x, m_v2Position.y, 0.0f, 0.0f, m_fRotation);
}

void AI::drawTracers(aie::Renderer2D* renderer) {
	renderer->setRenderColour(0.0f, 1.0f, 1.0f);
	renderer->drawCircle(m_v2StartPos.x, m_v2StartPos.y, 10.0f);
	renderer->drawCircle(m_v2EndPos.x, m_v2EndPos.y, 10.0f);

	for (int i = 1; i < m_Path.size(); ++i) {
		renderer->drawLine(m_Path[i - 1].x, m_Path[i - 1].y, m_Path[i].x, m_Path[i].y, 5.0f);
	}
	renderer->setRenderColour(1.0f, 1.0f, 1.0f);
}

void AI::Wander(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	Vector2 v2MousePos;
	v2MousePos.x = (float)input->getMouseX();
	v2MousePos.y = (float)input->getMouseY();

	// Calculate new destination if completed path
	if (m_Path.size() <= 1)
		m_v2EndPos = Vector2((float)(rand() % 1000), (float)(rand() % 500));

	float fDistance = (m_v2Position - v2MousePos).magnitude();
	if (fDistance < 300.0f)
		m_eCurrentState = EAISTATE_CHASE;

	if (input->wasMouseButtonPressed(2))
		m_eCurrentState = EAISTATE_FLEE;
}

void AI::Chase(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	Vector2 v2MousePos;
	v2MousePos.x = (float)input->getMouseX();
	v2MousePos.y = (float)input->getMouseY();

	m_v2EndPos = v2MousePos;

	float fDistance = (m_v2Position - v2MousePos).magnitude();

	if (fDistance >= 300.0f)
		m_eCurrentState = EAISTATE_WANDER;

	if (fDistance > 50 && m_Path.size() == 0)
		m_eCurrentState = EAISTATE_WANDER;

	if (input->wasMouseButtonPressed(2))
		m_eCurrentState = EAISTATE_FLEE;
}

void AI::Flee(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	Vector2 v2MousePos;
	v2MousePos.x = (float)input->getMouseX();
	v2MousePos.y = (float)input->getMouseY();

	Vector2 vDir = m_v2Position - v2MousePos;
	vDir.normalise();

	m_v2EndPos = m_v2Position + vDir * 200.0f;

	float fDistance = (m_v2Position - v2MousePos).magnitude();
	if (fDistance >= 500.0f)
		m_eCurrentState = EAISTATE_WANDER;

	if (m_Path.size() == 0)
		m_eCurrentState = EAISTATE_WANDER;
}