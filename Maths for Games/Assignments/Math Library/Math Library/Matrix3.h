#pragma once

class Matrix3
{
public:
	Matrix3();
	Matrix3(float x, float y, float z);

	union {
		struct {
			Matrix3 xAxis;
			Matrix3 yAxis;
			Matrix3 zAxis;
		};
		Matrix3 axis[3];
		float data[3][3];
	};



private:

};