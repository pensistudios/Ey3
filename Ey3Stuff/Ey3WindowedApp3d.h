#ifndef _EY3WINDOWEDAPP3D_H_
#define _EY3WINDOWEDAPP3D_H_

#include "Ey3WindowedApp.h"
#include "Ey3Vector3.h"
#include "Ey3Matrix3.h"
#include "Ey3Camera.h"

namespace Ey3
{

class Ey3Export WindowedApp3d : public WindowedApp
{
	WindowedApp3d (const char* acWindowTitle, int iXPosition,
        int iYPosition, int iWidth, int iHeight,
        const ColorRGB& rkBackgroundColor);

    virtual ~WindowedApp3d ();

    // event callbacks
    virtual bool onInitialize ();
    virtual void onTerminate ();
    virtual void onDisplay ();
    virtual bool onKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool onSpecialKeyDown (int iKey, int iX, int iY);
    virtual bool onSpecialKeyUp (int iKey, int iX, int iY);
    virtual bool onMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool onMotion (int iButton, int iX, int iY);

protected:
    // camera motion
    void initializeCameraMotion (float fTrnSpeed, float fRotSpeed,
        float fTrnSpeedFactor = 2.0f, float fRotSpeedFactor = 2.0f);
    virtual bool moveCamera ();
    virtual void moveForward ();
    virtual void moveBackward ();
    virtual void moveUp ();
    virtual void moveDown ();
    virtual void turnLeft ();
    virtual void turnRight ();
    virtual void lookUp ();
    virtual void lookDown ();
    
	Camera* _camera;

    Vector3 worldAxis[3];

    float m_fTrnSpeed, m_fTrnSpeedFactor;
    float m_fRotSpeed, m_fRotSpeedFactor;
    bool m_bUArrowPressed;
    bool m_bDArrowPressed;
    bool m_bLArrowPressed;
    bool m_bRArrowPressed;
    bool m_bPgUpPressed;
    bool m_bPgDnPressed;
    bool m_bHomePressed;
    bool m_bEndPressed;
    bool m_bCameraMoveable;

    // object motion
    void initializeObjectMotion (RenderObject* pkMotionObject);
    bool moveObject ();
    //void rotateTrackBall (float fX0, float fY0, float fX1, float fY1);
    RenderObject* motionObject;
    int m_iDoRoll, m_iDoYaw, m_iDoPitch;
    float m_fXTrack0, m_fYTrack0, m_fXTrack1, m_fYTrack1;
    Matrix3 m_kSaveRotate;
    bool m_bUseTrackBall, m_bTrackBallDown;
    bool m_bObjectMoveable;

    // performance measurements
   /* void resetTime ();
    void measureTime ();
    void updateFrameCount ();
    void drawFrameRate (int iX, int iY, const ColorRGBA& rkColor);
    double m_dLastTime, m_dAccumulatedTime, m_dFrameRate;
    int m_iFrameCount, m_iTimer, m_iMaxTimer;*/




};


};

#endif