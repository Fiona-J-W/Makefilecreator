#ifndef treewalker
#define treewalker

#include <list>
#include <utility>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

const vector<string> HEADER_ENDINGS={
	"h","hpp"
};

const vector<string> IMPLEMENTATION_ENDINGS={
	"cpp","cxx","cc","c"
};

enum filetype{
	HEADER,
	IMPL,
	OTHER
};

filetype analyse_file(path file);

pair<list<path>,list<path>> get_code_files(path rootdir=".");

#endif