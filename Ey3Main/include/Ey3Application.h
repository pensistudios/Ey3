#ifndef _EY3APPLICATION_H_
#define _EY3APPLICATION_H_

#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export Application
{

public:

	virtual ~Application();

	static virtual Application* create()=0;

	virtual void init() = 0;
	virtual void run() = 0;
	virtual void end() = 0;

public:
	Application();
	


};

};

#endif