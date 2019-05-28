#include "Matrix3.h"

Matrix3::Matrix3() {

}

Matrix3::Matrix3(float xAxis, float yAxis, float zAxis) {

}

Vector3& Matrix3::operator [] (int index) {
	return axis[index];
}

const Vector3& Matrix3::operator [] (int index) const {
	return axis[index];
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