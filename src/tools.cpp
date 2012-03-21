#include "tools.hpp"
#include <algorithm>

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


string clean_whitespace(string &str){
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