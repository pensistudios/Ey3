#ifndef _EY3WINDOWAPPLICATION_H_
#define _EY3WINDOWAPPLICATION_H_

#include "Ey3Application.h"

namespace Ey3
{

class Ey3Export WindowApplication : public Application
{

public:

	virtual ~WindowApplication();

	static virtual Application* create()=0;

	virtual void init() = 0;
	virtual void run() = 0;
	virtual void end() = 0;

	virtual void setStrings(Str& title, Str& name);
	virtual void setWindow(int h,int w, int b);

	virtual void isFullscreen() { return fullscreen; }


public:

	WindowApplication();

protected:

	int windowWidth;
	int windowHeight;
	int windowBits;
	bool fullscreen;

	Str _title;
	Str _className;

};

};

#endif