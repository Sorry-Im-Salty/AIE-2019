#include "Matrix4.h"

Matrix4::Matrix4() {

}

Matrix4::Matrix4(float xAxis, float yAxis, float zAxis, float wAxis) {

}

Vector4& Matrix4::operator [] (int index) {
	return axis[index];
}

const Vector4& Matrix4::operator [] (int index) const {
	return axis[index];
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