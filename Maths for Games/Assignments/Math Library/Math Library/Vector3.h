#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	float operator[](int index) const;
	float& operator[](int index);
	Vector3 operator + (const Vector3& other) const;
	Vector3& operator -= (const Vector3& other);
	Vector3 operator * (float scalar) const;
	Vector3& operator = (const Vector3& other);



	union
	{
		struct
		{
			float x, y, z;
		};
		float data[3];
	};

private:

};