/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3SceneQueue.h
/*	Class: SceneQueue
/*	Definition: A queue of objects to be rendered
/*  Functionality: not yet used
******************************************************************/

#ifndef _EY3SCENEQUEUE_H_
#define _EY3SCENEQUEUE_H_

#include "Ey3RenderObject.h"

namespace Ey3
{

class Ey3Export SceneQueue
{
protected:
	
	
	RenderObjectList _list;

public:

	SceneQueue();

	virtual ~SceneQueue();

	void clear();



};

};

#endif