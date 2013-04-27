#ifndef _EY3FRUSTRUM_H_
#define _EY3FRUSTRUM_H_

#include "Ey3Plane.h"
#include "Ey3Vector2.h"

namespace Ey3
{

class Ey3Export Frustrum
{
public:

	enum ProjectionType
	{
		ORTHOGRAPHIC,
		PERSPECTIVE
	};


private:
	
	ProjectionType _type;

	Plane _near;
	Plane _far;
	Plane _left;
	Plane _right;
	Plane _down;
	Plane _up;

	Radian _FOVy;
	float _farDistance;
	float _nearDistance;

	float _aspectRatio;
	Vector2 frustrumOffset;






};

};

#endif