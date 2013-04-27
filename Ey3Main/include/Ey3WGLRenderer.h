/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3WGLRenderer.h
/*	Class: WGLRenderer
/*	Definition: Renderer for the WGL system
/*  Functionality: For use of OpenGL on windows
******************************************************************/

#ifndef _EY3WGLRENDERER_H_
#define _EY3WGLRENDERER_H_

#include "Ey3OpenGLRenderer.h"

namespace Ey3
{

class Ey3Export WGLRenderer : public OpenGLRenderer
{
public:
	WGLRenderer (HWND hWnd, int w, int h);
    virtual ~WGLRenderer ();

    virtual void toggleFullscreen ();
    virtual void displayBackBuffer ();
	//virtual int  loadFont (const char* acFace, int size, bool bold,
      //  bool italic);

protected:

    HWND m_hWnd;
    HDC m_hDC;
    HGLRC m_hRC;
	HGDIOBJ m_hOldFont;

    int saveWidth;
	int saveHeight;

	bool setupPixelFormat(HDC hDC);

};


};


#endif