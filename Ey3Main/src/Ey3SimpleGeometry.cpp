#include "Ey3SimpleGeometry.h"
#include "Ey3ColorRGB.h"

using namespace Ey3;

SimpleGeometry::SimpleGeometry()
{
    verts = 0;
    norms = 0;
    colors = 0;
    numVerts = 0;

    mIndices = 0;
    numIndices = 0;
	_type = SG_GEOMETRY;
} 

SimpleGeometry::~SimpleGeometry()
{
    delete[] verts;
    delete[] norms;
    delete[] colors;

    delete[] mIndices;

}  

SimpleGeometry* SimpleGeometry::createFromStream(std::istream& in)
{
	SimpleGeometry* geom = new SimpleGeometry();

	in >> geom->numVerts;

	geom->verts = new Vector3[geom->numVerts];
	
	for(int i = 0; i < geom->numVerts; i++)
	{
		 in >> geom->verts[i].x >> geom->verts[i].y 
            >> geom->verts[i].z;
	}

	geom->norms = new Vector3[geom->numVerts];
    for (int i = 0; i < geom->numVerts; i++)
    {
        in >> geom->norms[i].x >> geom->norms[i].y 
            >> geom->norms[i].z;
    }

    geom->colors = new ColorRGB[geom->numVerts];
    for (int i = 0; i < geom->numVerts; i++)
    {
        in >> geom->colors[i].r >> geom->colors[i].g 
			>> geom->colors[i].b;
    }

    in >> geom->numIndices;

    geom->mIndices = new uint[geom->numIndices];
    for (int i = 0; i < geom->numIndices; i++)
    {
        in >> geom->mIndices[i];
    }

	
    // initialize the model-space capsule to the vertex data
    //geom->mModelCapsule.Set( geom->mVerts, geom->mNumVerts );

    return geom;


}

void SimpleGeometry::updateWorldBound()
{

}

void SimpleGeometry::render(Renderer& ren)
{

}

void SimpleGeometry::updateWorldTransform()
{
	RenderObject::updateWorldTransform();
	 
	/*char buf[100];
	Vector3 t = world.getTranslate();
	sprintf(buf,"WORLDTRANSFORM %f %f %f", t.x,t.y,t.z);
	//sprintf(buf, "WORLD TRANSFORM : %f %f %f", 
	//	world.getTranslate().x,
	//	world.getTranslate().y,
	//	world.getTranslate().z);
	LOG(buf);
	*/
	Vector3 b,a;
	for(int i = 0; i < numVerts; i++)
	{
		b = verts[i];
		verts[i] = world.applyForward(verts[i]);
		a = verts[i];
		/*sprintf(buf,"Before: %f %f %f After: %f %f %f",b.x,b.y,b.z,
			a.x,a.y,a.z);
		LOG(buf);*/
	} 
}