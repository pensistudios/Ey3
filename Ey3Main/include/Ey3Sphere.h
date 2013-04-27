/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Sphere.h
/*	Class: Sphere
/*	Definition: Mathematical sphere
/*  Functionality: Used for bouding sphere
******************************************************************/

#ifndef _EY3SPHERE_H_
#define _EY3SPHERE_H_

#include "Ey3Vector3.h"

namespace Ey3
{

class Ey3Export Sphere
{
public: //W/e
	Vector3 _center;
	float _radius;
public:
	Sphere() :_center(Vector3::ZERO) , _radius(0.0f) {}
	Sphere(Vector3& d, float r) : _center(d), _radius(r) {}
	Sphere(Sphere& s) : _center(s.getCenter()), _radius(s.getRadius()) {}
	
	float getRadius() const
	{
		return _radius;
	}
	
	void setRadius(float r)
	{
		_radius = r;
	}

	const Vector3& getCenter() const
	{
		return _center;
	}

	void setCenter(const Vector3& v)
	{
		_center = v;
	}
	
	bool contains(const Vector3& point) const
	{
		Vector3 diff = point - _center;
		return diff.mag() <= _radius;
	}


};

};

#endif