#pragma once
#ifndef _VECTOR_3_ 
#define _VECTOR_3_
#include <cmath>
class vector_3
{
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float data[3];
	};

	//vector_2();
	vector_3(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f);

	float& operator[] (const int a_index);

	operator float* ();

	operator const float* () const;

	vector_3 operator+(const vector_3& a_rhs) const;
	vector_3 operator-(const vector_3& a_rhs) const;
	vector_3 operator*(const float a_rhs) const;
	vector_3 operator/(const float a_rhs) const;

	vector_3& operator+=(const vector_3& a_rhs);
	vector_3& operator-=(const vector_3& a_rhs);
	vector_3& operator*=(const float a_rhs);
	vector_3& operator/=(const float a_rhs);
	vector_3& operator= (const vector_3& rhs);

	vector_3 cross(const vector_3& a_vector_3) const;

	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	vector_3 normalised();

	float dot(const vector_3& a_vector_3) const;
};

vector_3 operator*(const float a_lhs, const vector_3& a_rhs);

#endif
