/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3ColorRGB.h
/*	Class: ColorRGB
/*	Definition: Represents a color value
/*  Functionality: A red green blue color
******************************************************************/

#ifndef _EY3COLORRGB_H_
#define _EY3COLORRGB_H_

#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export ColorRGB
{

public:
	float r, g, b;

	ColorRGB() : r(0), g(0), b(0) {}
	
	ColorRGB(float rr, float gg, float bb);

	ColorRGB(uchar rr, uchar gg, uchar bb);
	
	ColorRGB& operator=(const ColorRGB& c)
	{
		r = c.r; g = c.g; b = c.b;
		return *this;
	}

	~ColorRGB() {}
};

};

#endif