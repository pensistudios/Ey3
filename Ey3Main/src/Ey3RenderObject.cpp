#include "Ey3RenderObject.h"

using namespace Ey3;

void RenderObject::updateWorldTransform()
{
	if (_parent)
    {
		world.product(_parent->world,local);
    }
    else
    {
        world = local;
    }
	needsUpdating = false;
}
