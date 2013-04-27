#include "Ey3WGLRenderer.h"

//#include <GL/glew.h>

using namespace Ey3;

bool WGLRenderer::setupPixelFormat(HDC hDC)
{
    int pixelFormat;

    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd,0,sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags =
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |
        PFD_GENERIC_ACCELERATED |
        PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;  // 24-bit colors for front/back buffers
    pfd.cDepthBits = 16;  // 16-bit depth buffer
    pfd.cStencilBits = 8; // 8-bit stencil buffer

    pixelFormat = ChoosePixelFormat(hDC, &pfd);
	
	if(!pixelFormat)
		return false;

    BOOL sucess = SetPixelFormat(hDC, pixelFormat, &pfd);

	if(!sucess)
		return false;

	return true;
}

WGLRenderer::WGLRenderer(HWND hWnd, int w, int h)
: OpenGLRenderer(w,h)
{
	saveWidth = w;
	saveHeight = h;

	m_hWnd = hWnd;
	m_hDC = GetDC(m_hWnd);
	
	bool result = setupPixelFormat(m_hDC);
	
	if(!result)
	{
		LERR("Pixel Format could not be established");
		return;
	}

	m_hRC = wglCreateContext(m_hDC);
    if ( !m_hRC )
	{
		LERR("WGL Context could not be created");
        return;
	}

	BOOL bSuccess = wglMakeCurrent(m_hDC,m_hRC);
    if ( !bSuccess )
	{
		LERR("WGL Context could not be made current");
        return;
	}
	
	GLenum error = glewInit();
    if ( error != GLEW_OK )
	{
		LERR("GLEW could not be initiliazed");
        return;
	}

	//do fonts 
	establishCapabilities();
	initialize();
}

WGLRenderer::~WGLRenderer ()
{
    if ( m_hRC )
        wglDeleteContext(m_hRC);

    if ( m_hDC )
    {
        SelectObject(m_hDC,m_hOldFont);
        ReleaseDC(m_hWnd,m_hDC);
    }
}

void WGLRenderer::toggleFullscreen ()
{
    OpenGLRenderer::toggleFullscreen();
    glFinish();

    DWORD dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

    UINT uiFlags = SWP_NOACTIVATE | SWP_NOOWNERZORDER |
        SWP_NOSENDCHANGING | SWP_NOZORDER;

    RECT kRect;

    if ( fullscreen )
    {
        saveWidth = width;
        saveHeight = height;
        GetWindowRect(GetDesktopWindow(),&kRect);
        AdjustWindowRect(&kRect,dwStyle,FALSE);
    }
    else
    {
        width = saveWidth;
        height = saveHeight;

        kRect.left = 0;
        kRect.top = 0;
        kRect.right = width-1;
        kRect.bottom = height-1;
        AdjustWindowRect(&kRect,dwStyle,FALSE);

        kRect.right -= kRect.left;
        kRect.left = 0;
        kRect.bottom -= kRect.top;
        kRect.top = 0;
    }

    SetWindowPos(m_hWnd,HWND_TOP,kRect.left,kRect.top,
        kRect.right-kRect.left,kRect.bottom-kRect.top,uiFlags);
}

void WGLRenderer::displayBackBuffer ()
{
    SwapBuffers(m_hDC);
}

/*int WGLRenderer::LoadFont (const char* acFace, int iSize, bool bBold,
    bool bItalic)
{
    int iWeight = ( bBold ? FW_BOLD : FW_REGULAR );
        
    HFONT hFont = CreateFont(iSize,0,0,0,iWeight,(DWORD)bItalic,FALSE,
        FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY,VARIABLE_PITCH,acFace);
    
    if ( !hFont )
        return -1;

    DisplayListInfo kInfo;
    int iFirstChar = int(' ');
    kInfo.Quantity = 127 - iFirstChar;
    kInfo.Start = glGenLists(kInfo.Quantity) ;
    kInfo.Base = kInfo.Start - iFirstChar;
    m_kDLInfo.Append(kInfo);

    SelectObject(m_hWindowDC,hFont); 
    wglUseFontBitmaps(m_hWindowDC,iFirstChar,kInfo.Quantity,kInfo.Start);
    DeleteObject(hFont);
    return DLInfo.GetQuantity()-1;
}*/