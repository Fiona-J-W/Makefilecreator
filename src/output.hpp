#ifndef output_hpp
#define output_hpp

#include <string>
using namespace std;

void set_verbose_level(int v);

void set_debug_level(int d);

void note(string text, int level=1);

void debug(string text, int level=1);

void warn(string text);

void error(string text);

void fatal(string text);


#endif