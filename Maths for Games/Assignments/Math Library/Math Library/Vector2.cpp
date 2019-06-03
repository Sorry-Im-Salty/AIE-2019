#include "Vector2.h"
#include <cmath>

Vector2::Vector2() {

}

Vector2::Vector2(float x, float y) {

}

float Vector2::operator [] (int index) const { 
	return data[index]; 
}

float& Vector2::operator [] (int index) { 
	return data[index]; 
}

Vector2::operator float* () {
	return data;
}

// f = v2.magnitude()
float Vector2::magnitude() const { 
	return sqrt(x*x + y * y);
}

// v2.normalise()
void Vector2::normalise() {
	float mag = sqrt(x * x + y * y);
	x /= mag;
	y /= mag;
}

// f = v2.dot( v2 )
float Vector2::dot(const Vector2& other) const {
	return x * other.x + y * other.y;
}

// Vector + Vector
Vector2 Vector2::operator + (const Vector2& other) const {
	return  Vector2( x + other.x, y + other.y );
}

// Vector - Vector
Vector2 Vector2::operator - (const Vector2& other) const {
	return Vector2( x - other.x, y - other.y );
}

// Vector * Float
Vector2 Vector2::operator * (float scalar) const {
	return Vector2( x * scalar, y * scalar );
}