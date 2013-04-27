/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Camera.h
/*	Class: Camera
/*	Definition: A camera used to view a scene
/*  Functionality: Represents a camera in the renderer
******************************************************************/

#ifndef _EY3CAMERA_H_
#define _EY3CAMERA_H_

#include "Ey3Frustum.h"
#include "Ey3Renderer.h"

namespace Ey3
{

class Ey3Export Camera : public Frustum
{
public:
	Camera();

	void setFrame (const Vector3& location, const Vector3& dVector,
        const Vector3& uVector, const Vector3& rVector);
    void setFrame (const Vector3& location, const Matrix3& axes);
    void setLocation (const Vector3& location);
    void setAxes (const Vector3& dVector, const Vector3& uVector,
        const Vector3& rVector);
    void setAxes (const Matrix3& axes);
    Vector3 getLocation () const;  // Local Translate
    Vector3 getDVector () const;   // Local Rotate column 0
    Vector3 getUVector () const;   // Local Rotate column 1
    Vector3 getRVector () const;   // Local Rotate column 2

	void getViewPort(float& iL, float& iR, float& iT, float& iB) const
	{
		iL = _lPort; iR = _rPort; iT = _tPort; iB = _bPort;
	}

	void getFrustum(float& rMin, float& rMax, float& uMin,
				float& uMax, float& dMin, float& dMax) const;

	Vector3 getWorldLocation () const;  // World Translate
    Vector3 getWorldDVector () const;   // World Rotate column 0
    Vector3 getWorldUVector () const;   // World Rotate column 1
    Vector3 getWorldRVector () const;   // World Rotate column 2

	void setFrustum (Radian& upFov, float aspectRatio, float dMin,
        float dMax);

	void setViewPort (float left, float right, float top, float bottom);

	bool culled(const BoundingVolume* wbound);
	
	int whichSide (const Plane& plane) const;

	virtual void render(Renderer& ren);
	
	Renderer* _activeRenderer;

protected:
    
    virtual void updateWorldBound ();
    void onFrustumChange ();
    void onViewPortChange ();
    void onFrameChange ();

    // viewport
	float _lPort, _rPort, _tPort, _bPort;


};

};

#endif