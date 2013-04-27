/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3LogManager.h
/*	Class: LogManager
/*	Definition: Manages set of logs
/*  Functionality: Used to have multiple logs
******************************************************************/

#ifndef _EY3LOGMANAGER_H_
#define _EY3LOGMANAGER_H_

#include "Ey3Log.h"
#include "Ey3Singleton.h"

namespace Ey3
{

class Ey3Export LogManager : public Singleton<LogManager>
{
private:

	typedef std::map<Str, Log*> LogMap;
	LogMap _logs;

	Log* _default;
	bool _debug;

public:
	
	LogManager();
	~LogManager();

	void addDefaultLog(Str& name);
	void setDefaultLog(Log* name);
	Log* getDefault();

	void addLog(Log* log);
	void addLog(Str& name,Str& filename,bool b_stdin, bool def);
	Log* getLog(Str& name);
	
	void turnOnDebug();
	void turnOffDebug();
	
	void logMessage(Str& message, Log::MType type, bool justDefault=true);
	void logMessage(Str& message, Log::MType type, Str& name);
	
	//override to prevent link errors
	static LogManager& GetSingleton(void);
	static LogManager* GetSingletonPtr(void);

};

};

#endif