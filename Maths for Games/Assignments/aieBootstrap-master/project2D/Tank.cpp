#include "Tank.h"
#include "Renderer2D.h"

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

void Tank::tankForward(int forward) {
	//auto facing = m_tank.getLocalTransform()[1] * deltaTime * 100;
	m_tank.translate(0, forward);
}

void Tank::draw(aie::Renderer2D* renderer) {
	m_tank.draw(renderer);
}

void Tank::update(float deltaTime) {
	m_tank.update(deltaTime);
}