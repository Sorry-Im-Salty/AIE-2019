#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	float operator [](int index) const;
	float& operator [](int index);
	operator float*();

	float magnitude() const;
	void normalise();
	
	float dot(const Vector2& other) const;

	Vector2 operator + (const Vector2& other) const;
	Vector2 operator - (const Vector2& other) const;
	Vector2 operator * (float scalar) const;

	union {
		struct {
			float x, y;
		};
		float data[2];
	};
};

// Float * Vector
Vector2 operator * (const Vector2& a, const Vector2& b) {
	return Vector2(a.x * b.x, a.y * b.y);
}
