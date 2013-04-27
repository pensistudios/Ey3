#ifndef _EY3AAB_H_
#define _EY3AAB_H_

#include "Ey3Vector3.h"

namespace Ey3
{

class Ey3Export AABox
{
public:

	AABox();
	AABox(Vector3& min, Vector3& max) : _min(min), _max(max) {}

private:
	Vector3 _min;
	Vector3 _max;

	
};

};

#endif
