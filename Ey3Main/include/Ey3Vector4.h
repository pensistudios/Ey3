/****************************************************************/
/*  File: Ey3Vector4.h
/*	Class: Vector4
/*  Definition: A general all-purpose Vector class for 
/*	4-Dimensional Vectors
******************************************************************/

#ifndef _EY3VECTOR4_H_
#define _EY3VECTOR4_H_

#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export Vector4
{
public:

	float x,y,z,w;

	Vector4() {}
	Vector4(const Vector4 &a) : x(a.x), y(a.y) , z(a.z) , w(a.w){}
	Vector4(float xx, float yy, float zz, float ww) : x(xx), y(yy), z(zz), w(ww) {}

	Vector4& operator=(const Vector4 &a)
	{
		x = a.x; y = a.y; z = a.z; w = a.w;
		return *this;
	}

	bool operator==(const Vector4 &a) const 
	{
		return (x==a.x && y == a.y && z == a.z && w == a.w);
	}

	bool operator!=(const Vector4 &a) const
	{
		return (x!=a.x || y != a.y || z != a.z || w != a.w);
	}

	float operator[](const size_t i)
	{
		switch(i)
		{
			case 0:	return x;
			case 1: return y;
			case 2: return z;
			case 3: return w;
		}
		return nanF;
	}

	Vector4 operator -() const
	{
		return Vector4(-x,-y,-z,-w);
	}

	Vector4 operator +(const Vector4 &a) const
	{
		return Vector4(x+a.x,y+a.y,z+a.z,w+a.w);
	}

	Vector4 operator -(const Vector4 &a) const
	{
		return Vector4(x-a.x,y-a.y,z-a.z,w-a.w);
	}

	Vector4& operator+=(const Vector4 &a)
	{
		x+=a.x; y+=a.y; z+=a.z; w+=a.w;
		return *this;
	}
	
	Vector4& operator-=(const Vector4 &a)
	{
		x-=a.x;y-=a.y;z-=a.z;w-=a.w;
		return *this;
	}

	Vector4 operator *(float a) const
	{
		return Vector4(x*a,y*a,z*a,w*a);
	}

	Vector4 operator /(float a) const
	{
		float rep = 1.0f/a;
		return Vector4(x*rep,y*rep,z*rep,w*rep);
	}

	Vector4& operator *=(float a) 
	{
		x*=a;y*=a;z*=a;w*=a;
		return *this;
	}

	Vector4& operator /=(float a) 
	{
		float rep = 1.0f/a;
		x*=rep;y*=rep;z*=rep;w*=rep;
		return *this;
	}

	void zero()
	{
		x=0;y=0;z=0;w=0;
	}

	void normalize()
	{
		float mag = x*x + y*y + z*z + w*w;
		if(mag > 0.0f)
		{
			float r = 1.0f/sqrtf(mag);
			x*=r;y*=r;z*=r;w*=r;
		}
	}

	float mag() const
	{
		return x*x + y*y + z*z + w*w;
	}

	float operator*(const Vector4 &a) const
	{
		return x*a.x + y*a.y + z*a.z + w*a.w;
	}

};

inline float vecMag(const Vector4 &a)
{
	return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w);
}

inline float distance(const Vector4 &a, const Vector4 &b)
{
	Vector4 c = a - b;
	return vecMag(c);
}

static const Vector4 ZERO4 = Vector4(0.0f,0.0f,0.0f,0.0f);
static const Vector4 UNIT_X4 = Vector4(1.0f,0.0f,0.0f,0.0f);
static const Vector4 UNIT_Y4 = Vector4(0.0f,1.0f,0.0f,0.0f);
static const Vector4 UNIT_Z4 = Vector4(0.0f,0.0f,1.0f,0.0f);
static const Vector4 UNIT_W4 = Vector4(0.0f,0.0f,0.0f,1.0f);
static const Vector4 NANV4 = Vector4(nanF,nanF,nanF,nanF);

};

#endif