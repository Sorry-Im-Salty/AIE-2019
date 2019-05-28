#pragma once
class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	float operator [](int index) const;
	float& operator [](int index);

	float magnitude() const;
	void normalise();

	float dot(const Vector4& other) const;
	Vector4 cross(const Vector4& other) const;

	Vector4 operator + (const Vector4& other) const;
	Vector4 operator - (const Vector4& other) const;
	Vector4 operator * (float scalar) const;

	union {
		struct {
			float x, y, z, w;
		};
		float data[4];
	};
};

// Float * Vector
Vector4 operator * (const Vector4& a, const Vector4& b) {
	return Vector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
