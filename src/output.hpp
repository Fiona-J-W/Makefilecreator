#ifndef output_hpp
#define output_hpp

#include <string>
using namespace std;

#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
	void debug(string text, int level=1);
#else
	#define debug(x,y) ;
	//#define debug(x) ;
#endif

void set_debug_level(int d);

void set_verbose_level(int v);

void note(string text, int level=1);

void warn(string text);

void error(string text);

void fatal(string text);


#endif