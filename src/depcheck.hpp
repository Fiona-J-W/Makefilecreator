#ifndef depcheck
#define depcheck

#include <list>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

#include "settings.hpp"

list<path> get_includes(path filee, settings &S);

list<path> get_deps(path startfile, settings &S);

#endif