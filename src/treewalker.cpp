#include "treewalker.hpp"

#include "tools.hpp"

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

pair<list<path>,list<path>> get_code_files(path rootdir){
	pair<list<path>,list<path>> returndata;
	recursive_directory_iterator it(rootdir);
	while(it!=recursive_directory_iterator()){
		switch(analyse_file(*it)){
			case HEADER:
				returndata.first.push_back(*it);
				break;
			case IMPL:
				returndata.second.push_back(*it);
				break;
			case OTHER:
				break;
		}
		++it;
	}
	return returndata;
}