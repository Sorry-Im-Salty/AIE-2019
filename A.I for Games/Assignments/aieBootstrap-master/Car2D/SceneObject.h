#pragma once
#include <vector>
#include "Renderer2D.h"
#include "Matrix3.h"


class SceneObject {
public:
	SceneObject();
	virtual ~SceneObject();

	const Matrix3& getLocalTransform() const;
	const Matrix3& getGlobalTransform() const;

	void setPosition(float x, float y);
	void setRotate(float radians);
	void setScale(float width, float height);
	void translate(float x, float y);
	void rotate(float radians);
	void scale(float width, float height);

protected:
	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;
};

