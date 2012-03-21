#ifndef settings_hpp
#define settings_hpp

#include <list>
#include <string>
#include <map>
using namespace std;

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

#include <getopt.h>

// string(longform), taken_arguments, NULL, char(short_index)

const option OPTIONS[]={
	{"source-dir",required_argument,NULL,'s'},
	{"build-dir",required_argument,NULL,'b'},
	{"target",required_argument,NULL,'t'},
	{"output",required_argument,NULL,'o'},
	{"config-file",required_argument,NULL,'f'},
	{"verbose",required_argument,NULL,'v'},
	{"debug",required_argument,NULL,'d'},
	{"use",required_argument,NULL,'u'},
	//compiler-options:
	{"compiler",required_argument,NULL,'c'},
	{"compile",no_argument,NULL,'C'},
	{"link",required_argument,NULL,'l'},
	{"link-dir",required_argument,NULL,'L'},
	{"include-dir",required_argument,NULL,'I'},
	{"compiler-opts",required_argument,NULL,'O'}
};


struct settings{
	settings(int argc, char **argv);
	void parse_file(string filename);
	void set_opt(char opt,string val);
	
	string target;
	string output;
	
	path source_dir;
	path build_dir;
	map<string,list<pair<char, string>>> conditional_settings;
	//compiler-options:
	string compiler;
	bool compile;
	
	list<string> include_dirs;
	list<string> libdirs;
	list<string> libs;
	list<string> compiler_opts;
	
	
};



#endif