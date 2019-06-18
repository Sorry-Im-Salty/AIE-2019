#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	float operator [](int index) const;
	float& operator [](int index);
	operator float*();

	float magnitude() const;
	void normalise();

	float dot(const Vector3& other) const;
	Vector3 cross(const Vector3& other) const;

	Vector3 operator + (const Vector3& other) const;
	Vector3 operator - (const Vector3& other) const;
	Vector3 operator * (float scalar) const;

	union {
		struct {
			float x, y, z;
		};
		float data[3];
	};
};

// Float * Vector
static Vector3 operator * (float a, const Vector3& b) {
	return Vector3(a * b.x, a * b.y, a * b.z);
}

