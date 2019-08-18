#include "SceneObject.h"

SceneObject::SceneObject() {

}

SceneObject::~SceneObject() {
	if (m_parent != nullptr)
		m_parent->removeChild(this);

	for (auto child : m_children)			
		child->m_parent = nullptr;
}

SceneObject* SceneObject::getParent() const {
	return m_parent;
}

size_t SceneObject::childCount() const {
	return m_children.size();
}

SceneObject* SceneObject::getChild(unsigned int index) const {
	return m_children[index];
}

void SceneObject::addChild(SceneObject* child) {
	assert(child->m_parent == nullptr);
	child->m_parent = this;
	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject* child) {
	auto iter = std::find(m_children.begin(), m_children.end(), child);

	if (iter != m_children.end()) {
		m_children.erase(iter);
		child->m_parent = nullptr;
	}
}

void SceneObject::update(float deltaTime) {
	onUpdate(deltaTime);

	for (auto child : m_children)
		child->update(deltaTime);
}

void SceneObject::draw(aie::Renderer2D* renderer) {
	onDraw(renderer);

	for (auto child : m_children)
		child->draw(renderer);
}

void SceneObject::onUpdate(float deltaTime) {

}

void SceneObject::onDraw(aie::Renderer2D* renderer) {

}

const Matrix3& SceneObject::getLocalTransform() const {
	return m_localTransform;
}

const Matrix3& SceneObject::getGlobalTransform() const {
	return m_globalTransform;
}

void SceneObject::updateTransform() {
	if (m_parent != nullptr)
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	else
		m_globalTransform = m_localTransform;

	for (auto child : m_children)
		child->updateTransform();
}

void SceneObject::setPosition(float x, float y) {
	m_localTransform[2] = { x, y, 1 };
	updateTransform();
}

Vector3 SceneObject::getPosition() {
	return m_localTransform[2];
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