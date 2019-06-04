#include "Vector4.h"
#include <cmath>

Vector4::Vector4() {
	data[0] = 0; 0; 0; 0;
}

Vector4::Vector4(float x, float y, float z, float w) {
	data[0] = x; y; z; w;
}

float Vector4::operator [] (int index) const {
	return data[index];
}

float& Vector4::operator [] (int index) {
	return data[index];
}

Vector4::operator float* () {
	return data;
}

// f = v4.magnitude()
float Vector4::magnitude() const {
	return sqrt(x * x + y * y + z * z + w * w);
}

// v4.normalise()
void Vector4::normalise() {
	float mag = sqrt(x * x + y * y + z * z + w * w);
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
}

// f = v4.dot( v4 )
float Vector4::dot(const Vector4& other) const {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

// v4 = v4.cross( v4 )
Vector4 Vector4::cross(const Vector4& other) const {
	return Vector4( y * other.z - z * other.y,
					z * other.x - x * other.z,
					x * other.y - y * other.x,
					w * 0);
}

// Vector + Vector
Vector4 Vector4::operator + (const Vector4& other) const {
	return  Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

// Vector - Vector
Vector4 Vector4::operator - (const Vector4& other) const {
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

// Vector * Float
Vector4 Vector4::operator * (float scalar) const {
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}