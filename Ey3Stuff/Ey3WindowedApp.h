#ifndef _EY3WINDOWEDAPP_H_
#define _EY3WINDOWEDAPP_H_

#include "Ey3App.h"
#include "Ey3ColorRGB.h"
#include "Ey3Renderer.h"

namespace Ey3
{

class Ey3Export WindowedApp : public App
{
public:
    WindowedApp(const char* windowTitle, int xPosition,
        int yPosition, int iwidth, int iheight,
        const ColorRGB& backgroundColor);
    virtual ~WindowedApp();

    // Entry point to be implemented by the application.  The return value
    // is an exit code, if desired.
    virtual int doMain(int iQuantity, char** apcArgument)=0;

    // member access
    const char* getWindowTitle () const;
    int getXPosition () const;
    int getYPosition () const;
    int getWidth () const;
    int getHeight () const;
    void setRenderer (Renderer* pkRenderer);
    void setWindowID (int iWindowID);
    int getWindowID () const;

    // event callbacks
    virtual bool onPrecreate ();
    virtual bool onInitialize ();
    virtual void onTerminate ();
    virtual void onMove (int iX, int iY);
    virtual void onResize (int iWidth, int iHeight);
    virtual void onDisplay ();
    virtual void onIdle ();
    virtual bool onKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool onKeyUp (unsigned char ucKey, int iX, int iY);
    virtual bool onSpecialKeyDown (int iKey, int iX, int iY);
    virtual bool onSpecialKeyUp (int iKey, int iX, int iY);
    virtual bool onMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool onMotion (int iButton, int iX, int iY);
    virtual bool onPassiveMotion (int iX, int iY);

    virtual void requestTermination ()=0;

    // Font information.  These are platform-specific, so classes that
    // implement the WindowApplication interfaces must implement these
    // functions.  They are not defined by WindowApplication.
  /*  int getStringWidth (const char* acText) const;
    int getCharWidth (const char cCharacter) const;
    int getFontHeight () const;
*/
    static const int KEY_ESCAPE;
    static const int KEY_LEFT_ARROW;
    static const int KEY_RIGHT_ARROW;
    static const int KEY_UP_ARROW;
    static const int KEY_DOWN_ARROW;
    static const int KEY_HOME;
    static const int KEY_END;
    static const int KEY_PAGE_UP;
    static const int KEY_PAGE_DOWN;
    static const int KEY_INSERT;
    static const int KEY_DELETE;
    static const int KEY_F1;
    static const int KEY_F2;
    static const int KEY_F3;
    static const int KEY_F4;
    static const int KEY_F5;
    static const int KEY_F6;
    static const int KEY_F7;
    static const int KEY_F8;
    static const int KEY_F9;
    static const int KEY_F10;
    static const int KEY_F11;
    static const int KEY_F12;

    // keyboard modifiers
    static const int KEY_SHIFT;
    static const int KEY_CONTROL;
    static const int KEY_ALT;
    static const int KEY_COMMAND;

    // mouse buttons
    static const int MOUSE_LEFT_BUTTON;
    static const int MOUSE_MIDDLE_BUTTON;
    static const int MOUSE_RIGHT_BUTTON;

    // mouse state
    static const int MOUSE_UP;
    static const int MOUSE_DOWN;

    // mouse modifiers
    static const int MODIFIER_CONTROL;
    static const int MODIFIER_LBUTTON;
    static const int MODIFIER_MBUTTON;
    static const int MODIFIER_RBUTTON;
    static const int MODIFIER_SHIFT;

protected:
    // The hookup to the 'main' entry point into the executable.
    static int Main(int iQuantity, char** apcArgument);

    // constructor inputs
    const char* windowTitle;
    int xPos, yPos, width, height;
    ColorRGB backgroundColor;

    // an identifier for the window (representation is platform-specific)
    int windowID;

    // the renderer (used for 2D and 3D applications)
    Renderer* _renderer;


};


};


#endif