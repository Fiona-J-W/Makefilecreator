#include "treewalker.hpp"

#include <algorithm>
using namespace std;

#include "tools.hpp"
#include "output.hpp"

filetype analyse_file(path file){
	if(!is_regular_file(file)){
		return OTHER;
	}
	string filename=file.filename().string();
	string filename_extension=cut(filename,".").back();
	if(in(filename_extension,HEADER_ENDINGS)){
		return HEADER;
	}
	else if(in(filename_extension,IMPLEMENTATION_ENDINGS)){
		return IMPL;
	}
	else return OTHER;
}

void get_code_files(path rootdir,settings &S){
	recursive_directory_iterator it(rootdir);
	while(it!=recursive_directory_iterator()){
		debug("Checking filetype of "+path(*it).string(),3);
		if(find(S.ignore_files.begin(),S.ignore_files.end(),*it)!=S.ignore_files.end()){
			debug("ignored "+path(*it).string(),2);
			++it;
			continue;
		}
		switch(analyse_file(*it)){
			case HEADER:
				S.header_files.push_back(*it);
				break;
			case IMPL:
				S.implementation_files.push_back(*it);
				break;
			case OTHER:
				break;
		}
		++it;
	}
}