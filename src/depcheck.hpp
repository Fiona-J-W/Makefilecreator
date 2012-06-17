#ifndef depcheck
#define depcheck

#include <list>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;


/// get all dependencies for @param startfile; this will call get_includes
list<path> get_deps(path startfile);

/// get all dependencies for @param file; this will be recursive
list<path> get_includes(path file);


#endif