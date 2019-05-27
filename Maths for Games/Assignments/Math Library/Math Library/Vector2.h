#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	float operator[](int index) const;
	float& operator[](int index);

	float magnitude() const;
	float magnitudeSqr() const;
	float distance(const Vector2& other) const;


	Vector2 operator + (const Vector2& other) const;
	
	Vector2 operator * (float scalar) const;
	Vector2 operator / (float scalar) const;
	Vector2& operator = (const Vector2& other);
	Vector2& operator -= (const Vector2& other);
	Vector2& operator += (const Vector2& other);


	union
	{
		struct
		{
			float x, y;
		};
		float data[2];
	};

private:
	
};