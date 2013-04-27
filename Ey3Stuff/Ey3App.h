#ifndef _EY3APP_H_
#define _EY3APP_H_

//#include "Ey3.h"
#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export App
{
public:
	virtual ~App();
	
	typedef int (*EntryFunction)(int, char**);
    static EntryFunction Main;

	static App* theApp;
	
protected:
	
	App();

};

};

#endif