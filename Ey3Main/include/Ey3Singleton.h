/****************************************************************/
/*	Ey3 Build: Enigma
/*  File: Ey3Singleton.h
/*	Class: Singleton
/*	Definition: Abstract class used for singletons
/*  Functionality: Classes that only need one instance
******************************************************************/

/* Original version Copyright (C) Scott Bilas, 2000.
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright (C) Scott Bilas, 2000"
 */
#ifndef _SINGLETON_H__
#define _SINGLETON_H__

#include "Ey3Def.h"

namespace Ey3
{

template <typename T> class Singleton
    {
    protected:

        static T* ms_Singleton;

    public:
        Singleton( void )
        {
            assert( !ms_Singleton );
#if defined( _MSC_VER ) && _MSC_VER < 1200	 
            int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
            ms_Singleton = (T*)((int)this + offset);
#else
	    ms_Singleton = static_cast< T* >( this );
#endif
        }
        ~Singleton( void )
            {  assert( ms_Singleton );  ms_Singleton = 0;  }
        static T& GetSingleton( void )
		{	assert( ms_Singleton );  return ( *ms_Singleton ); }
        static T* GetSingletonPtr( void )
		{ return ms_Singleton; }
    };

};

#endif