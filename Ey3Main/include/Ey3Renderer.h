/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Renderer.h
/*	Class: Renderer
/*	Definition: Abstract base renderer
/*  Functionality: Manages scene graph traversal rendering
******************************************************************/

#ifndef _EY3RENDERER_H_
#define _EY3RENDERER_H_

#include "Ey3Def.h"
#include "Ey3ColorRGB.h"
#include "Ey3ColorRGBA.h"
#include "Ey3Logging.h"

namespace Ey3
{
	class Camera;
	class SceneQueue;
	class SceneNode;
	class RenderObject;
	class SimpleGeometry;

class Ey3Export Renderer 
{
public:

	virtual ~Renderer();

	enum APIType
	{
		OPENGL,
		DIRECTX
	};

	APIType _type;

	virtual void setCamera(Camera* cam);
	virtual Camera* getCamera();

	int getWidth() const { return width; }
	int getHeight() const {return height; }

	virtual void resize(int width, int height);
	virtual void toggleFullscreen();

	virtual void setBackgroundColor(ColorRGB& c); 
	const ColorRGB& getBackgroundColor() const;

    //virtual bool BeginRender()=0;
    //virtual void EndRender()=0;

    //Buffer Operations
    virtual void clearBackBuffer () = 0;
    virtual void clearZBuffer () = 0;
    virtual void clearStencilBuffer () = 0;
    virtual void clearBuffers () = 0;
    virtual void displayBackBuffer () = 0;

	virtual void onFrustumChange() = 0;
    virtual void onViewPortChange() = 0;
    virtual void onFrameChange() = 0;

	virtual void drawSimple(SimpleGeometry* simple)=0; //simplest form of drawing

	virtual void drawScene(SceneNode* root); //Using Basic SceneGraph

    // object drawing
    virtual void draw(RenderObject* node);
 
protected:

	Renderer (int iWidth, int iHeight);

	virtual void setWorldTransformation() = 0;
    virtual void restoreWorldTransformation() = 0;
    virtual void setScreenTransformation() = 0;
    virtual void restoreScreenTransformation() = 0;
	
	int width, height;
    ColorRGB backgroundColor;

	Camera* camera;
	
	SceneQueue* queue;

	int maxLights;
	int maxTextures;

	bool fullscreen;


};

};

#endif