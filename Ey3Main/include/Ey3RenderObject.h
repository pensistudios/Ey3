/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3RenderObject.h
/*	Class: RenderObject
/*  Definition: Abstract Base Class for all objects that will be
/*  rendered to inheirit from 
/*  Functionality: Used in the SceneGraph 
******************************************************************/

#ifndef _EY3RENDEROBJECT_H_
#define _EY3RENDEROBJECT_H_

#include "Ey3Transformation.h"
#include "Ey3Logging.h"
#include "Ey3BVSphere.h"

namespace Ey3
{
class Renderer;

class Ey3Export RenderObject
{
public:

	virtual ~RenderObject() {}

	enum SceneGraphType
	{
		SG_NODE,
		SG_GEOMETRY
	};

	SceneGraphType _type;

	Transformation local;
	Transformation world;
	bool needsUpdating;

	BVSphere worldCullVolume;

	RenderObject* getParent() { return _parent; }
	void setParent(RenderObject* r) { _parent = r; }

	virtual void updateWorldTransform();
	virtual void updateWorldBound()=0;

	virtual void render(Renderer& renderer) = 0;


protected:
	
	RenderObject() 
	{
		_parent = 0;
		local.makeIdentity();
		world.makeIdentity();
		needsUpdating = true;
	}

	 RenderObject* _parent;



};

typedef std::vector<RenderObject*> RenderObjectList;

};

#endif
