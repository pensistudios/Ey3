#include "Ey3ColorRGB.h"

using namespace Ey3;

ColorRGB::ColorRGB(float rr, float gg, float bb)
{
	if(rr > 1.0f)
		r = 1.0f;
	else if(rr < 0.0f)
		r = 0.0f;
	else 
		r = rr;

	if(gg > 1.0f)
		g = 1.0f;
	else if(gg < 0.0f)
		g = 0.0f;
	else
		g = gg;

	if(bb > 1.0f)
		b = 1.0f;
	else if(bb < 0.0f)
		b = 0.0f;
	else
		b = bb;

}

ColorRGB::ColorRGB(uchar rr, uchar gg, uchar bb)
{
	r = ((float)rr/255.0f);
	g = ((float)gg/255.0f);
	b = ((float)bb/255.0f);
}
