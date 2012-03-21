#ifndef treewalker
#define treewalker

#include <list>
#include <utility>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

#include "settings.hpp"

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

void get_code_files(path rootdir, settings &S);

#endif