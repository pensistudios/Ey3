/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Logging.h
/*  Functionality: Useful Macros for logging
******************************************************************/

#ifndef _EY3LOGGING_H_
#define _EY3LOGGING_H_

#include "Ey3Log.h"
#include "Ey3LogManager.h"

namespace Ey3
{

#define LOG(M)  \
{	\
	Str m(M);	\
	Ey3::LogManager::GetSingleton().logMessage(m + "\n", \
												Ey3::Log::INFO, \
									   true); \
}

#define LALL(M)	\
{	\
	Str m(M);	\
	Ey3::LogManager::GetSingleton().logMessage(m + "\n",	\
												Ey3::Log::INFO,	\
												false);	\
}

#define LERR(M)  \
{	\
	Str m(M);	\
	Str e("Error"); \
	if(LogManager::GetSingleton().getLog(e) != 0) \
	LogManager::GetSingleton().getLog(e)->logMessage(m + "\n", \
													Log::MERROR); \
	else LogManager::GetSingleton().logMessage(m + "\n",	 \
											 Log::MERROR,	\
												false);	\
}

};

#endif