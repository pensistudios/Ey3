#ifndef _EY3FRUSTUM_H_
#define _EY3FRUSTUM_H_

#include "Ey3Plane.h"
#include "Ey3Vector2.h"
#include "Ey3RenderObject.h"
#include "Ey3Math.h"

namespace Ey3
{

class Renderer;

class Ey3Export Frustum : public RenderObject
{
public:

	enum ProjectionType
	{
		ORTHOGRAPHIC,
		PERSPECTIVE
	};

	Frustum();
	Frustum(Radian& fovy, float aratio, float near, float far);

	const Radian& getFOV() const;
	void setFOV(Radian& r);
	float getNear() const;
	void setNear(float n);
	float getFar() const;
	void setFar(float f);
	float getAspectRatio() const;
	void setAspectRatio(float a);

	void updateWorldBound()=0;
	void render(Renderer& r)=0;

protected:
	
	ProjectionType _type;

	Plane _near;
	Plane _far;
	Plane _left;
	Plane _right;
	Plane _down;
	Plane _up;

	Radian _FOVy;
	float _farDistance;
	float _nearDistance;
	float _aspectRatio;
	
	
	
	




};

};

#endif