#pragma once
#include "Vector3.h"
#include <math.h>

class Matrix3
{
public:
	Matrix3();
	Matrix3(	float m1, float m2, float m3,
				float m4, float m5, float m6, 
				float m7, float m8, float m9	);
	Vector3& operator [](int index);
	const Vector3& operator [](int index) const;
	operator float*();

	Matrix3 setRotateX(float x);
	Matrix3 setRotateY(float y);
	Matrix3 setRotateZ(float z);

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