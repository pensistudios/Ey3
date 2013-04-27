/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3BVBox.h
/*	Class: BVBox
/*	Definition: Inherits from BoudingVolume; Box Bouding Volume;
/*  Functionality: a box that surrounds your model for easy 
/*	culling
******************************************************************/

#ifndef _EY3BVBOX_H_
#define _EY3BVBOX_H_

#include "Ey3BoundingVolume.h"

namespace Ey3
{

class Ey3Export BVBox : public BoundingVolume
{
public:

	BVBox();
	virtual ~BVBox();
	
	virtual int getType() const;
	void setCenter(Vector3& pos);
	void setRadius(float rad); //useless for box
	const Vector3& getCenter() const;
	float getRadius() const;

	void computeFromVerts(const Vector3* vertArray, int size);

	void transformBy(const Transformation& trans, BVBox* out);

	Plane::PointLocation side(const Plane& plane) const;

	bool testIntersection(const Line3& ray) const;
	
	bool testIntersection(const BoundingVolume* in) const;

	void growToContain(const BoundingVolume* in);

	bool contains(const Vector3& point) const;
	
	
};

};

#endif