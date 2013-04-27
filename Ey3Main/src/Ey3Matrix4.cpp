#include "Ey3Matrix4.h"

namespace Ey3
{

const Matrix4 Matrix4::ZERO(
		0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0 );

const Matrix4 Matrix4::IDENTITY(
		1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1 );


inline static float MINOR(const Matrix4& m, const size_t r0, const size_t r1, const size_t r2, 
								const size_t c0, const size_t c1, const size_t c2)
{
	return m[r0][c0] * (m[r1][c1] * m[r2][c2] - m[r2][c1] * m[r1][c2]) -
		m[r0][c1] * (m[r1][c0] * m[r2][c2] - m[r2][c0] * m[r1][c2]) +
		m[r0][c2] * (m[r1][c0] * m[r2][c1] - m[r2][c0] * m[r1][c1]);
}

Matrix4 Matrix4::adjoint() const
{
	return Matrix4( MINOR(*this, 1, 2, 3, 1, 2, 3),
		-MINOR(*this, 0, 2, 3, 1, 2, 3),
		MINOR(*this, 0, 1, 3, 1, 2, 3),
		-MINOR(*this, 0, 1, 2, 1, 2, 3),

		-MINOR(*this, 1, 2, 3, 0, 2, 3),
		MINOR(*this, 0, 2, 3, 0, 2, 3),
		-MINOR(*this, 0, 1, 3, 0, 2, 3),
		MINOR(*this, 0, 1, 2, 0, 2, 3),

		MINOR(*this, 1, 2, 3, 0, 1, 3),
		-MINOR(*this, 0, 2, 3, 0, 1, 3),
		MINOR(*this, 0, 1, 3, 0, 1, 3),
		-MINOR(*this, 0, 1, 2, 0, 1, 3),

		-MINOR(*this, 1, 2, 3, 0, 1, 2),
		MINOR(*this, 0, 2, 3, 0, 1, 2),
		-MINOR(*this, 0, 1, 3, 0, 1, 2),
		MINOR(*this, 0, 1, 2, 0, 1, 2));
}

float Matrix4::det() const
{
	return d[0][0] * MINOR(*this, 1, 2, 3, 1, 2, 3) -
		d[0][1] * MINOR(*this, 1, 2, 3, 0, 2, 3) +
		d[0][2] * MINOR(*this, 1, 2, 3, 0, 1, 3) -
		d[0][3] * MINOR(*this, 1, 2, 3, 0, 1, 2);
}

Matrix4 Matrix4::inverse() const
{
	return adjoint() * (1.0f / det());
}

void Matrix4::makeTransform(const Vector3& position, const Vector3& scale, const Quaternion& orientation)
{

	Matrix3 scale3x3;
	Matrix3 rot3x3 = orientation.toRotationMatrix();
	scale3x3 = Matrix3::ZERO;
	scale3x3[0][0] = scale.x;
	scale3x3[1][1] = scale.y;
	scale3x3[2][2] = scale.z;


	*this = rot3x3 * scale3x3;
	this->setTrans(position);

	d[3][0] = 0; d[3][1] = 0; d[3][2] = 0; d[3][3] = 1;
}

void Matrix4::makeInverseTransform(const Vector3& position, const Vector3& scale, const Quaternion& orientation)
{

	Vector3 invTranslate = -position;
	Vector3 invScale(1 / scale.x, 1 / scale.y, 1 / scale.z);
	Quaternion invRot = orientation.inverse();

	invTranslate *= invScale; 
	invTranslate = invRot.rotate(invTranslate); 


	Matrix3 rot3x3, scale3x3;
	rot3x3 = invRot.toRotationMatrix();
	scale3x3 = Matrix3::ZERO;
	scale3x3[0][0] = invScale.x;
	scale3x3[1][1] = invScale.y;
	scale3x3[2][2] = invScale.z;


	*this = scale3x3 * rot3x3;
	this->setTrans(invTranslate);


	d[3][0] = 0; d[3][1] = 0; d[3][2] = 0; d[3][3] = 1;
}

};