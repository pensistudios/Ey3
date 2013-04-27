#include "Ey3BVSphere.h"

using namespace Ey3;

BVSphere::BVSphere()
: BoundingVolume(BoundingVolume::SPHERE),
_sphere()
{

}

BVSphere::~BVSphere()
{
}

BVSphere::BVSphere(Sphere &s)
: BoundingVolume(BoundingVolume::SPHERE),
_sphere(s)
{
}

int BVSphere::getType() const
{
	return _type;
}

Plane::PointLocation BVSphere::side(const Plane& plane) const
{
    float distance = plane.getDistance(_sphere.getCenter());

    if ( distance <= -_sphere.getRadius() )
		return Plane::BEHIND;
    else if ( distance >= _sphere.getRadius() )
		return Plane::FRONT;

	return Plane::ON_PLANE;
}

void BVSphere::setCenter(Vector3& pos)
{
	center = pos;
	_sphere.setCenter(pos);
}

void BVSphere::setRadius(float r)
{
	radius = r;
	_sphere.setRadius(r);
}

const Vector3& BVSphere::getCenter() const
{
	return center;
}

float BVSphere::getRadius() const
{
	return radius;
}

void BVSphere::computeFromVerts(const Vector3* points, int size)
{
	Vector3 min(points[0]), max(points[0]);
	uint i;
    for ( i = 1; i < size; ++i )
    {
        if (points[i].x < min.x)
            min.x = points[i].x;
        else if (points[i].x > max.x )
            max.x = points[i].x;
        if (points[i].y < min.y)
            min.y = points[i].y;
        else if (points[i].y > max.y )
            max.y = points[i].y;
        if (points[i].z < min.z)
            min.z = points[i].z;
        else if (points[i].z > max.z )
            max.z = points[i].z;
    }
    // compute center and radius
    center = (min + max)*0.5f;
    float maxDistance = Ey3::distance(center, points[0]);
	maxDistance *= maxDistance;
    for ( i = 1; i < size; ++i )
    {
		float dist =  Ey3::distance(center, points[i]);
		dist *= dist;
        if (dist > maxDistance)
            maxDistance = dist;
    }
    radius = sqrtf( maxDistance );
	_sphere._center = center;
	_sphere._radius = radius;
}

void BVSphere::computeFromVerts(const std::vector<Vector3> points)
{
	// compute minimal and maximal bounds
    Vector3 min(points[0]), max(points[0]);
	int size = (int) points.size();
	uint i;
    for ( i = 1; i < size; ++i )
    {
        if (points[i].x < min.x)
            min.x = points[i].x;
        else if (points[i].x > max.x )
            max.x = points[i].x;
        if (points[i].y < min.y)
            min.y = points[i].y;
        else if (points[i].y > max.y )
            max.y = points[i].y;
        if (points[i].z < min.z)
            min.z = points[i].z;
        else if (points[i].z > max.z )
            max.z = points[i].z;
    }
    // compute center and radius
    center = (min + max)*0.5f;
    float maxDistance = Ey3::distance(center, points[0]);
	maxDistance *= maxDistance;
    for ( i = 1; i < size; ++i )
    {
		float dist =  Ey3::distance(center, points[i]);
		dist *= dist;
        if (dist > maxDistance)
            maxDistance = dist;
    }
    radius = sqrtf( maxDistance );
	_sphere._center = center;
	_sphere._radius = radius;
}

void BVSphere::transformBy(const Ey3::Transformation &trans, Ey3::BVSphere *out)
{
	if(trans.isUniformScales())
	{
		out->setCenter(trans.applyForward(center));
		out->setRadius(trans.getUniformScale() * radius);
	}
}

bool BVSphere::testIntersection(const Ey3::BoundingVolume *in) const
{
	if(in->getType() == BoundingVolume::SPHERE)
	{
		float radiusSum = radius + in->getRadius();
		Vector3 centerDiff = in->getCenter() - center; 
		float distancesq = centerDiff.magSqrd();

		// if distance squared < sum of radii squared, collision!
		return ( distancesq <= radiusSum*radiusSum );
	}
	return false; //ONLY against spheres for now
}

bool BVSphere::testIntersection(const Ey3::Line3 &line) const
{
	// compute intermediate values
    Vector3 w = center - line.getOrigin();
    float wsq = w*w;
    float proj = w*  line.getDirection();
    float rsq = radius*radius;
    float vsq = line.getDirection()* line.getDirection();

    // test length of difference vs. radius
    return ( vsq*wsq - proj*proj <= vsq*rsq );
}

void BVSphere::growToContain(const Ey3::BoundingVolume *in)
{
	if(in->getType() == BoundingVolume::SPHERE)
	{
	// get differences between them
    Vector3 diff = in->getCenter() - center;
    float distsq = diff*diff;
	float radiusdiff = in->getRadius() - radius;

    // if one sphere inside other
    if ( distsq <= radiusdiff*radiusdiff )
    {
        if (radius > in->getRadius())
			return;
        else
		{
             center = in->getCenter();
			 _sphere._center = center;
			 radius = in->getRadius();
			 _sphere._radius = radius;
		}
        return;
    }

    // build new sphere
    float dist = sqrt(distsq);
    float fradius = 0.5f*( radius + in->getRadius() + dist );
	if (!(dist < Ey3::EPSILON))
        center += (diff*((fradius-radius)/dist));
	
	_sphere._center = center;
	_sphere._radius = radius;
    } //SPHERES ONLY
}

bool BVSphere::contains(const Vector3& point) const
{
	return(_sphere.contains(point));
}