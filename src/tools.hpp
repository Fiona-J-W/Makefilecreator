#ifndef tools
#define tools

#include <vector>
#include <string>
#include <utility>
#include <list>
#include <fstream>
#include <set>

using namespace std;

bool in(string val, const vector<string> &vec);

vector<string> cut(string str, string delim=".");

pair<string,string> cut_once(string str, string delim="=");

string clean_whitespace(string &str);

template<typename T>
ostream& operator<<(ostream &stream,list<T> t);

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