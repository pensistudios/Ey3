#include "Ey3SceneGraph.h"

using namespace Ey3;

SceneGraph::SceneGraph(const Ey3::Str &name)
: _name(name)
{
	_root = 0;
}

void SceneGraph::attachNode(RenderObject* node)
{

}

void SceneGraph::detachNode(Ey3::RenderObject *node)
{

}

void SceneGraph::clearScene()
{
	_root = 0;
}

void SceneGraph::attachRoot(Ey3::SceneNode *root)
{
	_root = root;
}

void SceneGraph::render(Renderer& ren)
{
	ren.drawScene(_root);	
}

SceneGraph::~SceneGraph()
{
}