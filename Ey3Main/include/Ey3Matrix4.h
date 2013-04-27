/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Matrix4.h
/*	Class: Matrix4
/*	Definition: A 4x4 Matrix
/*  Functionality: Used to represent Affine Transformations
******************************************************************/

#ifndef _EY3MATRIX4_H_
#define _EY3MATRIX4_H_

#include "Ey3Vector3.h"
#include "Ey3Vector4.h"
#include "Ey3Matrix3.h"
#include "Ey3Plane.h"
#include "Ey3Quaternion.h"

namespace Ey3
{

class Ey3Export Matrix4
{
	float d[4][4];

public:
	
	Matrix4() //IDENTITY
	{
		d[0][0] = 1.0f;
		d[1][1] = 1.0f;
		d[2][2] = 1.0f;
		d[3][3] = 1.0f;
	}
	
	float* operator [](size_t row)
    {
        assert(row < 4);
        return d[row];
    }

	const float* const operator[](size_t row) const
    {
        assert(row < 4);
        return d[row];
    }
	
	Matrix4(
            float d00, float d01, float d02, float d03,
            float d10, float d11, float d12, float d13,
            float d20, float d21, float d22, float d23,
            float d30, float d31, float d32, float d33 )
        {
            d[0][0] = d00;
            d[0][1] = d01;
            d[0][2] = d02;
            d[0][3] = d03;
            d[1][0] = d10;
            d[1][1] = d11;
            d[1][2] = d12;
            d[1][3] = d13;
            d[2][0] = d20;
            d[2][1] = d21;
            d[2][2] = d22;
            d[2][3] = d23;
            d[3][0] = d30;
            d[3][1] = d31;
            d[3][2] = d32;
            d[3][3] = d33;
        }
	
	Matrix4(Matrix3& mat)
	{
		d[0][0] = mat[0][0];
		d[0][1] = mat[0][1];
		d[0][2] = mat[0][2];
		d[1][0] = mat[1][0];
		d[1][1] = mat[1][1];
		d[1][2] = mat[1][2];
		d[2][0] = mat[2][0];
		d[2][1] = mat[2][1];
		d[2][2] = mat[2][2];
		d[3][0] = 0.0f;
		d[3][1] = 0.0f;
		d[3][2] = 0.0f;
		d[3][3] = 1.0f;
		d[0][3] = 0.0f;
		d[1][3] = 0.0f;
		d[2][3] = 0.0f;
	}

	Matrix4 concatenate(const Matrix4 &d2) const
    {
        Matrix4 r;
        r[0][0] = d[0][0] * d2[0][0] + d[0][1] * d2[1][0] + d[0][2] * d2[2][0] + d[0][3] * d2[3][0];
        r[0][1] = d[0][0] * d2[0][1] + d[0][1] * d2[1][1] + d[0][2] * d2[2][1] + d[0][3] * d2[3][1];
        r[0][2] = d[0][0] * d2[0][2] + d[0][1] * d2[1][2] + d[0][2] * d2[2][2] + d[0][3] * d2[3][2];
        r[0][3] = d[0][0] * d2[0][3] + d[0][1] * d2[1][3] + d[0][2] * d2[2][3] + d[0][3] * d2[3][3];

		r[1][0] = d[1][0] * d2[0][0] + d[1][1] * d2[1][0] + d[1][2] * d2[2][0] + d[1][3] * d2[3][0];
        r[1][1] = d[1][0] * d2[0][1] + d[1][1] * d2[1][1] + d[1][2] * d2[2][1] + d[1][3] * d2[3][1];
        r[1][2] = d[1][0] * d2[0][2] + d[1][1] * d2[1][2] + d[1][2] * d2[2][2] + d[1][3] * d2[3][2];
        r[1][3] = d[1][0] * d2[0][3] + d[1][1] * d2[1][3] + d[1][2] * d2[2][3] + d[1][3] * d2[3][3];

        r[2][0] = d[2][0] * d2[0][0] + d[2][1] * d2[1][0] + d[2][2] * d2[2][0] + d[2][3] * d2[3][0];
        r[2][1] = d[2][0] * d2[0][1] + d[2][1] * d2[1][1] + d[2][2] * d2[2][1] + d[2][3] * d2[3][1];
        r[2][2] = d[2][0] * d2[0][2] + d[2][1] * d2[1][2] + d[2][2] * d2[2][2] + d[2][3] * d2[3][2];
        r[2][3] = d[2][0] * d2[0][3] + d[2][1] * d2[1][3] + d[2][2] * d2[2][3] + d[2][3] * d2[3][3];

        r[3][0] = d[3][0] * d2[0][0] + d[3][1] * d2[1][0] + d[3][2] * d2[2][0] + d[3][3] * d2[3][0];
        r[3][1] = d[3][0] * d2[0][1] + d[3][1] * d2[1][1] + d[3][2] * d2[2][1] + d[3][3] * d2[3][1];
        r[3][2] = d[3][0] * d2[0][2] + d[3][1] * d2[1][2] + d[3][2] * d2[2][2] + d[3][3] * d2[3][2];
        r[3][3] = d[3][0] * d2[0][3] + d[3][1] * d2[1][3] + d[3][2] * d2[2][3] + d[3][3] * d2[3][3];

        return r;
	}
	
	Matrix4 operator*(const Matrix4& d2) const
    {
        return concatenate(d2);
    }
	
	Vector3 operator*(const Vector3 &v) const
    {
        Vector3 r;

		float inv = 1.0/(d[3][0] * v.x + d[3][1] * v.y + d[3][2] * v.z + d[3][3]);

		r.x = ( d[0][0] * v.x + d[0][1] * v.y + d[0][2] * v.z + d[0][3] ) * inv;
		r.y = ( d[1][0] * v.x + d[1][1] * v.y + d[1][2] * v.z + d[1][3] ) * inv;
		r.z = ( d[2][0] * v.x + d[2][1] * v.y + d[2][2] * v.z + d[2][3] ) * inv;

		return r;
	}
	Vector4 operator*(const Vector4& v) const
	{
		return Vector4(
			d[0][0] * v.x + d[0][1] * v.y + d[0][2] * v.z + d[0][3] * v.w, 
			d[1][0] * v.x + d[1][1] * v.y + d[1][2] * v.z + d[1][3] * v.w,
			d[2][0] * v.x + d[2][1] * v.y + d[2][2] * v.z + d[2][3] * v.w,
			d[3][0] * v.x + d[3][1] * v.y + d[3][2] * v.z + d[3][3] * v.w
			);
	}
	Plane operator*(const Plane& p) const
	{
		Plane ret;
		Matrix4 invTrans = inverse().transpose(); //TODO
		ret._norm.x =
			invTrans[0][0] * p._norm.x + invTrans[0][1] * p._norm.y + invTrans[0][2] * p._norm.z;
		ret._norm.y = 
			invTrans[1][0] * p._norm.x + invTrans[1][1] * p._norm.y + invTrans[1][2] * p._norm.z;
		ret._norm.z = 
			invTrans[2][0] * p._norm.x + invTrans[2][1] * p._norm.y + invTrans[2][2] * p._norm.z;
		Vector3 pt = p._norm * -p.d;
		pt = *this * pt;
		ret.d = - pt * ret._norm;
		return ret;
	}
	
	Matrix4 operator+(const Matrix4 &m2) const
    {
		Matrix4 r;
            
		r[0][0] = d[0][0] + m2[0][0];
        r[0][1] = d[0][1] + m2[0][1];
        r[0][2] = d[0][2] + m2[0][2];
        r[0][3] = d[0][3] + m2[0][3];

		r[1][0] = d[1][0] + m2[1][0];
		r[1][1] = d[1][1] + m2[1][1];
		r[1][2] = d[1][2] + m2[1][2];
		r[1][3] = d[1][3] + m2[1][3];
		
		r[2][0] = d[2][0] + d[2][0];
		r[2][1] = d[2][1] + d[2][1];
		r[2][2] = d[2][2] + d[2][2];
		r[2][3] = d[2][3] + d[2][3];
		
		r[3][0] = d[3][0] + d[3][0];
		r[3][1] = d[3][1] + d[3][1];
		r[3][2] = d[3][2] + d[3][2];
		r[3][3] = d[3][3] + d[3][3];

		return r;        
	}

    Matrix4 operator-(const Matrix4 &m2) const
    {
        Matrix4 r;
    
		r[0][0] = d[0][0] - m2[0][0];
		r[0][1] = d[0][1] - m2[0][1];
		r[0][2] = d[0][2] - m2[0][2];
		r[0][3] = d[0][3] - m2[0][3];
        
		r[1][0] = d[1][0] - m2[1][0];
		r[1][1] = d[1][1] - m2[1][1];
		r[1][2] = d[1][2] - m2[1][2];
		r[1][3] = d[1][3] - m2[1][3];
		
		r[2][0] = d[2][0] - d[2][0];
		r[2][1] = d[2][1] - d[2][1];
		r[2][2] = d[2][2] - d[2][2];
		r[2][3] = d[2][3] - d[2][3];

		r[3][0] = d[3][0] - d[3][0];
		r[3][1] = d[3][1] - d[3][1];
		r[3][2] = d[3][2] - d[3][2];
		r[3][3] = d[3][3] - d[3][3];

		return r;

	}
	bool operator == ( const Matrix4& m2 ) const
	{
		if( 
			d[0][0] != m2[0][0] || d[0][1] != m2[0][1] || d[0][2] != m2[0][2] || d[0][3] != m2[0][3] ||
			d[1][0] != m2[1][0] || d[1][1] != m2[1][1] || d[1][2] != m2[1][2] || d[1][3] != m2[1][3] ||
			d[2][0] != m2[2][0] || d[2][1] != m2[2][1] || d[2][2] != m2[2][2] || d[2][3] != m2[2][3] ||
			d[3][0] != m2[3][0] || d[3][1] != m2[3][1] || d[3][2] != m2[3][2] || d[3][3] != m2[3][3] )
			return false;
		return true;
	}

    bool operator != (const Matrix4& m2) const
	{
		if( 
			d[0][0] != m2[0][0] || d[0][1] != m2[0][1] || d[0][2] != m2[0][2] || d[0][3] != m2[0][3] ||
			d[1][0] != m2[1][0] || d[1][1] != m2[1][1] || d[1][2] != m2[1][2] || d[1][3] != m2[1][3] ||
			d[2][0] != m2[2][0] || d[2][1] != m2[2][1] || d[2][2] != m2[2][2] || d[2][3] != m2[2][3] ||
			d[3][0] != m2[3][0] || d[3][1] != m2[3][1] || d[3][2] != m2[3][2] || d[3][3] != m2[3][3] )
			return true;     
		return false;
	}
     
	void operator=(const Matrix3& mat3)
	{
		d[0][0] = mat3.d[0][0]; d[0][1] = mat3.d[0][1]; d[0][2] = mat3.d[0][2];
		d[1][0] = mat3.d[1][0]; d[1][1] = mat3.d[1][1]; d[1][2] = mat3.d[1][2];
		d[2][0] = mat3.d[2][0]; d[2][1] = mat3.d[2][1]; d[2][2] = mat3.d[2][2];
	}

	Matrix4 transpose() const
	{
		return Matrix4(d[0][0], d[1][0], d[2][0], d[3][0],
			d[0][1], d[1][1], d[2][1], d[3][1],
			d[0][2], d[1][2], d[2][2], d[3][2],
			d[0][3], d[1][3], d[2][3], d[3][3]);
	}

	void setMatrix(const Matrix3& mat)
	{
		d[0][0] = mat[0][0];
		d[0][1] = mat[0][1];
		d[0][2] = mat[0][2];
		d[1][0] = mat[1][0];
		d[1][1] = mat[1][1];
		d[1][2] = mat[1][2];
		d[2][0] = mat[2][0];
		d[2][1] = mat[2][1];
		d[2][2] = mat[2][2];
	}

    void setTrans(const Vector3& v)
    {
		d[0][3] = v.x;
		d[1][3] = v.y;
		d[2][3] = v.z;
	}

	Vector3 getTrans() const
	{
		return Vector3(d[0][3], d[1][3], d[2][3]);
	}
        
	void makeTrans(const Vector3& v)
	{
		d[0][0] = 1.0; d[0][1] = 0.0; d[0][2] = 0.0; d[0][3] = v.x;
		d[1][0] = 0.0; d[1][1] = 1.0; d[1][2] = 0.0; d[1][3] = v.y;
		d[2][0] = 0.0; d[2][1] = 0.0; d[2][2] = 1.0; d[2][3] = v.z;
		d[3][0] = 0.0; d[3][1] = 0.0; d[3][2] = 0.0; d[3][3] = 1.0;
	}

	void makeTrans(float tx, float ty, float tz)
	{
		d[0][0] = 1.0; d[0][1] = 0.0; d[0][2] = 0.0; d[0][3] = tx;
		d[1][0] = 0.0; d[1][1] = 1.0; d[1][2] = 0.0; d[1][3] = ty;
		d[2][0] = 0.0; d[2][1] = 0.0; d[2][2] = 1.0; d[2][3] = tz;
		d[3][0] = 0.0; d[3][1] = 0.0; d[3][2] = 0.0; d[3][3] = 1.0;
	}

	static Matrix4 getTrans(const Vector3& v)
  	{
		Matrix4 r;

		r[0][0] = 1.0; r[0][1] = 0.0; r[0][2] = 0.0; r[0][3] = v.x;
		r[1][0] = 0.0; r[1][1] = 1.0; r[1][2] = 0.0; r[1][3] = v.y;
		r[2][0] = 0.0; r[2][1] = 0.0; r[2][2] = 1.0; r[2][3] = v.z;
		r[3][0] = 0.0; r[3][1] = 0.0; r[3][2] = 0.0; r[3][3] = 1.0;

		return r;
	}

	static Matrix4 getTrans(float t_x, float t_y, float t_z)
	{
		Matrix4 r;

		r[0][0] = 1.0; r[0][1] = 0.0; r[0][2] = 0.0; r[0][3] = t_x;
		r[1][0] = 0.0; r[1][1] = 1.0; r[1][2] = 0.0; r[1][3] = t_y;
		r[2][0] = 0.0; r[2][1] = 0.0; r[2][2] = 1.0; r[2][3] = t_z;
		r[3][0] = 0.0; r[3][1] = 0.0; r[3][2] = 0.0; r[3][3] = 1.0;

		return r;
	}

	void setScale(const Vector3& v)
	{
		d[0][0] = v.x;
		d[1][1] = v.y;
		d[2][2] = v.z;
	}

	static Matrix4 getScale(const Vector3& v)
	{
		Matrix4 r;
		r[0][0] = v.x; r[0][1] = 0.0; r[0][2] = 0.0; r[0][3] = 0.0;
		r[1][0] = 0.0; r[1][1] = v.y; r[1][2] = 0.0; r[1][3] = 0.0;
		r[2][0] = 0.0; r[2][1] = 0.0; r[2][2] = v.z; r[2][3] = 0.0;
		r[3][0] = 0.0; r[3][1] = 0.0; r[3][2] = 0.0; r[3][3] = 1.0;

		return r;
	}

	static Matrix4 getScale(float s_x, float s_y, float s_z)
	{
		Matrix4 r;
		r[0][0] = s_x; r[0][1] = 0.0; r[0][2] = 0.0; r[0][3] = 0.0;
		r[1][0] = 0.0; r[1][1] = s_y; r[1][2] = 0.0; r[1][3] = 0.0;
		r[2][0] = 0.0; r[2][1] = 0.0; r[2][2] = s_z; r[2][3] = 0.0;
		r[3][0] = 0.0; r[3][1] = 0.0; r[3][2] = 0.0; r[3][3] = 1.0;

		return r;
	}

	void extract3x3Matrix(Matrix3& m3x3) const
	{
		m3x3[0][0] = d[0][0];
		m3x3[0][1] = d[0][1];
		m3x3[0][2] = d[0][2];
		m3x3[1][0] = d[1][0];
		m3x3[1][1] = d[1][1];
		m3x3[1][2] = d[1][2];
		m3x3[2][0] = d[2][0];
		m3x3[2][1] = d[2][1];
		m3x3[2][2] = d[2][2];
	}

	Quaternion extractQuaternion() const
    {
		Matrix3 m3x3;
		extract3x3Matrix(m3x3);
		return Quaternion(m3x3);
	}

	Matrix4 operator*(float scalar)
	{
		return Matrix4(
			scalar*d[0][0], scalar*d[0][1], scalar*d[0][2], scalar*d[0][3],
			scalar*d[1][0], scalar*d[1][1], scalar*d[1][2], scalar*d[1][3],
			scalar*d[2][0], scalar*d[2][1], scalar*d[2][2], scalar*d[2][3],
			scalar*d[3][0], scalar*d[3][1], scalar*d[3][2], scalar*d[3][3]);
	}
	

	Matrix4 adjoint() const;
	float det() const;
	Matrix4 inverse() const;

	void makeTransform(const Vector3& position, const Vector3& scale, const Quaternion& orientation);

    void makeInverseTransform(const Vector3& position, const Vector3& scale, const Quaternion& orientation);
	
	static const Matrix4 ZERO;
    static const Matrix4 IDENTITY;

};    
    
inline Vector4 operator * (const Vector4& v, const Matrix4& mat)
{

	return Vector4(
		v.x*mat[0][0] + v.y*mat[1][0] + v.z*mat[2][0] + v.w*mat[3][0],
		v.x*mat[0][1] + v.y*mat[1][1] + v.z*mat[2][1] + v.w*mat[3][1],
		v.x*mat[0][2] + v.y*mat[1][2] + v.z*mat[2][2] + v.w*mat[3][2],
		v.x*mat[0][3] + v.y*mat[1][3] + v.z*mat[2][3] + v.w*mat[3][3]	);
}



};

#endif