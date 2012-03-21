#ifndef depcheck
#define depcheck

#include <list>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;


list<path> get_includes(path file);

list<path> get_deps(path startfile, const list<path> &headers);

#endif