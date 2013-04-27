/****************************************************************/
/*  File: Ey3Vector3.h
/*	Class: Vector3
/*  Definition: A general all-purpose Vector class for 
/*	3-Dimensional Vectors
******************************************************************/

#ifndef _EY3VECTOR3_H_
#define _EY3VECTOR3_H_

#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export Vector3
{
public:

	float x,y,z;

	Vector3() {}
	Vector3(const Vector3 &a) : x(a.x), y(a.y) , z(a.z) {}
	Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}

	Vector3& operator=(const Vector3 &a)
	{
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	bool operator==(const Vector3 &a) const 
	{
		return (x==a.x && y == a.y && z == a.z);
	}

	bool operator!=(const Vector3 &a) const
	{
		return (x!=a.x || y != a.y || z != a.z);
	}
	
	float operator[](const size_t i) const
	{
		switch(i)
		{
			case 0:	return x;
			case 1: return y;
			case 2: return z;
		}
		return nanF;
	}

	float operator[](const size_t i)
	{
		switch(i)
		{
			case 0:	return x;
			case 1: return y;
			case 2: return z;
		}
		return nanF;
	}

	Vector3 operator -() const
	{
		return Vector3(-x,-y,-z);
	}

	Vector3 operator +(const Vector3 &a) const
	{
		return Vector3(x+a.x,y+a.y,z+a.z);
	}

	Vector3 operator -(const Vector3 &a) const
	{
		return Vector3(x-a.x,y-a.y,z-a.z);
	}

	Vector3& operator+=(const Vector3 &a)
	{
		x+=a.x; y+=a.y; z+=a.z;
		return *this;
	}
	
	Vector3& operator-=(const Vector3 &a)
	{
		x-=a.x;y-=a.y;z-=a.z;
		return *this;
	}

	Vector3 operator *(float a) const
	{
		return Vector3(x*a,y*a,z*a);
	}

	Vector3 operator /(float a) const
	{
		float rep = 1.0f/a;
		return Vector3(x*rep,y*rep,z*rep);
	}

	Vector3& operator *=(float a) 
	{
		x*=a;y*=a;z*=a;
		return *this;
	}

	Vector3& operator /=(float a) 
	{
		float rep = 1.0f/a;
		x*=rep;y*=rep;z*=rep;
		return *this;
	}

	void zero()
	{
		x=0;y=0;z=0;
	}

	void normalize()
	{
		float mag = x*x + y*y + z*z;
		if(mag > 0.0f)
		{
			float r = 1.0f/sqrtf(mag);
			x*=r;y*=r;z*=r;
		}
	}

	float magSqrd() const
	{
		return x*x + y*y + z*z;
	}

	float mag() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	float operator*(const Vector3 &a) const
	{
		return x*a.x + y*a.y + z*a.z;
	}

	inline Vector3& operator *= ( const Vector3& vector )
    {
		x *= vector.x;
		y *= vector.y;
		z *= vector.z;
		return *this;
	}

	static const Vector3 ZERO;
	static const Vector3 UNIT_X;
	static const Vector3 UNIT_Y;
	static const Vector3 UNIT_Z;
	static const Vector3 NANV;


};

inline float vecMag(const Vector3 &a)
{
	return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z);
}

inline float distance(const Vector3 &a, const Vector3 &b)
{
	Vector3 c = a - b;
	return vecMag(c);
}

inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y - a.y*b.x); 
}


};

#endif
