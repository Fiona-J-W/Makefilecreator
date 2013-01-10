#ifndef treewalker
#define treewalker

#include <vector>
#include <utility>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;


/**
 * Type of the file; should be self-explaining
 */
enum filetype{
	HEADER,
	IMPL,
	OTHER
};

/**
 * analyse what filetype param file is
 */
filetype analyse_file(path file);

/**
 * walk the source-dir and get every file that contains code
 */
void get_code_files();

#endif
