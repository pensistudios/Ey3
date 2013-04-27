#include "Ey3WindowedApp3d.h"

using namespace Ey3;

WindowedApp3d::WindowedApp3d (const char* acWindowTitle,
    int iXPosition, int iYPosition, int iWidth, int iHeight,
    const ColorRGB& rkBackgroundColor)
    :
    WindowedApp(acWindowTitle,iXPosition,iYPosition,iWidth,iHeight,
        rkBackgroundColor)
{
    // camera motion
    worldAxis[0] = Vector3::ZERO;
    worldAxis[1] = Vector3::ZERO;
    worldAxis[2] = Vector3::ZERO;
    m_fTrnSpeed = 0.0f;
    m_fRotSpeed = 0.0f;
    m_bUArrowPressed = false;
    m_bDArrowPressed = false;
    m_bLArrowPressed = false;
    m_bRArrowPressed = false;
    m_bPgUpPressed = false;
    m_bPgDnPressed = false;
    m_bHomePressed = false;
    m_bEndPressed = false;
    m_bCameraMoveable = false;

    // object motion
    m_iDoRoll = 0;
    m_iDoYaw = 0;
    m_iDoPitch = 0;
    motionObject = 0;
    m_fXTrack0 = 0.0f;
    m_fYTrack0 = 0.0f;
    m_fXTrack1 = 0.0f;
    m_fYTrack1 = 0.0f;
    m_bUseTrackBall = true;
    m_bTrackBallDown = false;
    m_bObjectMoveable = false;

    // performance measurements
/*    m_dLastTime = -1.0;
    m_dAccumulatedTime = 0.0;
    m_dFrameRate = 0.0;
    m_iFrameCount = 0;
    m_iTimer = 30;
    m_iMaxTimer = 30;*/
}

WindowedApp3d::~WindowedApp3d ()
{
}

bool WindowedApp3d::onInitialize ()
{
    if ( !WindowedApp::onInitialize() )
        return false;

    _camera = new Camera;
    _renderer->setCamera(_camera);
    motionObject = 0;
    return true;
}

void WindowedApp3d::onTerminate ()
{
    _renderer->setCamera(0);
    _camera = 0;
    motionObject = 0;
    WindowedApp::onTerminate();
}

void WindowedApp3d::onDisplay ()
{
    if ( _renderer )
        onIdle();
}

bool WindowedApp3d::onKeyDown (unsigned char ucKey, int iX, int iY)
{
    if ( WindowedApp::onKeyDown(ucKey,iX,iY) )
        return true;

    // standard keys
    switch ( ucKey )
    {
    case 't':  // slower camera translation
        if ( m_bCameraMoveable )
            m_fTrnSpeed /= m_fTrnSpeedFactor;
        return true;
    case 'T':  // faster camera translation
        if ( m_bCameraMoveable )
            m_fTrnSpeed *= m_fTrnSpeedFactor;
        return true;
    case 'r':  // slower camera rotation
        if ( m_bCameraMoveable )
            m_fRotSpeed /= m_fRotSpeedFactor;
        return true;
    case 'R':  // faster camera rotation
        if ( m_bCameraMoveable )
            m_fRotSpeed *= m_fRotSpeedFactor;
        return true;
    case '?':  // reset the timer
        //resetTime();
        return true;
    };

    return false;
}

bool WindowedApp3d::onSpecialKeyDown (int iKey, int, int)
{
    if ( m_bCameraMoveable )
    {
        if ( iKey == KEY_LEFT_ARROW )
        {
            m_bLArrowPressed = true;
            return true;
        }
        if ( iKey == KEY_RIGHT_ARROW )
        {
            m_bRArrowPressed = true;
            return true;
        }
        if ( iKey == KEY_UP_ARROW )
        {
            m_bUArrowPressed = true;
            return true;
        }
        if ( iKey == KEY_DOWN_ARROW )
        {
            m_bDArrowPressed = true;
            return true;
        }
        if ( iKey == KEY_PAGE_UP )
        {
            m_bPgUpPressed = true;
            return true;
        }
        if ( iKey == KEY_PAGE_DOWN )
        {
            m_bPgDnPressed = true;
            return true;
        }
        if ( iKey == KEY_HOME )
        {
            m_bHomePressed = true;
            return true;
        }
        if ( iKey == KEY_END )
        {
            m_bEndPressed = true;
            return true;
        }
    }

    if ( m_bObjectMoveable )
    {
        if ( iKey == KEY_F1 )
        {
            m_iDoRoll = -1;
            return true;
        }
        if ( iKey == KEY_F2 )
        {
            m_iDoRoll = 1;
            return true;
        }
        if ( iKey == KEY_F3 )
        {
            m_iDoYaw = -1;
            return true;
        }
        if ( iKey == KEY_F4 )
        {
            m_iDoYaw = 1;
            return true;
        }
        if ( iKey == KEY_F5 )
        {
            m_iDoPitch = -1;
            return true;
        }
        if ( iKey == KEY_F6 )
        {
            m_iDoPitch = 1;
            return true;
        }
    }

    return false;
}

bool WindowedApp3d::onSpecialKeyUp (int iKey, int, int)
{
    if ( m_bCameraMoveable )
    {
        if ( iKey == KEY_LEFT_ARROW )
        {
            m_bLArrowPressed = false;
            return true;
        }
        if ( iKey == KEY_RIGHT_ARROW )
        {
            m_bRArrowPressed = false;
            return true;
        }
        if ( iKey == KEY_UP_ARROW )
        {
            m_bUArrowPressed = false;
            return true;
        }
        if ( iKey == KEY_DOWN_ARROW )
        {
            m_bDArrowPressed = false;
            return true;
        }
        if ( iKey == KEY_PAGE_UP )
        {
            m_bPgUpPressed = false;
            return true;
        }
        if ( iKey == KEY_PAGE_DOWN )
        {
            m_bPgDnPressed = false;
            return true;
        }
        if ( iKey == KEY_HOME )
        {
            m_bHomePressed = false;
            return true;
        }
        if ( iKey == KEY_END )
        {
            m_bEndPressed = false;
            return true;
        }
    }

    if ( m_bObjectMoveable )
    {
        if ( iKey == KEY_F1 )
        {
            m_iDoRoll = 0;
            return true;
        }
        if ( iKey == KEY_F2 )
        {
            m_iDoRoll = 0;
            return true;
        }
        if ( iKey == KEY_F3 )
        {
            m_iDoYaw = 0;
            return true;
        }
        if ( iKey == KEY_F4 )
        {
            m_iDoYaw = 0;
            return true;
        }
        if ( iKey == KEY_F5 )
        {
            m_iDoPitch = 0;
            return true;
        }
        if ( iKey == KEY_F6 )
        {
            m_iDoPitch = 0;
            return true;
        }
    }

    return false;
}

bool WindowedApp3d::onMouseClick (int iButton, int iState, int iX,
    int iY, unsigned int)
{
    if ( !m_bUseTrackBall
    ||   iButton != MOUSE_LEFT_BUTTON
    ||   !motionObject )
    {
        return false;
    }

    float fMult = 1.0f/(width >= height ? height : width);

    if ( iState == MOUSE_DOWN )
    {
        // get the starting point
        m_bTrackBallDown = true;
		Matrix3 m;
		motionObject->localTrans.getMatrix(m);
        m_kSaveRotate = m;
        m_fXTrack0 = (2*iX-width)*fMult;
        m_fYTrack0 = (2*(height-1-iY)-height)*fMult;
    }
    else
    {
        m_bTrackBallDown = false;
    }

    return true;
}

bool WindowedApp3d::onMotion (int iButton, int iX, int iY)
{
    if ( !m_bUseTrackBall
    ||   iButton != MOUSE_LEFT_BUTTON
    ||   !m_bTrackBallDown
    ||   !motionObject )
    {
        return false;
    }

    // get the ending point
    float fMult = 1.0f/(width >= height ? height : width);
    m_fXTrack1 = (2*iX-width)*fMult;
    m_fYTrack1 = (2*(height-1-iY)-height)*fMult;

    // update the object's localTrans rotation
//    rotateTrackBall(m_fXTrack0,m_fYTrack0,m_fXTrack1,m_fYTrack1);
    return true;
}



// camera motion

void WindowedApp3d::initializeCameraMotion (float fTrnSpeed,
    float fRotSpeed, float fTrnSpeedFactor, float fRotSpeedFactor)
{
    m_bCameraMoveable = true;

    m_fTrnSpeed = fTrnSpeed;
    m_fRotSpeed = fRotSpeed;
    m_fTrnSpeedFactor = fTrnSpeedFactor;
    m_fRotSpeedFactor = fRotSpeedFactor;

    worldAxis[0] = _camera->getDVector();
    worldAxis[1] = _camera->getUVector();
    worldAxis[2] = _camera->getRVector();
}

bool WindowedApp3d::moveCamera ()
{
    if ( !m_bCameraMoveable )
        return false;

    bool bmoved = false;

    if ( m_bUArrowPressed )
    {
        moveForward();
        bmoved = true;
    }

    if ( m_bDArrowPressed )
    {
        moveBackward();
        bmoved = true;
    }

    if ( m_bHomePressed )
    {
        moveUp();
        bmoved = true;
    }

    if ( m_bEndPressed )
    {
        moveDown();
        bmoved = true;
    }

    if ( m_bLArrowPressed )
    {
        turnLeft();
        bmoved = true;
    }

    if ( m_bRArrowPressed )
    {
        turnRight();
        bmoved = true;
    }

    if ( m_bPgUpPressed )
    {
        lookUp();
        bmoved = true;
    }

    if ( m_bPgDnPressed )
    {
        lookDown();
        bmoved = true;
    }

    return bmoved;
}

void WindowedApp3d::moveForward ()
{
    Vector3 kLoc = _camera->getLocation();
    kLoc += worldAxis[0]*m_fTrnSpeed;
    _camera->setLocation(kLoc);
}

void WindowedApp3d::moveBackward ()
{
    Vector3 kLoc = _camera->getLocation();
    kLoc -= worldAxis[0]*m_fTrnSpeed;
    _camera->setLocation(kLoc);
}

void WindowedApp3d::moveUp ()
{
    Vector3 kLoc = _camera->getLocation();
    kLoc += worldAxis[1]*m_fTrnSpeed;
    _camera->setLocation(kLoc);
}

void WindowedApp3d::moveDown ()
{
    Vector3 kLoc = _camera->getLocation();
    kLoc -= worldAxis[1]*m_fTrnSpeed;
    _camera->setLocation(kLoc);
}

void WindowedApp3d::turnLeft ()
{
    Matrix3 kIncr(worldAxis[1],m_fRotSpeed);
    worldAxis[0] = kIncr*worldAxis[0];
    worldAxis[2] = kIncr*worldAxis[2];

    Vector3 kDVector = kIncr*_camera->getDVector();
    Vector3 kUVector = kIncr*_camera->getUVector();
    Vector3 kRVector = kIncr*_camera->getRVector();
    _camera->setAxes(kDVector,kUVector,kRVector);
}

void WindowedApp3d::turnRight ()
{
    Matrix3 kIncr(worldAxis[1],-m_fRotSpeed);
    worldAxis[0] = kIncr*worldAxis[0];
    worldAxis[2] = kIncr*worldAxis[2];

    Vector3 kDVector = kIncr*_camera->getDVector();
    Vector3 kUVector = kIncr*_camera->getUVector();
    Vector3 kRVector = kIncr*_camera->getRVector();
    _camera->setAxes(kDVector,kUVector,kRVector);
}

void WindowedApp3d::lookUp ()
{
    Matrix3 kIncr(worldAxis[2],-m_fRotSpeed);

    Vector3 kDVector = kIncr*_camera->getDVector();
    Vector3 kUVector = kIncr*_camera->getUVector();
    Vector3 kRVector = kIncr*_camera->getRVector();
    _camera->setAxes(kDVector,kUVector,kRVector);
}

void WindowedApp3d::lookDown ()
{
    Matrix3 kIncr(worldAxis[2],m_fRotSpeed);

    Vector3 kDVector = kIncr*_camera->getDVector();
    Vector3 kUVector = kIncr*_camera->getUVector();
    Vector3 kRVector = kIncr*_camera->getRVector();
    _camera->setAxes(kDVector,kUVector,kRVector);
}



// object motion

void WindowedApp3d::initializeObjectMotion (RenderObject* pkMotionObject)
{
    m_bObjectMoveable = true;
    motionObject = pkMotionObject;
}

bool WindowedApp3d::moveObject ()
{
    // The coordinate system in which the rotations are applied is that of
    // the object's parent, if it has one.  The parent's world rotation
    // matrix is R, of which the columns are the coordinate axis directions.
    // Column 0 is "direction", column 1 is "up", and column 2 is "right".
    // If the object does not have a parent, the world coordinate axes are
    // used, in which case the rotation matrix is I, the identity.  Column 0
    // is (1,0,0) and is "direction", column 1 is (0,1,0) and is "up", and
    // column 2 is (0,0,1) and is "right".  This choice is consistent with
    // the use of rotations in the Camera and Light classes to store
    // coordinate axes.
    //
    // Roll is about the "direction" axis, yaw is about the "up" axis, and
    // pitch is about the "right" axis.

    if ( !m_bCameraMoveable || !motionObject )
        return false;

    RenderObject* pkParent = motionObject->getParent();
    Vector3 kAxis;
    float fAngle;
    Matrix3 kRot, kIncr;

	Matrix3 m;
    if ( m_iDoRoll )
    {
		
		motionObject->localTrans.getMatrix(m);
        kRot = m;

        fAngle = m_iDoRoll*m_fRotSpeed;
        if ( pkParent )
		{
			pkParent->worldTrans.getMatrix(m);	
            kAxis = m.getColumn(0);
		}
        else
            kAxis = Vector3::UNIT_X;

        kIncr.fromAxisAngle(kAxis,fAngle);
        motionObject->localTrans.setMatrix(kIncr*kRot);
        return true;
    }
	
    if ( m_iDoYaw )
    {
		motionObject->localTrans.getMatrix(m);
        kRot = m;

        fAngle = m_iDoYaw*m_fRotSpeed;
        if ( pkParent )
		{
			pkParent->worldTrans.getMatrix(m);	
            kAxis = m.getColumn(1);
		}
        else
            kAxis = Vector3::UNIT_Y;

        kIncr.fromAxisAngle(kAxis,fAngle);
        motionObject->localTrans.setMatrix(kIncr*kRot);
        return true;
    }

    if ( m_iDoPitch )
    {
		motionObject->localTrans.getMatrix(m);
        kRot = m;

        fAngle = m_iDoPitch*m_fRotSpeed;
        if ( pkParent )
		{
            pkParent->worldTrans.getMatrix(m);	
            kAxis = m.getColumn(2);
		}
        else
            kAxis = Vector3::UNIT_Z;

        kIncr.fromAxisAngle(kAxis,fAngle);
        motionObject->localTrans.setMatrix(kIncr*kRot);
        return true;
    }

    return false;
}

/*void WindowedApp3d::rotateTrackBall (float fX0, float fY0, float fX1,
    float fY1)
{
    if ( (fX0 == fX1 && fY0 == fY1) || !_camera )  // nothing to rotate
        return;

    // get first vector on sphere
    float fLength = sqrtf(fX0*fX0+fY0*fY0), fInvLength, fZ0, fZ1;
    if ( fLength > 1.0f )
    {
        // outside unit disk, project onto it
        fInvLength = 1.0f/fLength;
        fX0 *= fInvLength;
        fY0 *= fInvLength;
        fZ0 = 0.0f;
    }
    else
    {
        // compute point (x0,y0,z0) on negative unit hemisphere
        fZ0 = 1.0f - fX0*fX0 - fY0*fY0;
        fZ0 = ( fZ0 <= 0.0f ? 0.0f : sqrtf(fZ0) );
    }
    fZ0 *= -1.0f;

    // use camera world coordinates, order is (D,U,R), so point is (z,y,x)
    Vector3 kVec0(fZ0,fY0,fX0);

    // get second vector on sphere
    fLength = sqrtf(fX1*fX1+fY1*fY1);
    if ( fLength > 1.0f )
    {
        // outside unit disk, project onto it
        fInvLength = 1.0f/fLength;
        fX1 *= fInvLength;
        fY1 *= fInvLength;
        fZ1 = 0.0f;
    }
    else
    {
        // compute point (x1,y1,z1) on negative unit hemisphere
        fZ1 = 1.0f - fX1*fX1 - fY1*fY1;
        fZ1 = ( fZ1 <= 0.0f ? 0.0f : sqrtf(fZ1) );
    }
    fZ1 *= -1.0f;

    // use camera world coordinates, order is (D,U,R), so point is (z,y,x)
    Vector3 kVec1(fZ1,fY1,fX1);

    // create axis and angle for the rotation
	Vector3 kAxis = Ey3::crossProduct(kVec0,kVec1);
    float fDot = kVec0*(kVec1);
    float fAngle;
	Vector3 kAxisNorm(kAxis);
	kAxisNorm.normalize();
	if ( kAxisNorm > Vector3::ZERO ) //USED TO COMPARE TO SOMETHING ELSE TODO
    {
        fAngle = acosf(kVec0*(kVec1)); 
    }
    else  // vectors are parallel
    {
        if ( fDot < 0.0f )
        {
            // rotated pi radians
            fInvLength = Math::InvSqrt(fX0*fX0+fY0*fY0);
            kAxis.x = fY0*fInvLength;
            kAxis.y = -fX0*fInvLength;
            kAxis.z = 0.0f;
            fAngle = Math::PI;
        }
        else
        {
            // rotation by zero radians
            kAxis = Vector3::UNIT_X;
            fAngle = 0.0f;
        }
    }

    // Compute the world rotation matrix implied by trackball motion.  The
    // axis vector was computed in camera coordinates.  It must be converted
    // to world coordinates.  once again, I use the camera ordering (D,U,R).
    Vector3 kWorldAxis =
        _camera->getWorldDVector()*kAxis.x +
        _camera->getWorldUVector()*kAxis.y +
        _camera->getWorldRVector()*kAxis.z;

    Matrix3 kTrackRotate(kWorldAxis,fAngle);

    // Compute the new localTrans rotation.  If the object is the root of the
    // scene, the new rotation is simply the *incremental rotation* of the
    // trackball applied *after* the object has been rotated by its old
    // localTrans rotation.  If the object is not the root of the scene, you have
    // to convert the incremental rotation by a change of basis in the
    // parent's coordinate space. 
    const RenderObject* pkParent = motionObject->getParent();
    if ( pkParent )
    {
        const Matrix3& rkPRotate = pkParent->World.getRotate();
        motionObject->localTrans.setRotate(
            rkPRotate.Transposetimes(kTrackRotate)*rkPRotate*m_kSaveRotate);
    }
    else
    {
        motionObject->localTrans.setRotate(kTrackRotate*m_kSaveRotate);
    }

    motionObject->UpdateGS();
}
*/


// performance measurements

/*void WindowedApp3d::resetTime ()
{
    m_dLastTime = -1.0f;
}

void WindowedApp3d::measureTime ()
{
    // start performance measurements
    if ( m_dLastTime == -1.0 )
    {
        m_dLastTime = System::getTime();
        m_dAccumulatedTime = 0.0;
        m_dFrameRate = 0.0;
        m_iFrameCount = 0;
        m_iTimer = m_iMaxTimer;
    }

    // accumulate the time only when the miniature time allows it
    if ( --m_iTimer == 0 )
    {
        double dCurrentTime = System::getTime();
        double dDelta = dCurrentTime - m_dLastTime;
        m_dLastTime = dCurrentTime;
        m_dAccumulatedTime += dDelta;
        m_iTimer = m_iMaxTimer;
    }
}

void WindowedApp3d::updateFrameCount ()
{
    m_iFrameCount++;
}

void WindowedApp3d::DrawFrameRate (int iX, int iY,
    const ColorRGBA& rkColor)
{
    if ( m_dAccumulatedTime > 0.0 )
        m_dFrameRate = m_iFrameCount/m_dAccumulatedTime;
    else
        m_dFrameRate = 0.0;

    char acMessage[256];
    sprintf(acMessage,"fps: %.1lf",m_dFrameRate);
    _renderer->Draw(iX,iY,rkColor,acMessage);
}

*/