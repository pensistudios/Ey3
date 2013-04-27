/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3SceneGraph.h
/*	Class: SceneGraph
/*	Definition: Encapsulated SceneGraph
/*  Functionality: Not yet used in favor of a simple scene graph
******************************************************************/

#ifndef _EY3SCENEGRAPH_H_
#define _EY3SCENEGRAPH_H_

#include "Ey3SceneNode.h"
#include "Ey3Renderer.h"

namespace Ey3
{

class Ey3Export SceneGraph
{
protected:
	Str _name;

	SceneNode* _root;

public:

	SceneGraph(const Str& name);

	virtual ~SceneGraph();

	virtual void clearScene();

	virtual void attachNode(RenderObject* node);
	virtual void detachNode(RenderObject* node);

	virtual void attachRoot(SceneNode* root);
	
	virtual void render(Renderer& ren);

};

};

#endif