#include "depcheck.hpp"

#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

#include "settings.hpp"
#include "tools.hpp"
#include "output.hpp"

vector<path> get_includes(path file, set<path>& touched_files){
	debug(3,"reading dependencies for „"+file.string()+"“");
	if( touched_files.count(file) ){
		debug(4, "\tfile is already known");
		return vector<path>();
	}
	else{
		touched_files.insert(file);
	}
	vector<path> includes;
	string line;
	ifstream filestream(file.c_str());
	path file_dir=file.parent_path();
	while(getline(filestream,line)){
		line = strip(line);
		if(line[0]=='#' && strip(line.substr(1)).find("include")==0){
			line.erase(0,sizeof("#include"));
			line = strip(line);
			if(line[0]!='"') continue;
			line.erase(0,1);
			size_t pos;
			if((pos=line.find('"'))==string::npos) continue;
			line.erase(pos);
			
			path include=clean_path(file_dir/path(line));
			if(std::find(settings::header_files.begin(),
			             settings::header_files.end(),include)
			   == settings::header_files.end()
			){
				if(std::find(
					settings::implementation_files.begin(),
					settings::implementation_files.end(),
					include)
				   == settings::implementation_files.end()
				){
					continue;
				}
			}
			includes.push_back(include);
		}
	}
	vector<path> secondary_includes, tmp;
	for(auto i:includes){
		tmp=get_includes(i, touched_files);
		secondary_includes.insert(secondary_includes.end()--,
		                          tmp.begin(),tmp.end());
	}
	includes.insert(includes.end()--,secondary_includes.begin(),
	                secondary_includes.end());
	return includes;
}


vector<path> get_deps(path startfile){
	set<path> touched_files;
	vector<path> includes=get_includes(startfile, touched_files);
	includes=remove_double(includes);
	return includes;
}
