/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3SceneNode.h
/*	Class: SceneNode
/*	Definition: Represents a node in the scenegraph
/*  Functionality: Used for scene graph traversal rendering
******************************************************************/

#ifndef _EY3SCENENODE_H_
#define _EY3SCENENODE_H_

#include "Ey3RenderObject.h"

namespace Ey3
{

class Ey3Export SceneNode : public RenderObject
{
public:
	SceneNode(uint numChildren);
	virtual ~SceneNode();

	virtual void updateWorldTransform();
	virtual void updateWorldBound();

	/*int attachChild(RenderObject* child);
	int detachChild(RenderObject* child);
	RenderObject* detachIdChild(int id);
	RenderObject* setChild(int i, RenderObject* child);
	RenderObject* getChild(int i);*/

	RenderObject* getChild(uint index) { return childList[index]; }
    void setChild(uint index, RenderObject* child);
	
	uint getNumChild() const {return numChild;}

	virtual void render(Renderer& render) {}

protected:
	
	RenderObjectList childList;
	uint numChild;
	
	

};


};

#endif