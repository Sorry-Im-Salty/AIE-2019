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
}

void Tank::turretRotate(float deltaTime) {
	m_turret.rotate(deltaTime);
}

void Tank::tankRotate(float deltaTime) {
	m_tank.rotate(deltaTime);
}

void Tank::tankForward(int forward, float deltaTime) {
	//auto facing = m_tank.getLocalTransform()[1] * deltaTime * 100;
	//m_tank.translate(0, forward);
	Vector2 vel;
	float accel = 500;
	float maxAccel = 1000;
	float speed = 100;

	aie::Input* input = aie::Input::getInstance();
	
	while (input->isKeyDown(aie::INPUT_KEY_W)) {
		vel.y += speed;
		speed += accel;
		
		if (speed > maxAccel)
			speed = maxAccel;
	}
	if (vel.y > 0) {
		speed -= accel;
		if (vel.y <= 0) {
			vel.y = 0;
			speed = accel;
		}
	}

	if (input->isKeyDown(aie::INPUT_KEY_S)) {
		vel.y -= speed;
		vel.y += accel;
		if (speed < -maxAccel) {
			speed = maxAccel;
		}
	}
	else if (vel.y < 0) {
		vel.y += speed;
		if (vel.x >= 0) {
			vel.y = 0;
			speed = accel;
		}
	}

	m_tank.translate(0, vel.y * deltaTime);
}

void Tank::draw(aie::Renderer2D* renderer) {
	m_tank.draw(renderer);
}

void Tank::update(float deltaTime) {
	m_tank.update(deltaTime);
	Vector2 vel;
	float accel = 20;
	float maxAccel = 150;
	float speed = 100;

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W)) {
		vel.y += speed;
		speed += accel;

		if (speed > maxAccel)
			speed = maxAccel;
	}
	if (vel.y > 0) {
		speed -= accel;
		if (vel.y <= 0) {
			vel.y = 0;
			speed = accel;
		}
	}

	if (input->isKeyDown(aie::INPUT_KEY_S)) {
		vel.y -= speed;
		vel.y += accel;
		if (speed < -maxAccel) {
			speed = maxAccel;
		}
	}
	else if (vel.y < 0) {
		vel.y += speed;
		if (vel.y >= 0) {
			vel.y = 0;
			speed = accel;
		}
	}

	m_tank.translate(0, vel.y * deltaTime);
}