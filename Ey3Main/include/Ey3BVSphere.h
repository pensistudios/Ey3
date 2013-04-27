/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3BVSphere.h
/*	Class: BVSphere
/*	Definition: Inherits from BoudingVolume; Sphere Bouding Volume;
/*  Functionality: a sphere that surrounds your model for easy 
/*	culling
******************************************************************/

#ifndef _EY3BVSPHERE_H_
#define _EY3BVSPHERE_H_

#include "Ey3BoundingVolume.h"
#include "Ey3Sphere.h"

namespace Ey3
{

class Ey3Export BVSphere : public BoundingVolume
{
public:

	BVSphere();
	BVSphere(Sphere& s);
	virtual ~BVSphere();

	virtual int getType() const;
	void setCenter(Vector3& pos);
	void setRadius(float rad); 
	const Vector3& getCenter() const;
	float getRadius() const;

	void computeFromVerts(const std::vector<Vector3> list);

	void computeFromVerts(const Vector3* ar, int size);

	void transformBy(const Transformation& trans, BVSphere* out);

	Plane::PointLocation side(const Plane& plane) const;

	bool testIntersection(const Line3& ray) const;
	
	bool testIntersection(const BoundingVolume* in) const;

	void growToContain(const BoundingVolume* in);

	bool contains(const Vector3& point) const;

private:

	Sphere _sphere;
	
	
};

};

#endif