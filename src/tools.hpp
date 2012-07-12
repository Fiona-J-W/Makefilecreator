#ifndef tools
#define tools

#include <vector>
#include <string>
#include <utility>
#include <list>
#include <fstream>
#include <set>
#include <boost/filesystem.hpp>

using namespace std;
using boost::filesystem::path;

/**
 * checks whether val is in vec 
 */
bool in(string val, const vector<string> &vec);

/**
 * cut str into pieces, wherever it contains a delim
 * @param str string to be cut
 * @param delim delimeter, that marks the cutlines
 */
vector<string> cut(string str, string delim=".");

/**
 * cut string at the first occurance of delim
 * @param str string to be cut 
 * @param delim delimeter that marks the cutline
 */
pair<string,string> cut_once(string str, string delim="=");

/**
 * clean whitespace from the beginning of str 
 * @param str string to be stripped
 */
string strip(string &str);

/**
 * write t to stream:
 * @param t list of values to be written to the stream
 * @param stream stream that the list will be written to
 */
template<typename T>
ostream& operator<<(ostream &stream,list<T> t);

/**
 * create a list from t that contains only unique members
 * @param t List that will be freed from double-members
 */
template<typename T>
list<T> remove_double(list<T> t);

/**
 * remove unneeded dots
 * @param p the unclean path
 */
path clean_path(path p);

/**
 * get a relative path that shows from startpath to target 
 * @param startpath path from which the returnvalue will point to targetpath
 * @param targetpath to which the relative path to target will be created
 */
path get_rel_path(path startpath, path targetpath = path("."));

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
