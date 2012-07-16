#include "help.hpp"

#include <iostream>

using namespace std;

void print_help(string name){
	cout
	<< "Makefilecreator\n\n"
	
	<< "Usage: " << name <<" [options] \n\n"
	
	<< "  -h, --help                 print this help and terminate\n"
	<< "  -s, --source-dir=dir       add a directory to the list of source-directories\n"
	<< "  -b, --build-dir=dir        set the build-dircetory, where the objectfiles will be put\n"
	<< "  -t, --target=path          set the build-target\n"
	<< "  -o, --output=path          set the pathes to the created makefiles\n"
	<< "  -v, --verbose=number       set the level of verbosity\n"
	<< "  -d, --debug=number         set the debuglevel (only in debug-builds)\n"
	<< "  -e, --header-ending=ending add a fileending as ending of header-files\n"
	<< "  -E, --impl-ending=ending   add a fileanding as ending of code-files\n"
	<< "  -c, --compiler=command     set the compiler\n"
	<< "  -C, --compile              execute make after creating the makefile\n"
	<< "  -l, --link=library         link the target against a library\n"
	<< "  -L, --link-dir=dir         add a libdir to the program\n"
	<< "  -I, --inlude-dir=dir       add an include-directory\n"
	<< "  -w, --ignore=file          completly ignore a codefile\n"
	<< "  -H, --header=file          treat a file as headerfile\n"
	<< "  -f, --config-file=file     treat the given file as config-file\n"
	<< "  -u, --use=label            use a set of labeled settings\n"
	<< "  -O, --compiler-opts=opts   pass some options to the compiler\n"
	<< "  -p, --pkg-libs=libname     use a libraries pkg-config to include it\n"
	<<endl;
}

