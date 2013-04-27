/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Matrix3.h
/*	Class: Matrix3
/*	Definition: A 3x3 matrix
/*  Functionality: Used in many locations throughout the engine
******************************************************************/

#ifndef _EY3MATRIX_H_
#define _EY3MATRIX_H_

#include "Ey3Vector3.h"

namespace Ey3
{

class Ey3Export Matrix3
{
public:
		float d[3][3];

public:
	Matrix3(){}
	Matrix3(const float m[3][3])
	{
		memcpy(d,m,9*sizeof(float));
	}
	Matrix3(const Matrix3& m)
	{
		memcpy(d,m.d,9*sizeof(float));
	}
	Matrix3& operator=(const Matrix3& m)
	{
		memcpy(d,m.d,9*sizeof(float));
		return *this;
	}
	
	Matrix3(const Vector3& a, float rad)
	{
		fromAxisAngle(a,rad);
	}

	Matrix3 (const Vector3& a, const Vector3& b, const Vector3& c)
	{//COLUMN ORDER
		d[0][0] = a.x;
		d[0][1] = b.x;
		d[0][2] = c.x;
		d[1][0] = a.y;
		d[1][1] = b.y;
		d[1][2] = c.y;
		d[2][0] = a.z;
		d[2][1] = b.z;
		d[2][2] = c.z;
	}

	Matrix3 (float d00, float d01, float d02,
                    float d10, float d11, float d12,
                    float d20, float d21, float d22)
		{
			d[0][0] = d00;
			d[0][1] = d01;
			d[0][2] = d02;
			d[1][0] = d10;
			d[1][1] = d11;
			d[1][2] = d12;
			d[2][0] = d20;
			d[2][1] = d21;
			d[2][2] = d22;
		}

	float* operator[] (size_t row) 
	{
		return (float*)d[row];
	}
	
	const float* operator[] (size_t row) const
	{
		return (float*)d[row];
	}

	Matrix3 operator-();
	
	bool operator==(const Matrix3& a) const;
	bool operator!=(const Matrix3& a) const;
	Matrix3 operator+(const Matrix3& a) const;
	Matrix3& operator+=(const Matrix3& a);
	Matrix3 operator-(const Matrix3& a) const;
	Matrix3& operator-=(const Matrix3& a);
	Matrix3 operator*(const Matrix3 &a) const;
	Matrix3& operator*=(const Matrix3 &a);
	
	// matrix * vector 3x3 * 3x1 = 3x1
	Vector3 operator* (const Vector3& v) const;

	Matrix3 operator*(float a);
	Matrix3& operator *=(float a);
	Matrix3 operator+(float a);
	Matrix3& operator+=(float a);
	Matrix3 operator-(float a);
	Matrix3& operator-=(float a);
	
	Vector3 getColumn(uint col);
	void setColumn(Vector3& col, uint index);
	void setAxes(Vector3& x, Vector3& y, Vector3& z);

	Matrix3& fromAxisAngle(const Vector3& a, float rad);

	Matrix3 transpose() const;
	float det() const;
	bool inverse(Matrix3& inv, float tolerance = Ey3::EPSILON) const;
	void ortho();
	
	void transposeSelf();

	static const Matrix3 ZERO;
	static const Matrix3 IDENTITY;

};

};

#endif
