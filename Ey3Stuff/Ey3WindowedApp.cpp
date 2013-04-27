#include "Ey3WindowedApp.h"

using namespace Ey3;


WindowedApp::WindowedApp (const char* acWindowTitle,
    int iXPosition, int iYPosition, int iWidth, int iHeight,
    const ColorRGB& rkBackgroundColor)
    :
    windowTitle(acWindowTitle),
    xPos(iXPosition),
    yPos(iYPosition),
    width(iWidth),
    height(iHeight),
    backgroundColor(rkBackgroundColor)
{
    windowID = 0;
    _renderer = 0;
}

WindowedApp::~WindowedApp ()
{
}

int WindowedApp::Main (int iQuantity, char** apcArgument)
{
    WindowedApp* pkTheApp = (WindowedApp*)theApp;
    return pkTheApp->doMain(iQuantity,apcArgument);
}

bool WindowedApp::onInitialize ()
{
    _renderer->setBackgroundColor(backgroundColor);
    return true;
}

void WindowedApp::onTerminate ()
{
    delete _renderer;
    _renderer = 0;
}

void WindowedApp::onMove(int iX, int iY)
{
    xPos = iX;
    yPos = iY;
}

void WindowedApp::onResize (int iWidth, int iHeight)
{
    if ( iWidth > 0 && iHeight > 0 )
    {
        if ( _renderer )
            _renderer->resize(iWidth,iHeight);

        width = iWidth;
        height = iHeight;
    }
}

bool WindowedApp::onKeyDown (unsigned char ucKey, int, int)
{
    // quit application if the ESCAPE key is pressed
    if ( ucKey == KEY_ESCAPE )
    {
        requestTermination();
        return true;
    }

    return false;
}




inline const char* WindowedApp::getWindowTitle () const
{
    return windowTitle;
}

inline int WindowedApp::getXPosition () const
{
    return xPos;
}

inline int WindowedApp::getYPosition () const
{
    return yPos;
}

inline int WindowedApp::getWidth () const
{
    return width;
}

inline int WindowedApp::getHeight () const
{
    return height;
}

inline void WindowedApp::setRenderer (Renderer* renderer)
{
    _renderer = renderer;
}

inline void WindowedApp::setWindowID (int iWindowID)
{
    windowID = iWindowID;
}

inline int WindowedApp::getWindowID () const
{
    return windowID;
}

inline bool WindowedApp::onPrecreate ()
{
    return true;
}

inline void WindowedApp::onDisplay ()
{

}

inline void WindowedApp::onIdle ()
{

}

inline bool WindowedApp::onKeyUp (unsigned char, int, int)
{
    return false;
}

inline bool WindowedApp::onSpecialKeyDown (int, int, int)
{
    return false;
}

inline bool WindowedApp::onSpecialKeyUp (int, int, int)
{
    return false;
}

inline bool WindowedApp::onMouseClick (int, int, int, int, unsigned int)
{
    return false;
}

inline bool WindowedApp::onMotion (int, int, int)
{
    return false;
}

inline bool WindowedApp::onPassiveMotion (int, int)
{
    return false;
}
