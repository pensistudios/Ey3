/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Geometry.h
/*	Class: Geometry
/*  Definition: Abstract Base Class; Inherits from RenderObject;
/*	Functionality: Used for representing geometry in the scenegraph
******************************************************************/

#ifndef _EY3GEOMETRY_H_
#define _EY3GEOMETRY_H_

#include "Ey3RenderObject.h"

namespace Ey3
{

class Ey3Export Geometry : public RenderObject
{
public:
	virtual ~Geometry();

	BVSphere modelBound;

	typedef std::vector<Vector3> VectorList;
	VectorList vertices;
	VectorList normals;
	typedef std::vector<int> IndexList;
	IndexList indices;

	enum GeometryType
	{
		TRIANGLE_MESH,
		LINE_SEGMENTS,
		OPEN_LINE,
		CLOSED_LINE,
		POINTS,
	};

	GeometryType type;

	virtual void updateModelBound ();
    virtual void updateModelNormals ()=0;
    virtual void updateWorldBound ();
	virtual void updateGeometry(bool updateNormals);
	virtual void render(Renderer& render) =0;

protected:
	Geometry(); //abstract
	Geometry(VectorList v);
	
	
};


};

#endif