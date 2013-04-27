/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Points.h
/*	Class: Points
/*	Definition: Represents geometric points
/*  Functionality: not yet used
******************************************************************/

#ifndef _EY3POINTS_H_
#define _EY3POINTS_H_

#include "Ey3Geometry.h"

namespace Ey3
{

class Ey3Export Points : public Geometry
{
public:
    
    Points(VectorList verts);
    virtual ~Points();

    void setActiveQuantity (int iActiveQuantity);
	int getActiveQuantity () const { return activeQuantity; }

protected:
    Points ();

    // Allow application to specify fewer than the maximum number of vertices
    // to draw.
    int activeQuantity;
};


};


#endif