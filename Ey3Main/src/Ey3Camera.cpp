#include "Ey3Camera.h"

using namespace Ey3;

Camera::Camera()
: Frustum()
{
	_activeRenderer = 0;

	onFrustumChange();
    setViewPort(0.0f,1.0f,1.0f,0.0f);
    setFrame(Vector3::ZERO,Vector3::UNIT_Z,Vector3::UNIT_Y,
        Vector3::UNIT_X);
}

void Camera::setFrame(const Vector3& location, const Vector3& dVector,
    const Vector3& uVector, const Vector3& rVector)
{
    local.setTranslate(location);
    local.setRotate(Matrix3(dVector,uVector,rVector));
    onFrameChange();
}

void Camera::setFrame(const Vector3& location, const Matrix3& axes)
{
    local.setTranslate(location);
    local.setRotate(axes);
    onFrameChange();
}

void Camera::setLocation(const Vector3& location)
{
    local.setTranslate(location);
    onFrameChange();
}

void Camera::setAxes(const Vector3& dVector, const Vector3& uVector,
    const Vector3& rVector)
{
    local.setRotate(Matrix3(dVector,uVector,rVector));
    onFrameChange();
}

void Camera::setAxes(const Matrix3& axes)
{
    local.setRotate(axes);
    onFrameChange();
}

void Camera::updateWorldBound ()
{
    // The camera has an implicit model bound whose center is the camera's
    // position and whose radius is zero.
	
    worldCullVolume.setCenter(world.applyForward(local.getTranslate()));
    worldCullVolume.setRadius(0.0f);
}


void Camera::setFrustum (Radian& upFov, float aspectRatio, float dMin,
    float dMax)
{
    /*float halfAngleRadians = 0.5f*upFovDegrees*Math::DEG_TO_RAD;
    _uMax = dMin*tanf(halfAngleRadians);
    _rMax = aspectRatio*_uMax;
    _uMin = -_uMax;
    _rMin = -_rMax;
    _dMin = dMin;
    _dMax = dMax;*/

	_FOVy = upFov;
	_aspectRatio = aspectRatio;
	_nearDistance = dMin;
	_farDistance = dMax;

    onFrustumChange();
}

void Camera::getFrustum(float& left, float& right, float& bottom, float& top, float& near, float& far) const
{
	near = _nearDistance;
	far = _farDistance;
	top = _nearDistance*tanf(_FOVy._value/2.0f);
	right = _aspectRatio*top;
	bottom = -top;
	left = -right;
}

void Camera::setViewPort (float fLeft, float fRight, float fTop,
    float fBottom)
{
    _lPort = fLeft;
    _rPort = fRight;
    _tPort = fTop;
    _bPort = fBottom;
    onViewPortChange();
}

void Camera::onFrustumChange ()
{
    if (_activeRenderer)
        _activeRenderer->onFrustumChange(); //TODO
}
//----------------------------------------------------------------------------
void Camera::onViewPortChange ()
{
    if ( _activeRenderer )
        _activeRenderer->onViewPortChange();
}
//----------------------------------------------------------------------------
void Camera::onFrameChange ()
{
	updateWorldTransform();
  
    if ( _activeRenderer )
        _activeRenderer->onFrameChange();
}


bool Camera::culled (const BoundingVolume* wBound)
{

    return false;
}

int Camera::whichSide (const Plane& plane) const
{
    // frustum is fully on the negative side
    return -1;
}


inline Vector3 Camera::getLocation () const
{	
    return local.getTranslate();
}

inline Vector3 Camera::getDVector () const
{
    Matrix3 m = local.getRotate();
    return m.getColumn(0);
}

inline Vector3 Camera::getUVector () const
{
	Matrix3 m = local.getRotate();
    return m.getColumn(1);
}

inline Vector3 Camera::getRVector () const
{
	Matrix3 m = local.getRotate();
    return m.getColumn(2);
}

inline Vector3 Camera::getWorldLocation () const
{
	 return world.getTranslate();
}

inline Vector3 Camera::getWorldDVector () const
{
	Matrix3 m = world.getRotate();
    return m.getColumn(0);
}

inline Vector3 Camera::getWorldUVector () const
{
	Matrix3 m = world.getRotate();
    return m.getColumn(1);
}

inline Vector3 Camera::getWorldRVector() const
{
	Matrix3 m = world.getRotate();
    return m.getColumn(2);
}


void Camera::render(Renderer& ren)
{

}