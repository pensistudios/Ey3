/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Def.h
/*  Functionality: Engine Definition file. Provides useful 
/*	Macros, Strings, Constants and class declrations to minimize 
/*	header dependencies. Every file has access to this file.
******************************************************************/

#ifndef _EY3DEF_H_
#define _EY3DEF_H_

#include "Ey3StdH.h"
#include "Ey3Platform.h"

//MSVC Specific
#pragma warning (disable : 4786)
#pragma warning (disable : 4503)
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#pragma warning (disable : 4251)
#pragma warning (disable : 4275)
#pragma warning (disable : 4290)
#pragma warning (disable : 4996)
#pragma warning (disable : 4661)
#pragma warning (disable : 4018)
//End MSVC Specifics

namespace Ey3
{
	#define EY3_MAJOR_VERSION 1
	#define EY3_MINOR_VERSION 0
	#define EY3_PATCH_VERSION 1
	#define EY3_VERSION_NAME "Energy"

	typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
	typedef unsigned long ulong;
	
	//STL
	typedef std::string Str;
	typedef std::ofstream StdStreamOut;

	const static float nanF = sqrtf(-1.0f);
	const static double nanD = sqrt(-1.0);
	const static float EPSILON = 1e-06;

	#define SAFE_DELETE(p) { if(p) { delete (p); (p)=NULL;}}
	#define SAFE_ADELETE(p) {if(p) { delete[] (p); (p)=NULL;}}
	
	//TODO:predefine classes here
	//and add any other macros and good stuff here
	
	class Radian;
	class Degree;
	class Vector3;
	class Vector4;
	class Vector2;
	class EulerAngles;
	class RenderObject;
	class Matrix3;
	class RotationMatrix;
	class Quaternion;
	class Line3;
	class Plane;
	class Sphere;
	class Log;
	class LogManager;
	class Core;
	class Quaternion;
	


};

#endif