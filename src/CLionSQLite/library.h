#ifndef CLIONSQLITE_LIBRARY_H
#define CLIONSQLITE_LIBRARY_H

/*
#ifdef BUILDING_CLIONSQLITE_LIBRARY
#define CLIONSQLITE_LIBRARY __declspec(dllexport)
#else
#define CLIONSQLITE_LIBRARY __declspec(dllimport)
#endif

void __stdcall hello_library();
void __stdcall CLIONSQLITE_LIBRARY hello(const char *s);
int CLIONSQLITE_LIBRARY calc_double(int x);
*/

void hello_library();
void hello(const char *s);
int calc_double(int x);

#endif
