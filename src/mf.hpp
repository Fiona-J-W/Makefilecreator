#ifndef mf_hpp
#define mf_hpp

#include <list>
#include <map>
using namespace std;

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

///write the actual makefile with the data shared in settings
int create_makefile(map<path,list<path>> dependencies);

#endif