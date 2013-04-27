#include "Ey3.h"

using namespace Ey3;

void main()
{
	Ey3::Core* core = new Ey3::Core();
	core->init();
	
	std::ifstream tankFile("Tank.txt");
	Ey3::SimpleGeometry* tankGeom = Ey3::SimpleGeometry::createFromStream(tankFile);

	std::ifstream turretFile("Turret.txt");
    Ey3::SimpleGeometry* turretGeom = Ey3::SimpleGeometry::createFromStream(turretFile);

	std::ifstream barrelFile("Barrel.txt");
    Ey3::SimpleGeometry* barrelGeom = Ey3::SimpleGeometry::createFromStream(barrelFile);
	
	Ey3::RenderObject* barrel = barrelGeom;
	barrel->local.setTranslate(Ey3::Vector3(4.5f,0.0f,1.0f));
	Ey3::RenderObject* turret = new Ey3::SceneNode(2);
	turret->local.setTranslate(Ey3::Vector3(0.75,0.0f,3.55f));
	((Ey3::SceneNode*)turret)->setChild(0, turretGeom);
	((Ey3::SceneNode*)turret)->setChild(1, barrel);

	Ey3::RenderObject* tank = new Ey3::SceneNode(2);
	((Ey3::SceneNode*)tank)->setChild(0, tankGeom);
	((Ey3::SceneNode*)tank)->setChild(1, turret);

	tank->local.setUniformScale(0.25f);
	tank->updateWorldTransform();

	
	for(int i = 0; i < tankGeom->getVertexCount(); i++)
	{
		
	std::cout << ((Ey3::SimpleGeometry*)((Ey3::SceneNode*)tank)->getChild(0))->verts[0].x << "\n";
	std::cout << ((Ey3::SimpleGeometry*)((Ey3::SceneNode*)tank)->getChild(0))->verts[0].y << "\n";
	std::cout << ((Ey3::SimpleGeometry*)((Ey3::SceneNode*)tank)->getChild(0))->verts[0].z << "\n";

	system("PAUSE");
	delete core;
}