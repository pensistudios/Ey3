/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3BoundingVolume.h
/*	Class: BoundingVolume
/*	Definition: Abstract base class for a bouding volume
/*  Functionality: a volume that surrounds your model 
/*	for easy culling
******************************************************************/

#ifndef _EY3BOUNDINGVOLUME_H_
#define _EY3BOUNDINGVOLUME_H_

#include "Ey3Line3.h"
#include "Ey3Plane.h"
#include "Ey3Transformation.h"

namespace Ey3
{

class Ey3Export BoundingVolume
{
public:

	enum Type
	{
		SPHERE,
		BOX
	};
	
	virtual int getType() const = 0;

	virtual ~BoundingVolume() {}

	virtual void setCenter(Vector3& pos) = 0;
	virtual void setRadius(float rad) = 0;
	virtual const Vector3& getCenter () const = 0;
    virtual float getRadius () const = 0;

	virtual void computeFromVerts(const std::vector<Vector3> list) = 0;

	//virtual void transform(const Transformation& transform, BoundingVolume* out) = 0;
	//Implement later for now since only using BVSPhere it has its own transform method
	virtual Plane::PointLocation side(const Plane& plane) const = 0;

    virtual bool testIntersection (const Line3& ray) const = 0;

    virtual bool testIntersection (const BoundingVolume* in) const = 0;

	virtual void growToContain (const BoundingVolume* in) = 0;

    virtual bool contains (const Vector3& point) const = 0;

protected:
	BoundingVolume(BoundingVolume::Type t): _type(t) {}

	Vector3 center;
	float radius;
	Type _type;



};


};

#endif