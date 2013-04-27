#include "Ey3Orientation.h"

using namespace Ey3;

Orientation::Orientation(Orientation::Type t)
{
	_type = t;
}

Orientation::~Orientation()
{
}

Orientation* Orientation::convert(Orientation::Type t)
{
	return &Orientation(Orientation::EULER);
}