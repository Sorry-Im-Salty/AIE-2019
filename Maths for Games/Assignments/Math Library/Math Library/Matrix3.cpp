#include "Matrix3.h"

Matrix3::Matrix3() {

}

Matrix3::Matrix3(float x, float y, float z) {

}

Vector3& Matrix3::operator [] (int index) {
	return axis[index];
}

const Vector3& Matrix3::operator [] (int index) const {
	return axis[index];
}