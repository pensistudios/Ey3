#include "Ey3Quaternion.h"

namespace Ey3
{

const Quaternion Quaternion::ZERO(0.0,0.0,0.0,0.0);
const Quaternion Quaternion::IDENTITY(1.0,0.0,0.0,0.0);

void Quaternion::convertRotationMatrix(const Matrix3& rot)
{
	// Ken Shoemake's Algorithm
	//TODO: REWRITE WHEN ADD MATH FUNCTIONS

	float trace = rot[0][0]+rot[1][1]+rot[2][2];
	float root;

	if ( trace > 0.0 )
	{
		// |w| > 1/2, may as well choose w > 1/2
		root = sqrtf(trace + 1.0);  // 2w
		w = 0.5*root;
		root = 0.5/root;  // 1/(4w)
		x = (rot[2][1]-rot[1][2])*root;
		y = (rot[0][2]-rot[2][0])*root;
		z = (rot[1][0]-rot[0][1])*root;
	}
	else
	{
		// |w| <= 1/2
		static size_t s_iNext[3] = { 1, 2, 0 };
		size_t i = 0;
		if ( rot[1][1] > rot[0][0] )
			i = 1;
		if ( rot[2][2] > rot[i][i] )
			i = 2;
		size_t j = s_iNext[i];
		size_t k = s_iNext[j];

		root = sqrt(rot[i][i]-rot[j][j]-rot[k][k] + 1.0);
		float* apkQuat[3] = { &x, &y, &z };
		*apkQuat[i] = 0.5*root;
		root = 0.5/root;
		w = (rot[k][j]-rot[j][k])*root;
		*apkQuat[j] = (rot[j][i]+rot[i][j])*root;
		*apkQuat[k] = (rot[k][i]+rot[i][k])*root;
	}
}

Matrix3 Quaternion::toRotationMatrix () const
{
	float tx  = 2.0*x;
	float ty  = 2.0*y;
	float tz  = 2.0*z;
	float twx = tx*w;
	float twy = ty*w;
	float twz = tz*w;
	float txx = tx*x;
	float txy = ty*x;
	float txz = tz*x;
	float tyy = ty*y;
	float tyz = tz*y;
	float tzz = tz*z;

	float rot[3][3];
	rot[0][0] = 1.0-(tyy+tzz);
	rot[0][1] = txy-twz;
	rot[0][2] = txz+twy;
	rot[1][0] = txy+twz;
	rot[1][1] = 1.0-(txx+tzz);
	rot[1][2] = tyz-twx;
	rot[2][0] = txz-twy;
	rot[2][1] = tyz+twx;
	rot[2][2] = 1.0-(txx+tyy);
	return Matrix3(rot);
}

//TODO:THIS
void Quaternion::toAxisAngle (Vector3& axis, Radian& angle) const
{
	float sqrLen = x*x+y*y+z*z;
	if (sqrLen > 0.0)
	{
		angle = 2.0*acos(w); //TODO
		float invLen = Math::InvSqrt(sqrLen);
		axis.x = x*invLen;
		axis.y = y*invLen;
		axis.z = z*invLen;
	}
	else
	{
		// angle is 0 (mod 2*pi), so any axis will do
		angle = Radian(0.0);
		axis.x = 1.0;
		axis.y = 0.0;
		axis.z = 0.0;
	}
}

Vector3 Quaternion::rotate(const Vector3& vec) const
{
	//TODO
	return vec;
}

Quaternion Quaternion::inverse() const
{
	//TODO
	return *this;
}

};