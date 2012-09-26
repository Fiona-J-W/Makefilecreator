#ifndef output_hpp
#define output_hpp

#include <vector>
#include <string>
#include <sstream>

namespace logging {

using std::string;
using std::stringstream;
using std::vector;


/**
 * convert a list of arguments to a string
 * @param args the arguments
 */
template<typename... T>
string text(T...args);

/**
 * create a string from a formatstring and some arguments
 *
 * unlike printf() this will accept any type with %s
 *
 * @param formatstring the formatstring
 * @param args the other arguments
 */
template<typename...T>
string textf(const string& formatstring,T...args);


/**
 * set the logfile
 * 
 * @param filename logfile; if empty, logging will be disabled
 */
void set_logfile(const string& filename);

#ifdef DEBUG

/**
 * prints a debugmessage; this is an internal function never call it directly.
 * @param filename sourcefile, that calls the function
 * @param line line of the functioncall
 * @param level the debuglevel
 * @param text the debugmessage
 */
void print_debug(string filename, int line, int level, string text);

/**
 * print a debugmessage; this won't do anything in release-builds
 * @param level debuglevel (lower means less important)
 * @param others parameters that will be converted to a string and printed
 */
#define debug(level, ...) logging::print_debug( __FILE__, __LINE__, (level), text(__VA_ARGS__) )

/**
 * print a debugmessage; this won't do anything in release-builds
 * @param level debuglevel (lower means less important)
 * @param others the first parameter is a formatstring that will, together with the rest, create the message
 */
#define debugf(level, ...) logging::print_debug( __FILE__, __LINE__, (level), textf(__VA_ARGS__) )

/**
 * set the debug-level: only debug-messages with a level <= @param d will
 * be printed
 */
void set_debug_level(int d);

#else

#define debug(level, ...)
#define debugf(level, ...)

inline void set_debug_level(int){}
#endif


/**
 * set the verbosity level: only notes with a level <= @param v will be
 * printed
 */
void set_verbose_level(int v);

 
/**
 * print a note with the given urgency-level 
 * @param text the message
 * @param level urgency-level ot the message
 */
void _note(int level, string text);

#define note(level, ...) _note( (level), text(__VA_ARGS__) )
#define notef(level, ...) _note( (level), textf(__VA_ARGS__) )

 
/**
 * print a warning, this won't do anything else
 */
void _warn(string text);

#define warn(...) _warn( text(__VA_ARGS__) )
#define warnf(...) _warn( textf(__VA_ARGS__) )

/**
 * print an error, this won't do anything else
 */
void _error(string text);

#define error(...) _error( text(__VA_ARGS__) )
#define errorf(...) _error( textf(__VA_ARGS__) )


/**
 * print a fatal error, this will terminate the whole program
 */
void _fatal(string text);

#define fatal(...) _error( text(__VA_ARGS__) )
#define fatalf(...) _error( textf(__VA_ARGS__) )

/**
 * get the current time
 */
string get_timestamp();


/**
 * write a message to stdout or stderr and to the log
 * 
 * @param msg the message that will be printed
 * @param normal whether the message is normal behaviour and should be 
 * printed to stdout or an error to be printed to stderr
 */
void print_and_log(const string& msg, bool normal = true);

} //logging namespace

#include "output.tcc"

using namespace logging;

#endif
