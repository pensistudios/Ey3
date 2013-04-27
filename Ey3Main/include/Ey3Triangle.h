/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Triangle.h
/*	Class: Triangle
/*	Definition: Mathematical Triangle
/*  Functionality: Used in geometry; Triangle Mesh
******************************************************************/

#ifndef _EY3TRIANGLE_H_
#define _EY3TRIANGLE_H_

#include "Ey3Vector3.h"

namespace Ey3
{

class Triangle
{
public:

	Triangle() {}
    Triangle(const Vector3& v0, const Vector3& v1, const Vector3& v2)
	{
		v[0] = v0;
		v[1] = v1;
		v[2] = v2;
	}
    Triangle(const Vector3 V[3])
	{
		for(int i = 0; i < 3; i++)
			v[i] = V[i];
	}

    Vector3 v[3];
};

};

#endif