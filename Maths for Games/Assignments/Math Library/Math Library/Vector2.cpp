#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
{

}

Vector2::Vector2(float x, float y)
{

}

float Vector2::operator [] (int index) const 
{ 
	return data[index]; 
}

float& Vector2::operator [] (int index) 
{ 
	return data[index]; 
}

float Vector2::magnitude() const 
{ 
	return sqrt(x*x + y * y);
}
float Vector2::magnitudeSqr() const 
{ 
	return (x * x + y * y); 
}

float Vector2::distance(const Vector2& other) const
{
	float diffX = x - other.x;
	float diffY = y - other.y;
	return sqrt(diffX * diffX + diffY * diffY);
}


Vector2 Vector2::operator + (const Vector2& other) const
{
	return  Vector2( x + other.x, y + other.y );
}



Vector2 Vector2::operator * (float scalar) const
{
	return Vector2( x * scalar, y * scalar );
}

Vector2 Vector2::operator / (float scalar) const
{
	return Vector2( x / scalar, y / scalar);
}

Vector2& Vector2::operator = (const Vector2& other)
{
	x = other.x; y = other.y;
	return *this;
}

Vector2& Vector2::operator -= (const Vector2& other)
{
	x -= other.x; y -= other.y;
	return *this;
}

Vector2& Vector2::operator += (const Vector2& other)
{
	x += other.x; y += other.y;
	return *this;
}