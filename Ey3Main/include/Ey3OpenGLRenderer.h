/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3OpenGLRenderer.h
/*	Class: OpenGLRenderer
/*	Definition: Inherits from renderer; Uses the OpenGL API to 
/*	render scenes
/*  Functionality: Used to render scenes on the graphics card
******************************************************************/

#ifndef _EY3OPENGLRENDERER_H_
#define _EY3OPENGLRENDERER_H_

#include "Ey3Renderer.h"
#include "Ey3Matrix4.h"

#if EY3_PLATFORM == EY3_WINDOWS
#define WIN32_LEAN_AND_MEAN		
#include <windows.h>
#include<GL/glew.h>
#endif

namespace Ey3
{

class Ey3Export OpenGLRenderer : public Renderer
{
public:
	static const char* getVendor();
    static const char* getRenderer();
    static const char* getVersion();
    static const char* getGluVersion();
    static const char* getExtensions();

	virtual ~OpenGLRenderer();
	
	static bool isMinimumVersion (int major, int minor, int release);

    static bool extensionSupported (const char* ext_name);

	virtual void establishCapabilities ();

	virtual void initialize();

	//virtual bool BeginRender()=0;
    //virtual void EndRender()=0;
	
	virtual void setBackgroundColor(ColorRGB& c);

	virtual void clearBackBuffer();
	virtual void clearZBuffer();
	virtual void clearStencilBuffer();
	virtual void clearBuffers();
	virtual void displayBackBuffer() = 0;

	virtual void clearBackBuffer (int xPos, int yPos, int iwidth, 
		int iheight);
    virtual void clearZBuffer (int xPos, int yPos, int iwidth,
        int iheight);
    virtual void clearStencilBuffer (int xPos, int yPos, int iwidth,
        int iheight);
    virtual void clearBuffers (int xPos, int yPos, int iwidth,
        int iheight);

	virtual void drawSimple(SimpleGeometry* simple);

protected:
	OpenGLRenderer(int w,int h);

	virtual void onFrustumChange();
	virtual void onViewPortChange();
	virtual void onFrameChange();

	virtual void setWorldTransformation();
	virtual void restoreWorldTransformation();
	virtual void setScreenTransformation();
	virtual void restoreScreenTransformation();

	Matrix4 viewMatrix;
	Matrix4 worldMatrix;
	Matrix4 textureMatrix;

	int maxStencilIndices;

};


};

#endif