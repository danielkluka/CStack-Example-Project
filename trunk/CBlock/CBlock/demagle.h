#ifndef DEMAGLE_H
#define DEMAGLE_H
// Name demagler for Unix/Linux GCC ABI RTTI interface by: Pety 2020
// !!! Don't modify this file !!!
// $Id: demagle.h 1 2022-10-26 16:54:35Z petyovsky $

#if !defined(__GNUC__) || defined(_MSC_VER)
 #define DM(a) (a)
#else
 #include <string>
 #define DM(a) cxxabidemagle(a)
 std::string cxxabidemagle(const char *aMagledName);
#endif /* __GNUC__ */

#endif /* DEMAGLE_H */
