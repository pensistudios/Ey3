/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Log.h
/*	Class: Log
/*	Definition: Log class
/*  Functionality: Logs strings to a file
******************************************************************/

#ifndef _EY3LOG_H_
#define _EY3LOG_H_

#include "Ey3Def.h"

namespace Ey3
{

class Ey3Export Log
{
public:

	enum MType
	{
		INFO,
		MERROR  //Logging uses compiler macros which dont like ERROR
	};
	
	explicit Log(const Str& name, const Str& filename, bool s_stdin = false);
	virtual ~Log();
	
	void turnOnStdin();
	void turnOffStdin();

	void logMessage(const Str& message, Log::MType type = Log::INFO);

	Str& getName() { return _name; }

private:

	Str _name;
	Str _filename;
	bool _stdin;
	StdStreamOut _out;

};

};

#endif 