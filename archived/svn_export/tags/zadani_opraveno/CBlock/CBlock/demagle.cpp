#if defined(__GNUC__) && !defined(_MSC_VER)
// Name demagler for Unix/Linux GCC ABI RTTI interface by: Pety 2021
// !!! Don't modify this file !!!
// $Id: demagle.cpp 1 2022-10-26 16:54:35Z petyovsky $

#include <cxxabi.h>
#include <cstdlib>
#include "demagle.h"

std::string cxxabidemagle(const char *aMagledName)
	{
	// https://www.cs.bham.ac.uk/internal/courses/2005/17423/doc/libstdc++-html-USERS-3.2.1/namespaceabi.html

	int status;
	char *realname;
	std::string str(aMagledName);
	realname = abi::__cxa_demangle(aMagledName, 0, 0, &status);
	if(!status) str = realname;
	std::free(realname);
	return str;
	}
#endif /* defined(__GNUC__) && !defined(_MSC_VER) */
