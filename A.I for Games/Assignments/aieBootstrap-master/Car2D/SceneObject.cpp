#include "SceneObject.h"

SceneObject::SceneObject() {

}


SceneObject::~SceneObject() {

}

const Matrix3& SceneObject::getLocalTransform() const {
	return m_localTransform;
}

const Matrix3& SceneObject::getGlobalTransform() const {
	return m_globalTransform;
}

void SceneObject::setPosition(float x, float y) {
	m_localTransform[2] = { x, y, 1 };
	updateTransform();
}

void SceneObject::setRotate(float radians) {
	m_localTransform.setRotateZ(radians);
	updateTransform();
}

void SceneObject::setScale(float width, float height) {
	m_localTransform.setScaled(width, height, 1);
	updateTransform();
}

void SceneObject::translate(float x, float y) {
	Matrix3 transMatrix;
	transMatrix.translate(x, y);

	m_localTransform = m_localTransform * transMatrix;
	updateTransform();
}

void SceneObject::rotate(float radians) {
	Matrix3 rotMatrix;
	rotMatrix.setRotateZ(radians);

	m_localTransform = m_localTransform * rotMatrix;
	updateTransform();
}

void SceneObject::scale(float width, float height) {
	Matrix3 scaleMatrix;
	scaleMatrix.scale(width, height, 1);

	m_localTransform = m_localTransform * scaleMatrix;
	updateTransform();
}
