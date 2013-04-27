/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Plane.h
/*	Class: Plane
/*	Definition: A mathematical plane
/*  Functionality: Used mainly for culling
******************************************************************/

#ifndef _EY3PLANE_H_ 
#define _EY3PLANE_H_ 

#include "Ey3Vector3.h"

namespace Ey3
{

class Ey3Export Plane
{

public:

	Vector3 _norm;
	float d;

	Plane() { _norm = Vector3::ZERO; d = 0.0f; }
	Plane(const Vector3& n, float d);
	Plane(float a,float b, float c,float d);
	
	enum PointLocation
	{
		BEHIND = -1,
		ON_PLANE = 0,
		FRONT = 1
	};

	PointLocation getPointLocation(const Vector3& point);
	float getDistance(const Vector3& point) const;
	Vector3 projection(const Vector3& vec);


};

};

#endif