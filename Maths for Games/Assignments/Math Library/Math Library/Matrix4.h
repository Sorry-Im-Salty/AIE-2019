#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float xAxis, float yAxis, float zAxis, float wAxis);
	Vector4& operator [](int index);
	const Vector4& operator [](int index) const;

	Matrix4 operator * (const Matrix4& other) const;
	Vector4 operator * (const Vector4& v) const;

	union {
		struct {
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 wAxis;
		};
		Vector4 axis[4];
		float data[4][4];
	};

};