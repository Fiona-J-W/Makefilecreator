#ifndef output_hpp
#define output_hpp

#include <string>
using namespace std;

#define ENABLE_DEBUG 0

/**
 * print a debug-message with priority level; this function is not to be called
 * from anywhere else than the debug function (we want this to be optimized out
 * in release-builds)
 * @param text  debugmessage
 * @param level debuglevel (lower means less important)
 */
void print_debug(string text, int level);

/**
 * print a debugmessage; this won't do anything in release-builds
 * @param text  debugmessage
 * @param level debuglevel (lower means less important)
 */
///TODO: make this world-visible
void debug(string text, int level=1);



/**
 * set the debug-level: only debug-messages with a level <= @param d will
 * be printed
 */
void set_debug_level(int d);


/**
 * set the verbosity level: only notes with a level <= @param v will be
 * printed
 */
void set_verbose_level(int v);

 
/**
 * print a note with urgency-level @param level
 */
void note(string text, int level=1);

 
/**
 * print a warning, this won't do anything else
 */
void warn(string text);

 
/**
 * print an error, this won't do anything else
 */
void error(string text);



/**
 * print a fatal error, this will terminate the whole program
 */
void fatal(string text);


#endif