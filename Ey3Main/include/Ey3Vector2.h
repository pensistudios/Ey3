/****************************************************************/
/*  File: Ey3Vector2.h
/*	Class: Vector2
/*  Definition: A general all-purpose Vector class for 
/*	2-Dimensional Vectors
******************************************************************/

#ifndef _EY3VECTOR2_H_
#define _EY3VECTOR2_H_

#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export Vector2
{
public:

	float x,y;

	Vector2() : x(0), y(0){}
	Vector2(const Vector2 &a) : x(a.x), y(a.y) {}
	Vector2(float xx, float yy) : x(xx), y(yy){}
	
	Vector2& operator=(const Vector2 &a)
	{
		x = a.x; y = a.y;
		return *this;
	}

	bool operator==(const Vector2 &a) const 
	{
		return (x==a.x && y == a.y);
	}

	bool operator!=(const Vector2 &a) const
	{
		return (x!=a.x || y != a.y);
	}

	float operator[](const size_t i)
	{
		switch(i)
		{
			case 0:	return x;
			case 1: return y;
		}
		return nanF;
	}

	Vector2 operator -() const
	{
		return Vector2(-x,-y);
	}

	Vector2 operator +(const Vector2 &a) const
	{
		return Vector2(x+a.x,y+a.y);
	}

	Vector2 operator -(const Vector2 &a) const
	{
		return Vector2(x-a.x,y-a.y);
	}

	Vector2& operator+=(const Vector2 &a)
	{
		x+=a.x; y+=a.y; 
		return *this;
	}
	
	Vector2& operator-=(const Vector2 &a)
	{
		x-=a.x;y-=a.y;
		return *this;
	}

	Vector2 operator *(float a) const
	{
		return Vector2(x*a,y*a);
	}

	Vector2 operator /(float a) const
	{
		float rep = 1.0f/a;
		return Vector2(x*rep,y*rep);
	}

	Vector2& operator *=(float a) 
	{
		x*=a;y*=a;
		return *this;
	}

	Vector2& operator /=(float a) 
	{
		float rep = 1.0f/a;
		x*=rep;y*=rep;
		return *this;
	}

	void zero()
	{
		x=0;y=0;
	}

	void normalize()
	{
		float mag = x*x + y*y;
		if(mag > 0.0f)
		{
			float r = 1.0f/sqrtf(mag);
			x*=r;y*=r;
		}
	}

	float operator*(const Vector2 &a) const
	{
		return x*a.x + y*a.y;
	}
	
	Vector2 midPoint(const Vector2& a) const
    {
		return Vector2(( x + a.x ) * 0.5,( y + a.y ) * 0.5 );
    }

	Vector2 perp() const
	{
		return Vector2(-y,x);
	}
 
};

inline float vecMag(const Vector2 &a)
{
	return sqrtf(a.x*a.x + a.y*a.y);
}

inline float distance(const Vector2 &a, const Vector2 &b)
{
	Vector2 c = a - b;
	return vecMag(c);
}

//static const Vector2 ZERO2 = Vector2(0.0f,0.0f);
//static const Vector2 UNIT_X2 = Vector2(1.0f,0.0f);
//static const Vector2 UNIT_Y2 = Vector2(0.0f,1.0f); 

};

#endif
