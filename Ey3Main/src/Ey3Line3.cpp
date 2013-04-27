#include "Ey3Line3.h"

using namespace Ey3;

Line3::Line3(const Ey3::Line3 &l)
: _direction(l.getDirection()), _origin(l.getOrigin())
{
}

void Line3::set(const Vector3& origin, const Vector3& direction)
{
    _origin = origin;
    _direction = direction;
    _direction.normalize();
}   

Vector3 Line3::closestPoint(const Vector3& point) const
{
    Vector3 w = point - _origin;
    float vsq = _direction * _direction;
    float proj = w * _direction;

    return _origin + _direction*(proj/vsq);

}  
