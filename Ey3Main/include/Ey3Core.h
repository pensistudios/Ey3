/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Core.h
/*	Class: Core
/*	Definition: Entry Point into the System
/*  Functionality: Initializes all managers, starts everything, etc
******************************************************************/

#ifndef _EY3CORE_H_
#define _EY3CORE_H_

#include "Ey3Def.h"

#include "Ey3Logging.h"
#include "Ey3Singleton.h"

namespace Ey3
{
	
class Ey3Export Core : public Singleton<Core>
{

public:
	Core();
	~Core();

	bool init();

	//Override to prevent link errors
	static Core& GetSingleton(void);
	static Core* GetSingletonPtr(void);

private:

	LogManager* logManager;

};

};

#endif
