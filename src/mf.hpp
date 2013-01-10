#ifndef mf_hpp
#define mf_hpp

#include <vector>
#include <map>
using namespace std;

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

/**
 * write the actual makefile with the data shared in settings
 */
int create_makefile(map<path,vector<path>> dependencies);

/**
 * writes the general settings to output
 */
void write_settings(ofstream &output,path relative_dir, 
                   map<path,vector<path>> dependencies);

/**
 * writes the build-rules to the output
 */
void write_rules(ofstream &output,path relative_dir);

/**
 * writes the found dependencies for all objectfiles to the output
 */
void write_dependencies(ofstream &output,path relative_dir, 
                       map<path,vector<path>> dependencies);

#endif
