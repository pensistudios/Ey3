#include "Ey3Geometry.h"

using namespace Ey3;

void Geometry::updateWorldBound()
{
	modelBound.transformBy(world,&worldCullVolume);
}

void Geometry::updateGeometry(bool upNorms)
{
	updateModelBound();
    if (upNorms)
        updateModelNormals();
}


void Geometry::updateModelBound ()
{
    modelBound.computeFromVerts(vertices);
}

Geometry::~Geometry()
{


}

Geometry::Geometry ()
{
	_type = SG_GEOMETRY;
}

Geometry::Geometry(VectorList l)
: vertices(l)
{
	_type = SG_GEOMETRY;
}