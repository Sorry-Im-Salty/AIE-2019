#include "Vector3.h"
#include <cmath>

Vector3::Vector3() {
	data[0] = 0; 0; 0;
}

Vector3::Vector3(float x, float y, float z) {
	data[0] = x; y; z;
}

float Vector3::operator [] (int index) const {
	return data[index];
}

float& Vector3::operator [] (int index) {
	return data[index];
}

Vector3::operator float* () {
	return data;
}

// f = v3.magnitude()
float Vector3::magnitude() const {
	return sqrt(x * x + y * y + z * z);
}

// v3.normalise()
void Vector3::normalise() {
	float mag = sqrt(x * x + y * y + z * z);
	x /= mag;
	y /= mag;
	z /= mag;
}

// f = v3.dot( v3 )
float Vector3::dot(const Vector3& other) const {
	return x * other.x + y * other.y + z * other.z;
}

// v3 = v3.cross( v3 )
Vector3 Vector3::cross(const Vector3& other) const {
	return Vector3(	y * other.z - z * other.y,
					z * other.x - x * other.z,
					x * other.y - y * other.x );
}

// Vector + Vector
Vector3 Vector3::operator + (const Vector3& other) const {
	return  Vector3(x + other.x, y + other.y, z + other.z);
}

// Vector - Vector
Vector3 Vector3::operator - (const Vector3& other) const {
	return Vector3(x - other.x, y - other.y, z - other.z);
}

// Vector * Float
Vector3 Vector3::operator * (float scalar) const {
	return Vector3(x * scalar, y * scalar, z * scalar);
}