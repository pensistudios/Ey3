/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3SimpleGeometry.h
/*	Class: SimpleGeometry
/*	Definition: Represents Simple model data in scene graph
/*	No effects or textures
/*  Functionality: Used for simple rendering
******************************************************************/

#ifndef _EY3SIMPLEGEOMETRY_H_
#define _EY3SIMPLEGEOMETRY_H_

#include "Ey3RenderObject.h"

#include <fstream>

namespace Ey3
{

class ColorRGB;

class Ey3Export SimpleGeometry : public RenderObject
{
public:
	 SimpleGeometry();
    ~SimpleGeometry();

	static SimpleGeometry* createFromStream(std::istream& in);

    //virtual void render(Renderer& renderer);
    
    Vector3* getVertices() { return verts; }
    const Vector3* getVertices() const { return verts; }
    Vector3* getNormals() { return norms; }
    const Vector3* getNormals() const { return norms; }
    ColorRGB* getColors() { return colors; }
    const ColorRGB* getColors() const { return colors; }
    unsigned int getVertexCount() const { return numVerts; }

    uint* getIndices() { return mIndices; }
    const uint* getIndices() const { return mIndices; }
    unsigned int getIndexCount() const { return numIndices; }

	virtual void updateWorldBound();
	virtual void updateWorldTransform();

	virtual void render(Renderer& ren);

public:

    Vector3* verts;
    Vector3* norms;
    ColorRGB* colors;
    uint numVerts;

    uint* mIndices;
    uint numIndices;

};

};

#endif