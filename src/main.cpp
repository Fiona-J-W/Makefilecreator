#include <iostream>
#include <list>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

#include "treewalker.hpp"
#include "depcheck.hpp"
#include "settings.hpp"
#include "mf.hpp"
#include "tools.hpp"
#include "output.hpp"
#include "help.hpp"


int main(int argc, char **argv){
	if(argc == 2 && ( argv[1] == string("-h") || argv[1] == string("--help") ) ){
		print_help(argv[0]);
		return 0;
	}
	settings::init(argc, argv);
	debug("settings read",1);
	get_code_files();
	debug("got list of code-files",1);
	
	map<path,list<path>> dependencies;
	debug("starting to read dependencies",1);
	for(auto x : settings::implementation_files){
		debug("reading dependencies for "+x.string(),2);
		dependencies[x]=get_deps(x);
		debug("done reading dependencies for "+x.string(),4);
	}
	debug("done reading all dependencies",1);
	debug("creating makefile",1);
	create_makefile(dependencies);
	if(settings::compile){
		debug("compiling",1);
		system("make");
	}
	
	return 0;
}
