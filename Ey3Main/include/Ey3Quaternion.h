/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Quaternion.h
/*	Class: Quaternion
/*	Definition: Mathematical orientation representation
/*  Functionality: Used to represent orientation
******************************************************************/

#ifndef _EY3QUATERNION_H_
#define _EY3QUATERNION_H_

#include "Ey3Math.h"
#include "Ey3Vector3.h"
#include "Ey3Matrix3.h"

namespace Ey3
{

class Ey3Export Quaternion 
{
public:
	float x,y,z,w;
	
	Quaternion() {}
	Quaternion(float xx, float yy, float zz, float ww) : 
				x(xx),y(yy),z(zz),w(ww) {}
	
	Quaternion(const Quaternion& q)
		: x(q.x),y(q.y),z(q.z),w(q.w)
	{
	}
	Quaternion& operator=(const Quaternion& q)
	{
		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;
		return *this;
	}
	Quaternion(const Matrix3& rot)
	{
		this->convertRotationMatrix(rot);
	}
	Quaternion(const Vector3& axis, float angle) //CONVERT TO RADIAN
	{
		w = cosf(angle/2); //TODO: REWRITE WHEN ADD MATH FUNCTIONS
		float a = sinf(angle/2);
		Vector3 axiscp = axis * a; //constness
		x = axiscp.x;
		y = axiscp.y;
		z = axiscp.z;
	}

	operator const float* () const;
	operator float* ();
	float operator[] (int i) const;
	float& operator[](int i);

	Quaternion operator+(const Quaternion& q) const;
	Quaternion operator-(const Quaternion& q) const;
	Quaternion& operator+=(const Quaternion& q);
	Quaternion& operator-=(const Quaternion& q);

	Quaternion operator*(float a) const;
	Quaternion operator/(float a) const;
	Quaternion& operator*=(float a);
	Quaternion& operator/=(float a);

	Quaternion operator*(const Quaternion& quat) const;

	Vector3 rotate(const Vector3& vec) const;

	Quaternion conjugate() const;
	Quaternion inverse() const;

	void convertRotationMatrix(const Matrix3& rot);
	Matrix3 toRotationMatrix() const;
	void fromAxisAngle(const Vector3& axis, Radian& angle)
	{
		w = cosf((angle/Radian(2))._value); //TODO: REWRITE WHEN ADD MATH FUNCTIONS
		float a = sinf((angle/Radian(2))._value);  //TODO: POtential problem with division
		Vector3 axiscp =axis * a; //constness
		x = axiscp.x;
		y = axiscp.y;
		z = axiscp.z;
	}
	void toAxisAngle(Vector3& axis, Radian& angle) const;

	float dotProduct(const Quaternion& quat) const;

	Quaternion& slerp(float T, const Quaternion& Q0, const Quaternion& Q1);

	Quaternion& slerpExtraSpins(float T, const Quaternion& Q0, const Quaternion& Q1, int extraSpins);

	Quaternion log() const;
	Quaternion exp() const;

	Quaternion& intermediate(const Quaternion& Q0, const Quaternion& Q1, const Quaternion& Q2);

	Quaternion& squad(float T, const Quaternion& Q0, const Quaternion& A0, const Quaternion& A1, const Quaternion& Q1);


	static const Quaternion ZERO;
	static const Quaternion IDENTITY;




};

};

#endif