#include "Ey3Matrix3.h"

using namespace Ey3;

const Matrix3 Matrix3::ZERO(0,0,0,0,0,0,0,0,0);
const Matrix3 Matrix3::IDENTITY(1,0,0,0,1,0,0,0,1);

Matrix3 Matrix3::operator-()
{
	float m[3][3];
	m[0][0] = -d[0][0];
	m[1][0] = -d[1][0];
	m[2][0] = -d[2][0];
	
	m[0][1] = -d[0][1];
	m[1][1] = -d[1][1];
	m[2][1] = -d[2][1];

	m[0][2] = -d[0][2];
	m[1][2] = -d[1][2];
	m[2][2] = -d[2][2];

	return Matrix3(m);
}

Matrix3 Matrix3::operator+(const Matrix3& a) const
{
	float m[3][3];
	m[0][0] = d[0][0] + a.d[0][0];
	m[1][0] = d[1][0] + a.d[1][0];
	m[2][0] = d[2][0] + a.d[2][0];
	
	m[0][1] = d[0][1] + a.d[0][1];
	m[1][1] = d[1][1] + a.d[1][1];
	m[2][1] = d[2][1] + a.d[2][1];

	m[0][2] = d[0][2] + a.d[0][2];
	m[1][2] = d[1][2] + a.d[1][2];
	m[2][2] = d[2][2] + a.d[2][2];	
	return Matrix3(m);
}

Matrix3& Matrix3::operator+=(const Matrix3& a)
{
	d[0][0] += a.d[0][0];
	d[1][0] += a.d[1][0];
	d[2][0] += a.d[2][0];
	d[0][1] += a.d[0][1];
	d[1][1] += a.d[1][1];
	d[2][1] += a.d[2][1];
	d[0][2] += a.d[0][2];
	d[1][2] += a.d[1][2];
	d[2][2] += a.d[2][2];

	return *this;
}

Matrix3 Matrix3::operator-(const Matrix3& a) const
{
	float m[3][3];
	m[0][0] = d[0][0] - a.d[0][0];
	m[1][0] = d[1][0] - a.d[1][0];
	m[2][0] = d[2][0] - a.d[2][0];
	
	m[0][1] = d[0][1] - a.d[0][1];
	m[1][1] = d[1][1] - a.d[1][1];
	m[2][1] = d[2][1] - a.d[2][1];

	m[0][2] = d[0][2] - a.d[0][2];
	m[1][2] = d[1][2] - a.d[1][2];
	m[2][2] = d[2][2] - a.d[2][2];	
	return Matrix3(m);
}

Matrix3& Matrix3::operator-=(const Matrix3& a)
{
	d[0][0] -= a.d[0][0];
	d[1][0] -= a.d[1][0];
	d[2][0] -= a.d[2][0];
	d[0][1] -= a.d[0][1];
	d[1][1] -= a.d[1][1];
	d[2][1] -= a.d[2][1];
	d[0][2] -= a.d[0][2];
	d[1][2] -= a.d[1][2];
	d[2][2] -= a.d[2][2];
	return *this;
}

Matrix3 Matrix3::operator*(const Matrix3& a) const
{
	float an[3][3];
	
	for(uint r = 0; r < 3; r++)
	{
		for(uint c = 0; c < 3; c++)
		{
			an[r][c] = d[r][0]*a.d[0][c] + d[r][1]*a.d[1][c] + d[r][2]*a.d[2][c];
		}
	}

	return Matrix3(an);
}

Matrix3& Matrix3::operator*=(const Matrix3& a)
{
	for(uint r = 0; r < 3; r++)
	{
		for(uint c = 0; c < 3; c++)
		{
			d[r][c] = d[r][0]*a.d[0][c] + d[r][1]*a.d[1][c] + d[r][2]*a.d[2][c];
		}
	}
	return *this;
}

Matrix3 Matrix3::operator*(float f)
{
	float a[3][3];
	for(uint r = 0; r < 3; r++)
	{
		for(uint c = 0; c < 3; c++)
		{
			a[r][c] = d[r][c] * f;			
		}
	}
	return Matrix3(a);
}

Matrix3& Matrix3::operator *=(float a)
{
	for(uint r = 0; r < 3; r++)
	{
		for(uint c = 0; c < 3; c++)
		{
			d[r][c] *= a;			
		}
	}
	return *this;
}

Matrix3 Matrix3::operator+(float a)
{
	float aa[3][3];
	aa[0][0] = d[0][0] + a;
	aa[1][0] = d[1][0] + a;
	aa[2][0] = d[2][0] + a;
	aa[0][1] = d[0][1] + a;
	aa[1][1] = d[1][1] + a;
	aa[2][1] = d[2][1] + a;
	aa[0][2] = d[0][2] + a; 
	aa[1][2] = d[1][2] + a;
	aa[2][2] = d[2][2] + a;
	return Matrix3(aa);

}

Matrix3& Matrix3::operator+=(float a)
{
	d[0][0] += a;
	d[1][0] += a;
	d[2][0] += a;
	d[0][1] += a;
	d[1][1] += a;
	d[2][1] += a;
	d[0][2] += a;
	d[1][2] += a;
	d[2][2] += a;
	return *this;
}

Matrix3 Matrix3::operator-(float a)
{
	float aa[3][3];
	aa[0][0] = d[0][0] - a;
	aa[1][0] = d[1][0] - a;
	aa[2][0] = d[2][0] - a;
	aa[0][1] = d[0][1] - a;
	aa[1][1] = d[1][1] - a;
	aa[2][1] = d[2][1] - a;
	aa[0][2] = d[0][2] - a; 
	aa[1][2] = d[1][2] - a;
	aa[2][2] = d[2][2] - a;
	return Matrix3(aa);
}

Matrix3& Matrix3::operator-=(float a)
{
	d[0][0] -= a;
	d[1][0] -= a;
	d[2][0] -= a;
	d[0][1] -= a;
	d[1][1] -= a;
	d[2][1] -= a;
	d[0][2] -= a;
	d[1][2] -= a;
	d[2][2] -= a;
	return *this;
}

Matrix3 Matrix3::transpose() const
{
	 Matrix3 t;
     for (uint r = 0; r < 3; r++)
     {
		 for (uint c = 0; c < 3; c++)
		 {
			 t[r][c] = d[c][r];
		 }
     }
	return t;
}

void Matrix3::transposeSelf()
{
	float temp;
	temp = this->d[0][1];
	d[0][1] = d[1][0];
	d[1][0] = temp;
	temp = d[0][2];
	d[0][2] = d[2][0];
	d[2][0] = temp;
	temp = d[1][2];
	d[1][2] = d[2][1];
	d[2][1] = temp;
}

float Matrix3::det() const
{
	return(d[0][0]*(d[1][1]*d[2][2] - d[1][2]*d[2][1]) +
			d[0][1]*(d[1][2]*d[2][0] -  d[1][0]*d[2][2]) +
			d[0][2]*(d[1][0]*d[2][1] - d[1][1]*d[2][0]));
}

bool Matrix3::inverse(Matrix3& rkInverse, float fTolerance) const
{
	//Ogre Algorithm
	//uses cofacters 8x faster than Numerical Recipices Algorithm

	rkInverse[0][0] = d[1][1]*d[2][2] -
            d[1][2]*d[2][1];
        rkInverse[0][1] = d[0][2]*d[2][1] -
            d[0][1]*d[2][2];
        rkInverse[0][2] = d[0][1]*d[1][2] -
            d[0][2]*d[1][1];
        rkInverse[1][0] = d[1][2]*d[2][0] -
            d[1][0]*d[2][2];
        rkInverse[1][1] = d[0][0]*d[2][2] -
            d[0][2]*d[2][0];
        rkInverse[1][2] = d[0][2]*d[1][0] -
            d[0][0]*d[1][2];
        rkInverse[2][0] = d[1][0]*d[2][1] -
            d[1][1]*d[2][0];
        rkInverse[2][1] = d[0][1]*d[2][0] -
            d[0][0]*d[2][1];
        rkInverse[2][2] = d[0][0]*d[1][1] -
            d[0][1]*d[1][0];

        float fDet =
            d[0][0]*rkInverse[0][0] +
            d[0][1]*rkInverse[1][0]+
            d[0][2]*rkInverse[2][0];

		if ( abs(fDet) <= fTolerance )
            return false;

        float fInvDet = 1.0/fDet;
        for (size_t iRow = 0; iRow < 3; iRow++)
        {
            for (size_t iCol = 0; iCol < 3; iCol++)
                rkInverse[iRow][iCol] *= fInvDet;
        }

        return true;
}

void Matrix3::ortho()
{
	// Gram-Schmidt orthogonalization.  

	float ilen = 1.0f/sqrt(d[0][0]*d[0][0] + d[1][0]*d[1][0] + d[2][0]);
	d[0][0]*=ilen;
	d[1][0]*=ilen;
	d[2][0]*=ilen;

	float dot1 = d[0][0]*d[0][1] + d[1][0]*d[1][1] + d[2][0]*d[2][1];

	d[0][1] -= dot1*d[0][0];
	d[1][1] -= dot1*d[1][0];
	d[2][1] -= dot1*d[2][0];

	float ilen1 = 1.0f/sqrt(d[0][1]*d[0][1] + d[1][1]*d[1][1] + d[2][1]*d[2][1]);

	d[0][1] *= ilen1;
	d[1][1] *= ilen1;
	d[2][1] *= ilen1;

	float dot2 = d[0][0]*d[0][2] + d[1][0]*d[1][2] + d[2][0]*d[2][2];
	float dot3 = d[0][1]*d[0][2] + d[1][1]*d[1][2] + d[2][1]*d[2][2];

	d[0][2] -= dot2*d[0][0] - dot3*d[0][1];
	d[1][2] -= dot2*d[1][0] - dot3*d[1][1];
	d[2][2] -= dot2*d[2][0] - dot3*d[2][1];

	float ilen2 = 1.0f/sqrt(d[0][2]*d[0][2] + d[1][2]*d[1][2] + d[2][2]);

	d[0][2] *= ilen2;
	d[1][2] *= ilen2;
	d[2][2] *= ilen2;

}

Vector3 Matrix3::getColumn(uint col)
{
	if(col < 0 || col > 2)
	{
		return Vector3::NANV;
	}

	return Vector3(d[0][col],d[1][col],d[2][col]);
}

void Matrix3::setColumn(Vector3& col, uint index)
{
	if(!(index < 0 || index > 2))
	{
		d[0][index] = col.x;
		d[1][index] = col.y;
		d[2][index] = col.z;
	}
}

Vector3 Matrix3::operator*(const Vector3& v) const
{
	return Vector3(d[0][0]*v.x + d[0][1]*v.y + d[0][2]*v.z,
				   d[1][0]*v.x + d[1][1]*v.y + d[1][2]*v.z,
				   d[2][0]*v.x + d[2][1]*v.y + d[2][2]*v.z);
}

void Matrix3::setAxes(Vector3& x,Vector3& y, Vector3& z)
{
	setColumn(x,0);
	setColumn(y,1);
	setColumn(z,2);
}

Matrix3& Matrix3::fromAxisAngle(const Vector3& a, float rad)
{
	float fCos = cosf(rad);
    float fSin = sinf(rad);
    float fOneMinusCos = ((float)1.0)-fCos;
    float fX2 = a[0]*a[0];
    float fY2 = a[1]*a[1];
    float fZ2 = a[2]*a[2];
    float fXYM = a[0]*a[1]*fOneMinusCos;
    float fXZM = a[0]*a[2]*fOneMinusCos;
    float fYZM = a[1]*a[2]*fOneMinusCos;
    float fXSin = a[0]*fSin;
    float fYSin = a[1]*fSin;
    float fZSin = a[2]*fSin;
    
    d[0][0] = fX2*fOneMinusCos+fCos;
    d[0][1] = fXYM-fZSin;
    d[0][2] = fXZM+fYSin;
    d[1][0] = fXYM+fZSin;
    d[1][1] = fY2*fOneMinusCos+fCos;
    d[1][2] = fYZM-fXSin;
    d[2][0] = fXZM-fYSin;
    d[2][1] = fYZM+fXSin;
    d[2][2] = fZ2*fOneMinusCos+fCos;

    return *this;

}