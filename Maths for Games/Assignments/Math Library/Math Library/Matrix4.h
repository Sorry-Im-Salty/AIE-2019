#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(	float m1, float m2, float m3, float m4,
				float m5, float m6, float m7, float m8,
				float m9, float m10, float m11, float m12,
				float m13, float m14, float m15, float m16	);
	Vector4& operator [](int index);
	const Vector4& operator [](int index) const;
	operator float*();

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