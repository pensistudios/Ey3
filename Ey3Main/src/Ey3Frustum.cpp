#include "Ey3Frustum.h"

using namespace Ey3;

Frustum::Frustum()
: _type(PERSPECTIVE),
_FOVy(Radian(Math::PI/4.0)),
_nearDistance(1.0f),
_farDistance(1000.0f),
_aspectRatio(1.33333333333333f)
{

}

Frustum::Frustum(Radian& fovy, float aratio, float near, float far)
:_FOVy(fovy),
_aspectRatio(aratio),
_nearDistance(near),
_farDistance(far),
_type(PERSPECTIVE)
{

}

const Radian& Frustum::getFOV() const
{
	return _FOVy;
}

float Frustum::getNear() const
{
	return _nearDistance;
}

float Frustum::getFar() const
{
	return _farDistance;
}

float Frustum::getAspectRatio() const
{
	return _aspectRatio;
}

void Frustum::setFOV(Radian& r)
{
	_FOVy = r;
}

void Frustum::setNear(float n)
{
	_nearDistance = n;
}

void Frustum::setFar(float f)
{
	_farDistance = f;
}

void Frustum::setAspectRatio(float a)
{
	_aspectRatio  = a;
}
