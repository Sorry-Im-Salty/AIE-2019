#include "Matrix3.h"

Matrix3::Matrix3() {
	data[0][0] =	1; 0; 0;
					0; 1; 0;
					0; 0; 1;
}

Matrix3::Matrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9) {
	data[0][0] =	m1; m2; m3;
					m4; m5; m6;
					m7; m8; m9;
}

Vector3& Matrix3::operator [] (int index) {
	return axis[index];
}

const Vector3& Matrix3::operator [] (int index) const {
	return axis[index];
}

Matrix3::operator float* () {
	return &data[0][0];
}

// Rotate X
Matrix3 Matrix3::setRotateX(float x) {
	data[0][0] =	1; 0; 0;
					0; cos(x); -sin(x);
					0; sin(x); cos(x);
}

// Rotate Y
Matrix3 Matrix3::setRotateY(float y) {
	data[0][0] =	cos(y); 0; sin(y);
					0; 1; 0;
					-sin(y); 0; cos(y);
}

// Rotate Z
Matrix3 Matrix3::setRotateZ(float z) {
	data[0][0] =	cos(z); -sin(z); 0;
					sin(z); cos(z); 0;
					0; 0; 1;
}

// Matrix * Matrix
Matrix3 Matrix3::operator * (const Matrix3& other) const {
	Matrix3 result;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
								data[1][r] * other.data[c][1] +
								data[2][r] * other.data[c][2];
		}
	}
	return result;
}

// Matrix * Vector
Vector3 Matrix3::operator * (const Vector3& v) const {
	Vector3 result;

	for (int r = 0; r < 3; ++r) {
		result[r] = data[0][r] * v[0] +
					data[1][r] * v[1] +
					data[2][r] * v[2];
	}
	return result;
}