#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float xAxis, float yAxis, float zAxis);
	Vector3& operator [](int index);
	const Vector3& operator [](int index) const;

	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
	};

};