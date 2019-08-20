#include "Tank.h"
#include "Renderer2D.h"
#include "Input.h"

Tank::Tank() {
}

Tank::~Tank() {
}

void Tank::initialize() {
	m_tank.Load("./textures/tank.png");
	m_turret.Load("./textures/gunTurret.png");

	m_tank.addChild(&m_turret);
	m_tank.setPosition(840 / 2.0f, 650 / 2.0f);
	m_vel[0] = 0;
	m_vel[1] = 0;
}

void Tank::turretRotate(float deltaTime) {
	m_turret.rotate(deltaTime);
}

void Tank::tankRotate(float deltaTime) {
	m_tank.rotate(deltaTime);
}

void Tank::draw(aie::Renderer2D* renderer) {
	m_tank.draw(renderer);
}

void Tank::update(float deltaTime) {
	m_tank.update(deltaTime);
	float speed = 100;

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W)) {
		m_vel.y += speed * deltaTime;
	}
	else if (m_vel.y > 0) {
		m_vel.y -= speed * deltaTime;
		if (m_vel.y <= 0) {
			m_vel.y = 0;
		}
	}

	if (input->isKeyDown(aie::INPUT_KEY_S)) {
		m_vel.y -= speed * deltaTime;
	}
	else if (m_vel.y < 0) {
		m_vel.y += speed * deltaTime;
		if (m_vel.y >= 0) {
			m_vel.y = 0;
		}
	}

	m_tank.translate(0, m_vel.y * deltaTime);
}