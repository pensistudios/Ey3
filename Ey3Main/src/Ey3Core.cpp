#include "Ey3Core.h"

using namespace Ey3;

template<> Core* Singleton<Core>::ms_Singleton = 0;

Core* Core::GetSingletonPtr()
{
	return ms_Singleton;
}
Core& Core::GetSingleton()
{
	assert(ms_Singleton); 
	return *ms_Singleton;
}


Core::Core()
{
}

Core::~Core()
{
	delete logManager;
}

bool Core::init()
{
	if(LogManager::GetSingletonPtr() == 0)
	{
		logManager = new LogManager();
		Str def("def");
		Str err("Error");
		Str file("Error.Ey3.log");
		logManager->addDefaultLog(def);
		logManager->addLog(err,file,true,false);

		char buf[64];
		sprintf(buf,"Ey3 Engine Build: %i.%i.%i (%s)",EY3_MAJOR_VERSION,EY3_MINOR_VERSION,EY3_PATCH_VERSION,EY3_VERSION_NAME);
		LALL(buf);

		#if defined( _DEBUG )
			logManager->turnOnDebug();
		#else
			logManager->turnOffDebug();
		#endif

		
	}
	
	
		
	LOG("Core Initialized");

	return true;

}
