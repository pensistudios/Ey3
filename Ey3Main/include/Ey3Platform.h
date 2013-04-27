/****************************************************************/
/*  File: Ey3Platform.h
/*  Functionality: A set of macros that defines what platform the
/*	code will be compiled for
******************************************************************/

#ifndef _EY3PLATFORM_H_
#define _EY3PLATFORM_H_

#define EY3_WINDOWS 1

#define EY3_PLATFORM EY3_WINDOWS 

//Only one platform for now :)

#define EY3_OPTIMIZE // dont define this for std lib math functions


#if EY3_PLATFORM == EY3_WINDOWS
   	#if defined( EY3_LIB_BUILD )
       	#define Ey3Export __declspec( dllexport )
   	#else
       	#define Ey3Export __declspec( dllimport )
   	#endif

    #ifdef _DEBUG
        #define EY3_DEBUG 1
    #else
        #define EY3_DEBUG 0
    #endif

	#if EY3_DEBUG
		#define EY3_LIB "Ey3Engine_d.dll"
	#else
		#define EY3_LIB "Ey3Engine.dll"
	#endif
	
//	#define WIN32_LEAN_AND_MEAN		
//	#include <windows.h>

#endif



#endif //_EY3PLATFORM_H_