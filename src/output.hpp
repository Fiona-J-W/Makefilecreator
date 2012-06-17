#ifndef output_hpp
#define output_hpp

#include <string>
using namespace std;

//#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
	/// print a debug-message with priority @param level; will be defined
	/// to nothing in release-builds
	void debug(string text, int level=1);
#else
	// undefine this for release, as described above:
	#define debug(x,y) ;
#endif

/// set the debug-level: only debug-messages with a level <= @param d will
/// be printed
void set_debug_level(int d);

/// set the verbosity level: only notes with a level <= @param v will be
/// printed
void set_verbose_level(int v);

/// print a note with urgency-level @param level
void note(string text, int level=1);

/// print a warning, this won't do anything else:
void warn(string text);

/// print an error, this won't do anything else:
void error(string text);

/// print a fatal error, this will terminate the whole program:
void fatal(string text);


#endif