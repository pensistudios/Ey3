#include "Ey3Log.h"

using namespace Ey3;

Log::Log(const Str& name, const Str& filename, bool s_stdin)
{
	_out.open(filename.c_str());
	_name = name;
	_filename = filename;
	_stdin = s_stdin;
}

Log::~Log()
{
	_out.close();
}

void Log::logMessage(const Str& message, Log::MType type)
{
	if(_stdin)
	{
		std::cout << message << std::endl;
	}
	
	Str s_type = (type == Log::MERROR)?"Error":"Info";
	//Will have to change if have more than 2 types of log
	
	char dateStr[9];
    char timeStr[9];
    _strdate(dateStr);
    _strtime(timeStr);


	//struct tm* sTime;
	//time_t timet; 
	//time(&timet);
	//localtime_s( sTime, &timet );

/*	_out << sTime->tm_hour << ":" 
		 << sTime->tm_min << ":" 
		 << sTime->tm_sec << "|"
		 << s_type << ": " << message << std::endl;
*/
	_out << dateStr << " | " << timeStr << "|"
		<< s_type << ": " << message << std::endl;
 	_out.flush();
	
}

void Log::turnOnStdin()
{
	if(!_stdin)
		_stdin = true;
}

void Log::turnOffStdin()
{
	if(_stdin)
		_stdin = false;
}