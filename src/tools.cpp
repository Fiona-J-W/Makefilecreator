#include "tools.hpp"
#include <algorithm>
#include "output.hpp"

bool in(string val, const vector<string> &vec){
	return std::find(vec.begin(),vec.end(),val) != vec.end();
}



vector<string> cut(string str, string delim){
	size_t pos;
	vector<string> data;
	while((pos=str.find(delim))!=string::npos){
		data.push_back(str.substr(0,pos));
		str.erase(0,pos+delim.size());
	}
	if(!str.empty()){
		data.push_back(str);
	}
	return data;
}


string strip(string str){
	size_t pos=0;
	while(str[pos]==' '||str[pos]=='\t'){
		++pos;
	}
	str.erase(0,pos);
	return str;
}


pair<string,string> cut_once(string str, string delim){
	size_t pos=str.find(delim);
	pair<string,string> data;
	data.first=str.substr(0,pos);
	data.second=str.substr(pos+delim.size());
	
	return data;
}



path clean_path(path p){
	auto raw = cut( p.string(), "/");
	vector<string> dirs;
	for(auto dir: raw){
		if( dir == "." ){
			continue;
		}
		else if( dir == ".." ){
			if( dirs.size() > 0 ){
				if( dirs.back() == ".." ){
					dirs.push_back("..");
				}
				else{
					dirs.pop_back();
				}
			}
			else{
				dirs.push_back("..");
			}
		}
		else{
			dirs.push_back(dir);
		}
	}
	if( dirs.size() == 0 ){
		return path();
	}
	else{
		path returnpath(dirs.front());
		for(auto it = ++(dirs.begin()); it != dirs.end(); ++it){
			returnpath/=path(*it);
		}
		return returnpath;
	}
}

#include <iostream>
using namespace std;

path get_rel_path(path startpath, path targetpath){
	path returnpath(".");
	
	debug(2, string("get_rel_path( ")+startpath.string()+" , "+targetpath.string()+" )");
	
	auto start_path_l  = cut( clean_path( absolute( startpath  ).remove_filename() ).string(), "/" );
	auto target_path_l = cut( clean_path( absolute( targetpath ) ).string(), "/" );
	
	debug(3, "absolute startpath="+ absolute(startpath).string());
	debug(3, "absolute targetpath="+absolute(targetpath).string());
	size_t i=0;
	for(; i<start_path_l.size() && i<target_path_l.size(); ++i){
		if( start_path_l[i] == target_path_l[i] ){
			debug(4, string("equal path (")+to_string(i)+"):"+target_path_l[i]);
			continue;
		}
		else{
			break;
		}
	}
	debug(5, "i="+to_string(i));
	for(size_t j=i;j<start_path_l.size();++j){
		debug(5, "j="+to_string(j)+"/"+to_string(start_path_l.size())+" „"+start_path_l[j]+"“");
		if(start_path_l[i] != ".")
			returnpath = path("..")/returnpath;
	}
	for(size_t j=i;j<target_path_l.size();++j){
		returnpath/=target_path_l[j];
	}
	return returnpath;
}



//path simplify_rel_path(path relpath, path startpath){
path simplify_rel_path(path, path){
	return path();
}
