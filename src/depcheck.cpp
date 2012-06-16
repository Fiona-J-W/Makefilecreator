#include "depcheck.hpp"

#include <fstream>
#include <algorithm>
using namespace std;

#include "tools.hpp"

list<path> get_includes(path file){
	list<path> includes;
	string line;
	ifstream filestream(file.c_str());
	path file_dir=file.parent_path();
	while(getline(filestream,line)){
		clean_whitespace(line);
		if(line.find("#include")==0){
			line.erase(0,sizeof("#include"));
			clean_whitespace(line);
			if(line[0]!='"') continue;
			line.erase(0,1);
			size_t pos;
			if((pos=line.find('"'))==string::npos) continue;
			line.erase(pos);
			
			path include=file_dir/path(line);
			if(std::find(settings::header_files.begin(),settings::header_files.end(),include)==settings::header_files.end()){
				if(std::find(settings::implementation_files.begin(),settings::implementation_files.end(),include)==settings::implementation_files.end()){
					continue;
				}
			}
			includes.push_back(include);
		}
	}
	list<path> secondary_includes, tmp;
	for(auto i:includes){
		tmp=get_includes(i);
		secondary_includes.insert(secondary_includes.end()--,tmp.begin(),tmp.end());
	}
	includes.insert(includes.end()--,secondary_includes.begin(),secondary_includes.end());
	return includes;
}


list<path> get_deps(path startfile){
	list<path> includes=get_includes(startfile);
	includes=remove_double(includes);
	return includes;
}
