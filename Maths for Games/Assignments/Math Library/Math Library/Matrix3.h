#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float xAxis, float yAxis, float zAxis);
	Vector3& operator [](int index);
	const Vector3& operator [](int index) const;
	operator float*();

	Matrix3 operator * (const Matrix3& other) const;
	Vector3 operator * (const Vector3& v) const;

	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
		float data[3][3];
	};

};