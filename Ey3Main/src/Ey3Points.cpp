#include "Ey3Points.h"

using namespace Ey3;

Points::Points(VectorList verts)
    :
    Geometry(verts)
{
    type = POINTS;

    int quantity = (int)vertices.size();
    activeQuantity = quantity;

    for (int i = 0; i < quantity; i++)
        indices[i] = i;
}

Points::Points()
{
    type = POINTS;
    activeQuantity = 0;
}

Points::~Points()
{
}

void Points::setActiveQuantity (int iActiveQuantity)
{
    int quantity = (int)vertices.size();
    if ( 0 <= iActiveQuantity && iActiveQuantity <= quantity )
        activeQuantity = iActiveQuantity;
    else
       activeQuantity = quantity;

    //Indices->SetActiveQuantity(m_iActiveQuantity);
	indices.resize(activeQuantity);
}