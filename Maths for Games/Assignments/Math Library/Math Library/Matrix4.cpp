#include "Matrix4.h"

Matrix4::Matrix4() {
	data[0][0] = 1; data[0][1] = 0; data[0][2] = 0; data[0][3] = 0;
	data[1][0] = 0; data[1][1] = 1; data[1][2] = 0; data[1][3] = 0;
	data[2][0] = 0; data[2][1] = 0; data[2][2] = 1; data[2][3] = 0;
	data[3][0] = 0; data[3][1] = 0; data[3][2] = 0; data[3][3] = 1;
}

Matrix4::Matrix4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16) {
	data[0][0] = m1; data[0][1] = m2; data[0][2] = m3; data[0][3] = m4;
	data[1][0] = m5; data[1][1] = m6; data[1][2] = m7; data[1][3] = m8;
	data[2][0] = m9; data[2][1] = m10; data[2][2] = m11; data[2][3] = m12;
	data[3][0] = m13; data[3][1] = m14; data[3][2] = m15; data[3][3] = m16;
}

Vector4& Matrix4::operator [] (int index) {
	return axis[index];
}

const Vector4& Matrix4::operator [] (int index) const {
	return axis[index];
}

Matrix4::operator float* () {
	return &data[0][0];
}

// Matrix * Matrix
Matrix4 Matrix4::operator * (const Matrix4& other) const {
	Matrix4 result;

	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
								data[1][r] * other.data[c][1] +
								data[2][r] * other.data[c][2] +
								data[3][r] * other.data[c][3];
		}
	}
	return result;
}

// Matrix * Vector
Vector4 Matrix4::operator * (const Vector4& v) const {
	Vector4 result;

	for (int r = 0; r < 4; ++r) {
		result[r] = data[0][r] * v[0] +
					data[1][r] * v[1] +
					data[2][r] * v[2] +
					data[3][r] * v[3];
	}
	return result;
}