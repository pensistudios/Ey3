/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3TriangleMesh.h
/*	Class: TriangleMesh
/*	Definition: Represents a mesh of triangles
/*  Functionality: Most models are triangle meshes
******************************************************************/

#ifndef _EY3TRIANGLEMESH_H_
#define _EY3TRIANGLEMESH_H_

#include "Ey3Geometry.h"
#include "Ey3Triangle.h"

namespace Ey3
{

class Ey3Export TriangleMesh : Geometry
{
public:
	
	TriangleMesh(VectorList vertices, IndexList indices, bool genNorms);

	virtual ~TriangleMesh();

	int getTriangleQuantity() const;
    void getModelTriangle(int i, Triangle& model) const;
    void getWorldTriangle(int i, Triangle& world) const;

	void generateNormals();

protected:
	TriangleMesh();

	 virtual void updateModelNormals ();


};

//TODO COde could be buggy watch out
};

#endif