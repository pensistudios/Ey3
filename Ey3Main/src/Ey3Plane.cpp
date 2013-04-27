#include "Ey3Plane.h"
#include "Ey3Matrix3.h"

using namespace Ey3;

Plane::Plane(const Vector3& n, float dd)
{
	_norm = n;
	d = dd;
}

Plane::Plane(float a, float b, float c, float dd)
{
	_norm.x = a;
	_norm.y = b;
	_norm.z = c;
	d = dd;
}

Plane::PointLocation Plane::getPointLocation(const Vector3& point)
{
	float distance = getDistance(point);
	
	if(distance < -EPSILON)
	{
		return Plane::BEHIND;
	}
	else if(distance > EPSILON)
	{
		return Plane::FRONT;
	}
	return ON_PLANE;
}

float Plane::getDistance(const Vector3& point) const
{
	return ((point * _norm) + d);
}

Vector3 Plane::projection(const Vector3& vec)
{
	Matrix3 x;
	x[0][0] = _norm.x * _norm.x - 1.0f;
	x[0][1] = _norm.x * _norm.y;
	x[0][2] = _norm.x * _norm.z;
	x[1][0] = _norm.y * _norm.x;
	x[1][1] = _norm.y * _norm.y - 1.0f;
	x[1][2] = _norm.y * _norm.z;
	x[2][0] = _norm.z * _norm.x;
	x[2][1] = _norm.z * _norm.y;
	x[2][2] = _norm.z * _norm.z - 1.0f;
	return (x * vec);
	
}