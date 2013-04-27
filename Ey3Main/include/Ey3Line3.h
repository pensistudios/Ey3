/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Line3.h
/*	Class: Line3
/*  Definition: Class used for representing 3dimensional lines
/*	Functionality: Used for easy mathematical operations
******************************************************************/

#ifndef _EY3LINE_H_
#define _EY3LINE_H_

#include "Ey3Vector3.h"

namespace Ey3
{

class Ey3Export Line3
{
protected:
	Vector3 _direction;
	Vector3 _origin;
public:
	Line3() {}
	Line3(const Vector3& d, const Vector3& o) : _direction(d), _origin(o) {}
	Line3(float a, float b, float c);
	Line3(const Line3& l);
	~Line3();

	const Vector3& getOrigin() const { return _origin; }
	const Vector3& getDirection() const { return _direction; }
	
	void set(const Vector3& origin, const Vector3& direction);
    inline void zero() { _origin.zero(); _direction.zero(); }



	Vector3 closestPoint( const Vector3& point ) const;
};

};

#endif