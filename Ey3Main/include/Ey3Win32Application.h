#ifndef _EY3WIN32APPLICATION_H_
#define _EY3WIN32APPLICATION_H_

#include "Ey3WindowApplication.h"

namespace Ey3
{

class Ey3Export Win32Application : public WindowApplication
{
public:
	virtual ~Win32Application();

	static virtual Application* create();

	virtual void init() = 0;
	virtual void run() = 0;
	virtual void end() = 0;

public:

	Win32Application();



};

};

#endif