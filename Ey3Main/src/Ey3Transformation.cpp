#include "Ey3Transformation.h"
#include "Ey3Logging.h"

using namespace Ey3;

Transformation::Transformation()
{

}

Transformation::Transformation(Matrix3& rot, Vector3& scale, Vector3& trans)
: _rot(rot), _scale(scale),_trans(trans)
{	
}

Transformation::Transformation(Matrix3& rot, float scale, Vector3& trans)
: _rot(rot),_scale(scale,scale,scale),bisUniformScale(true), _trans(trans)
{
}

void Transformation::setRotate(const Matrix3& mat) 
{
	_rot = mat;
	bisIdentity = false;
}

const Matrix3& Transformation::getRotate() const
{
	return _rot;
}

void Transformation::setTranslate(const Vector3& trans)
{
	_trans = trans;
	bisIdentity = false;
}

const Vector3& Transformation::getTranslate() const
{
	return _trans;
}

void Transformation::setScale(const Vector3 &scale)
{
	_scale = scale;
	bisIdentity = false;
}

const Vector3& Transformation::getScale() const
{
	return _scale;
}

void Transformation::setUniformScale(float scale)
{
	_scale = Vector3(scale,scale,scale);
	bisUniformScale = true;
	bisIdentity = false;
}

float Transformation::getUniformScale() const
{
	if(bisUniformScale)
	{
		return _scale.x;
	}
	return nanF;
}

void Transformation::makeIdentity()
{
	_trans = Vector3::ZERO;
	_scale.x = _scale.y = _scale.z = 1.0f;
	_rot = Matrix3::IDENTITY;
	bisIdentity = true;
}

bool Transformation::isIdentity() const
{
	return bisIdentity;
}

bool Transformation::isUniformScales() const
{
	return bisUniformScale;
}

Vector3 Transformation::applyForward(const Vector3& in) const
{
	if(bisIdentity)
		return in;

	Vector3 out(_scale.x*in.x,_scale.y*in.y, _scale.z*in.z);
        out = _rot*out + _trans;
        return out;
}

Vector3 Transformation::applyInverse(const Vector3& in) const
{
	Matrix3 inv;
	Vector3 out = in - _trans;
	
	if(_rot.inverse(inv))
	{
		out = inv * out;
	}
	//else log
	return out;
}

void Transformation::product(const Transformation& a,const Transformation& b)
{
	if (a.isIdentity())
    {
        *this = b;
        return;
    }

    if (b.isIdentity())
    {
        *this = a;
        return;
    }

    if (a.isUniformScales())
	{
		_rot = a.getRotate()*b.getRotate();

		_trans = ((a.getRotate()	* b.getTranslate()) 
			+ a.getTranslate()) * a.getUniformScale();

		if ( b.isUniformScales())
			setUniformScale(a.getUniformScale()*b.getUniformScale());
		else
			setScale(b.getScale()*a.getUniformScale());

		return;
	}
    // In all remaining cases, the matrix cannot be written as R*S*X+T.
    Matrix3 mA;
	Vector3 aS = a.getScale();
	mA[0][0] = mA[0][0] * aS.x;
	mA[1][1] = mA[1][1] * aS.y;
	mA[2][2] = mA[2][2] * aS.z;

    Matrix3 mB;
	Vector3 bS = b.getScale();
	mB[0][0] = mB[0][0] * bS.x;
	mB[1][1] = mB[1][1] * bS.y;
	mB[2][2] = mB[2][2] * bS.z;
	
    setRotate(mA*mB);
    setTranslate(mA*b.getTranslate()+a.getTranslate());

}
/*
void Transformation::inverse(Transformation& inverse)
{
	inverse.__getTrans() = _trans.inverse();
}
*/
//const Transformation Transformation::IDENTITY(Matrix4::IDENTITY);
