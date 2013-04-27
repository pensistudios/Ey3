#include "Ey3ColorRGBA.h"

using namespace Ey3;

const ColorRGBA ColorRGBA::WHITE(1.0f,1.0f,1.0f,0.0f);
const ColorRGBA ColorRGBA::BLACK(0.0f,0.0f,0.0f,0.0f);

ColorRGBA::ColorRGBA(float rr, float gg, float bb,float aa)
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

	if(aa >1.0f)
		a = 1.0f;
	else if(aa < 0.0f)
		a = 0.0f;
	else
		a = aa;

}

ColorRGBA::ColorRGBA(uchar rr, uchar gg, uchar bb,uchar aa)
{
	r = ((float)rr/255.0f);
	g = ((float)gg/255.0f);
	b = ((float)bb/255.0f);
	a = ((float)aa/255.0f);
}
