#pragma once
#ifndef _VECTOR_2_ 
#define _VECTOR_2_
#include <cmath>
//'ere we farkin go
class vector_2
{
public:
	union
	{
		struct
		{
			float x;
			float y;
		};
		float data[2];
	};

	//vector_2();
	vector_2(const float a_x = 0.0f, const float a_y = 0.0f);

	float& operator[] (const int a_index);

	operator float* ();

	operator const float* () const;

	vector_2 operator+(const vector_2& a_rhs) const;
	vector_2 operator-(const vector_2& a_rhs) const;
	vector_2 operator*(const float a_rhs) const;
	vector_2 operator/(const float a_rhs) const;

	vector_2& operator+=(const vector_2& a_rhs);
	vector_2& operator-=(const vector_2& a_rhs);
	vector_2& operator*=(const float a_rhs);
	vector_2& operator/=(const float a_rhs);

	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	vector_2 normalised();

	float dot(const vector_2& a_vector_2) const;
};

vector_2 operator*(const float a_lhs, const vector_2& a_rhs);

#endif