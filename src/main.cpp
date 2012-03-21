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
	debug("settings read");
	auto files=get_code_files(S.source_dir);
	debug("got list of code-files");
	list<path> headers=files.first, implementations=files.second;
	
	map<path,list<path>> dependencies;
	debug("starting to read dependencies");
	for(auto x:implementations){
		debug("reading dependencies for "+x.string(),2);
		dependencies[x]=get_deps(x,headers);
		debug("done reading dependencies for "+x.string(),4);
		//cout<<x<<":\t"<<dependencies[x]<<endl;
	}
	debug("done reading all dependencies");
	debug("creating makefile");
	create_makefile(S,dependencies);
	if(S.compile){
		debug("compiling");
		system("make");
	}
	
	return 0;
}