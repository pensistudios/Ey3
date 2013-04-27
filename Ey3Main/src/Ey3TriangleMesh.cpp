#include "Ey3TriangleMesh.h"

using namespace Ey3;

TriangleMesh::TriangleMesh()
{
    type = TRIANGLE_MESH;
}

TriangleMesh::TriangleMesh (VectorList verts, IndexList ind, bool genNorms)
: Geometry(verts)
{
    type = TRIANGLE_MESH;
    indices = ind;
    if ( genNorms )
        generateNormals();
}

TriangleMesh::~TriangleMesh ()
{
}

void TriangleMesh::getModelTriangle (int i, Triangle& tri) const
{
    if(indices.size() > (3*i))
	{
		LERR("TriangleMesh::getModelTriangle: More Indices than indexs");
	}
    Vector3* vert =(Vector3*) &vertices.front();
    int* aiIndex = (int*)&indices.front();
    int* piIndex = &aiIndex[3*i];
    tri.v[0] = vert[*piIndex++];
    tri.v[1] = vert[*piIndex++];
    tri.v[2] = vert[*piIndex];
}

void TriangleMesh::getWorldTriangle (int i, Triangle& tri) const
{
    if(indices.size() > (3*i))
	{
		LERR("TriangleMesh::getWorldTriangle: More Indices than indexs");
	}
    Vector3* akVertex = (Vector3*)&vertices.front();
    int* aiIndex = (int*)&indices.front();
    int* piIndex = &aiIndex[3*i];
    tri.v[0] = world.applyForward(akVertex[*piIndex++]);
    tri.v[1] = world.applyForward(akVertex[*piIndex++]);
    tri.v[2] = world.applyForward(akVertex[*piIndex  ]);
}

void TriangleMesh::generateNormals ()
{
    int iVQuantity;

    if ( normals.size() == 0 )
    {
        iVQuantity =(int) vertices.size();      
        normals.resize(iVQuantity);
        updateModelNormals();
    }
    else
    {
        updateModelNormals();
    }
}

void TriangleMesh::updateModelNormals()
{
    if (normals.size() == 0)
        return;

    int iVQuantity = (int)vertices.size();
    Vector3* akVertex = (Vector3*)&vertices.front();
    Vector3* akNormal = (Vector3*)&normals.front();
    normals.clear();

    int iTQuantity = (int)indices.size()/3;
    int* piIndex = (int*)&indices.front();
    int i;
    for (i = 0; i < iTQuantity; i++)
    {
        // get vertex indices
        int iV0 = *piIndex++;
        int iV1 = *piIndex++;
        int iV2 = *piIndex++;

        // get vertices
        Vector3& rkV0 = akVertex[iV0];
        Vector3& rkV1 = akVertex[iV1];
        Vector3& rkV2 = akVertex[iV2];

        // compute the normal (length provides the weighted sum)
        Vector3 kEdge1 = rkV1 - rkV0;
        Vector3 kEdge2 = rkV2 - rkV0;
		Vector3 kNormal = Ey3::crossProduct(kEdge1,kEdge2);

        akNormal[iV0] += kNormal;
        akNormal[iV1] += kNormal;
        akNormal[iV2] += kNormal;
    }

    for (i = 0; i < iVQuantity; i++)
        akNormal[i].normalize();
}