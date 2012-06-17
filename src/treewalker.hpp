#ifndef treewalker
#define treewalker

#include <list>
#include <utility>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

#include "settings.hpp"

/// all sane fileendings for headerfiles
const vector<string> HEADER_ENDINGS={
	"hpp","hxx","hh","h"
};

/// all sane fileendings for files, that contain the actual code
const vector<string> IMPLEMENTATION_ENDINGS={
	"cpp","cxx","cc","c"
};

///Type of the file; should be self-explaining
enum filetype{
	HEADER,
	IMPL,
	OTHER
};

///analyse what filetype @param file is
filetype analyse_file(path file);

///walk the source-dir and get every file that contains code
void get_code_files();

#endif