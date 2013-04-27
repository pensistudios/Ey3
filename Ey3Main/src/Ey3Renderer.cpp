#include "Ey3Renderer.h"
#include "Ey3SceneNode.h"
#include "Ey3SimpleGeometry.h"
#include "Ey3Camera.h"

using namespace Ey3;

Renderer::Renderer(int wwidth, int hheight)
{
	width = wwidth;
	height = hheight;
	camera = 0;
}

void Renderer::resize(int w, int h)
{
	width = w;
	height = h;
	onViewPortChange();
}

void Renderer::toggleFullscreen()
{
	fullscreen=(fullscreen)?false:true;
}

/*bool Renderer::BeginRender()
{
	return true;
}

void Renderer::EndRender()
{

}*/

void Renderer::setBackgroundColor(ColorRGB& color)
{
	backgroundColor = color;
}

const ColorRGB& Renderer::getBackgroundColor() const
{
	return backgroundColor;
}

Renderer::~Renderer()
{

}

void Renderer::drawScene(Ey3::SceneNode *root)
{
	if(root)
	{
		clearBuffers();
		draw(root);		
	}

}

void Renderer::draw(Ey3::RenderObject *node)
{
	if(node->_type == RenderObject::SG_NODE)
	{
		SceneNode* nptr = dynamic_cast<SceneNode*>(node);
		for(int i = 0; i < nptr->getNumChild(); i++)
		{
			draw(nptr->getChild(i));
		}
	}
	else if(node->_type == RenderObject::SG_GEOMETRY)
	{
		drawSimple(dynamic_cast<SimpleGeometry*>(node));
	}
}

void Renderer::setCamera(Camera* cam)
{
	if(camera)
		camera->_activeRenderer = 0;

	if(cam)	
		cam->_activeRenderer = this;

	camera = cam;
	onFrameChange();
	onFrustumChange();
	onViewPortChange();
}

Camera* Renderer::getCamera()
{
	return camera;
}