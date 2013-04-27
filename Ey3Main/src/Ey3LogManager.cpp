#include "Ey3LogManager.h"

using namespace Ey3;

template<> LogManager* Singleton<LogManager>::ms_Singleton = 0;

LogManager* LogManager::GetSingletonPtr()
{
	return ms_Singleton;
}
LogManager& LogManager::GetSingleton()
{
	assert(ms_Singleton); 
	return *ms_Singleton;
}

LogManager::LogManager()
{

}
LogManager::~LogManager()
{
    LogMap::iterator i;
    for (i = _logs.begin(); i != _logs.end(); i++)
    {
		delete i->second;
	}
	delete _default;
}

void LogManager::setDefaultLog(Log* name)
{	
	_default = name;
}

void LogManager::addDefaultLog(Str& name)
{
	_default = new Log(name,"Default.Ey3.log");
}

Log* LogManager::getDefault()
{
	return _default;
}

void LogManager::logMessage(Str& message, Log::MType type, bool justDefault)
{
	if(_debug)
	{
		_default->turnOnStdin();
	}

	if(justDefault)
	{
		_default->logMessage(message,type);
	}
	else
	{
		_default->logMessage(message,type);

		LogMap::iterator i;
		for(i = _logs.begin(); i != _logs.end(); i++)
		{
			i->second->logMessage(message,type);
		}
	}

	_default->turnOffStdin();
}

void LogManager::logMessage(Str& message, Log::MType type, Str& name)
{
	LogMap::iterator i;
	for(i = _logs.begin(); i != _logs.end(); i++)
	{
		if(i->first == name)
		{
			i->second->logMessage(message,type);
		}
	}
}

void LogManager::turnOnDebug()
{
	_debug = true;
}

void LogManager::turnOffDebug()
{
	_debug = false;
}



void LogManager::addLog(Log* log)
{
	_logs[log->getName()] = log;
}

void LogManager::addLog(Str& name,Str& filename ,bool b_stdin, bool def)
{
	if(!def)
		_logs[name] = new Log(name, filename, b_stdin);
	else
		_default = new Log(name,filename);
}

Log* LogManager::getLog(Str& name)
{
	LogMap::iterator i;
	for(i = _logs.begin(); i != _logs.end(); i++)
	{
		if(name == i->first)
			return i->second;
	}
	return NULL;
}
