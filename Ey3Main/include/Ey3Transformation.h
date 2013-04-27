/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Transformation.h
/*	Class: Transformation
/*	Definition: Represents a Transformation
/*  Functionality: Used to manipulate objects in scene graph
******************************************************************/

#ifndef _EY3TRANSFORMATION_H_
#define _EY3TRANSFORMATION_H_

//Transformation
//Y=M*X+T
//M is a 3x3 Matrix that = RotationMatrix*ScaleMatrix
//X is input vector Y is output Vector
//T is transformation Vector
//Stored as a column order 4x4 Matrix
//[m m m v]
//[m m m v]
//[m m m v]
//[0 0 0 1]
//Scaling is stored as the diag of M

#include "Ey3Vector3.h"
#include "Ey3Matrix3.h"
#include "Ey3Matrix4.h"

namespace Ey3
{

class Ey3Export Transformation
{
public:
	Transformation();
	Transformation(Matrix3& rot, Vector3& scale,Vector3& trans);
	Transformation(Matrix3& rot, float scale, Vector3& trans);
	Transformation(Quaternion& orient, Vector3& scale, Vector3& trans); //dont use yet

	Transformation& operator=(const Transformation& kA)
	{
		_rot = kA.getRotate();
		_scale = kA.getScale();
		_trans = kA.getTranslate();
		bisIdentity = kA.isIdentity();
		bisUniformScale = kA.isUniformScales();
		return *this;
	}

	void makeIdentity();
	bool isIdentity() const;
	bool isUniformScales() const;

	const Matrix3& getRotate() const;
	void setRotate(const Matrix3& rot);
    void setTranslate (const Vector3& trans);
    const Vector3& getTranslate() const;
    void setScale (const Vector3& scale);
    const Vector3& getScale () const;
    void setUniformScale (float scale);
    float getUniformScale () const;

    Vector3 applyForward (const Vector3& in) const;

    Vector3 applyInverse (const Vector3& in) const;

    // Compute C = A*B.
    void product (const Transformation& a, const Transformation& b);

    // The identity transformation.
    static const Transformation IDENTITY;

private:
	Matrix3 _rot;
	Vector3 _scale;
	Vector3 _trans;
	bool bisIdentity;
	bool bisUniformScale;

};


};


#endif