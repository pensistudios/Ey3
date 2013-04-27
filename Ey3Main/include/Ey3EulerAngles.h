/****************************************************************/
/*  File: Ey3EulerAngles.h
/*	Class: EulerAngles
/*  Definition: A Specific type of orientation that uses 3 values 
******************************************************************/

#ifndef _EY3EULERANGLES_H_
#define _EY3EULERANGLES_H_

#include "Ey3Math.h"

namespace Ey3
{

class Ey3Export EulerAngles 
{
public:
	Radian heading, pitch, bank;

	EulerAngles() {}
	EulerAngles(float h, float p, float b) : heading(h), pitch(p), bank(b) {  }
	EulerAngles(Radian h, Radian p, Radian b) : heading(h), pitch(p), bank(b) {}

	void zero() { heading = pitch = bank = 0.0f; }
	

};

};

#endif
