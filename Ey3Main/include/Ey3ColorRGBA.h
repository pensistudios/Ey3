/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3ColorRGBA.h
/*	Class: ColorRGBA
/*	Definition: Represents a color value with alpha compenent
/*  Functionality: A red green blue alpha color
******************************************************************/

#ifndef _EY3COLORRGBA_H_
#define _EY3COLORRGBA_H_

#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export ColorRGBA
{

public:
	float r, g, b, a;
	mutable float arr[4];

	ColorRGBA() : r(0), g(0), b(0), a(0) {}
	
	ColorRGBA(float rr, float gg, float bb, float aa);

	ColorRGBA(uchar rr, uchar gg, uchar bb, uchar aa);
	
	~ColorRGBA() {}

	operator const float* () const
	{
		arr[0] = r;
		arr[1] = g;
		arr[2] = b;
		arr[3] = a;
		return arr;
	}

	static const ColorRGBA WHITE;
	static const ColorRGBA BLACK;
};

};

#endif