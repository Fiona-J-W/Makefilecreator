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
	{"ignore",required_argument,NULL,'w'},
	//compiler-options:
	{"compiler",required_argument,NULL,'c'},
	{"compile",no_argument,NULL,'C'},
	{"link",required_argument,NULL,'l'},
	{"link-dir",required_argument,NULL,'L'},
	{"include-dir",required_argument,NULL,'I'},
	{"compiler-opts",required_argument,NULL,'O'},
	{0,0,0,0}
};


struct settings{
	//There is really  no reason to create an instance:
	settings() = delete;
	
	static void init(int argc, char **argv);
	
	static void parse_file(string filename);
	static void set_opt(char opt,string val);
	
	static list<path> header_files;
	static list<path> implementation_files;
	
	static string target;
	static string output;
	
	static path source_dir;
	static path build_dir;
	static list<path> ignore_files;
	static map<string,list<pair<char, string>>> conditional_settings;
	//compiler-options:
	static string compiler;
	static bool compile;
	
	static list<string> include_dirs;
	static list<string> libdirs;
	static list<string> libs;
	static list<string> compiler_opts;
};



#endif
