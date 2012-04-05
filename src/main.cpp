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


int main(int argc, char **argv){
	settings S(argc, argv);
	debug("settings read",1);
	get_code_files(S.source_dir,S);
	debug("got list of code-files",1);
	
	map<path,list<path>> dependencies;
	debug("starting to read dependencies",1);
	for(auto x:S.implementation_files){
		debug("reading dependencies for "+x.string(),2);
		dependencies[x]=get_deps(x,S);
		debug("done reading dependencies for "+x.string(),4);
	}
	debug("done reading all dependencies",1);
	debug("creating makefile",1);
	create_makefile(S,dependencies);
	if(S.compile){
		debug("compiling",1);
		system("make");
	}
	
	return 0;
}