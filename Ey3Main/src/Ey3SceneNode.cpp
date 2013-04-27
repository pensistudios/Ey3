#include "Ey3SceneNode.h"

using namespace Ey3;

SceneNode::SceneNode(uint num)
{

	_type = SG_NODE;

    numChild = num;

	childList.resize(numChild);
}
	
SceneNode::~SceneNode()
{
    for(uint i = 0; i < numChild; i++)
    {
        if (childList[i])
            childList[i]->setParent(0);
	}
}

void SceneNode::setChild(unsigned int index, RenderObject* child)
{
    if (childList[index])
        childList[index]->setParent(0);
    
    
    if (child)
        child->setParent(this);
    
    // set the new child
    childList[index] = child;
}  



void SceneNode::updateWorldTransform()
{
	RenderObject::updateWorldTransform();
    
    unsigned int i;
    for ( i = 0; i < numChild; i++ )
    {
        if (childList[i])
		{
            childList[i]->updateWorldTransform();
		}
    }
    
}

void SceneNode::updateWorldBound()
{
	uint i;
	for ( i = 0; i < numChild; i++ )
    {
        if (childList[i])
        {
            worldCullVolume = childList[i]->worldCullVolume;
            break;
        }
    }

    for ( ; i < numChild; i++ )
    {
        if (childList[i])
        {
			worldCullVolume.growToContain(
				dynamic_cast<BoundingVolume*>(&childList[i]->worldCullVolume));   
         
        }
    }
}