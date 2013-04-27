/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Image.h
/*	Class: Image
/*	Definition: Class for representing images
/*	Functionality: <warning> not used yet
******************************************************************/

#ifndef _EY3IMAGE_H_
#define _EY3IMAGE_H_

#include "Ey3Def.h"

//Inherit Resource when ResourceManagment is in place

namespace Ey3
{

class Ey3Export Image
{


	enum ImageFilter
	{
		FILTER_NEAREST,
		FILTER_LINEAR,
		FILTER_BILINEAR,
		FILTER_BOX,
		FILTER_TRIANGLE,
		FILTER_BICUBIC
	};

protected:
	
	size_t _width;	
	size_t _height;	
	size_t _depth;
	size_t _size;
	size_t _numMipmaps;
	
	// Image specific flags
	int _flags;

	// The pixel format of the image
	//PixelFormat _pformat;

	//uchar m_ucPixelSize;
	uchar* imageData;


};

};

#endif