#ifndef tools
#define tools

#include <vector>
#include <string>
#include <utility>
#include <list>
#include <fstream>
#include <set>

using namespace std;

/// checks whether @param val is in @param vec
bool in(string val, const vector<string> &vec);

/// cut @param str into pieces, wherever it contains a @param delim
vector<string> cut(string str, string delim=".");

/// cut @param string at the first occurance of @param delim
pair<string,string> cut_once(string str, string delim="=");

/// clean whitespace from the beginning of @param str
string clean_whitespace(string &str);

/// write @param t to @param stream:
template<typename T>
ostream& operator<<(ostream &stream,list<T> t);

/// create a list from @param t that contains only unique members
template<typename T>
list<T> remove_double(list<T> t);



//Public because templates are used:

template<typename T>
ostream& operator<<(ostream &stream,list<T> t){
	stream<<"[";
	for(auto &i:t){
		stream<<i;
		if(&i!=&t.back()){
			stream<<",";
		}
		
	}
	stream<<"]";
	return stream;
}


template<typename T>
list<T> remove_double(list<T> t){
	set<T> tmp;
	for(auto x:t){
		tmp.insert(x);
	}
	t.clear();
	for(auto x:tmp){
		t.push_back(x);
	}
	return t;
}


#endif