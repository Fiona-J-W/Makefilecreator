# MFC - makefilecreator

mfc is a programm, that searches for all codefiles in the current (or a given) 
directory and creates a valid makefile, that contains all dependencies.

##Background

Anyone who develops C or C++ without an IDE is forced to create his own makefiles 
and even though there are tools that make this process easier (mostly by checking 
dependencies), you still have to add every file you write manually. While this is a 
pretty flexible way to create makefiles, you are using relativly strict conventions 
in reality nevertheless: Usually implementations are put in one kind of files 
(.c/.cpp/…) and include headers (.h/.hpp/…). In rare cases (mostly when using 
templates) you might consider to include an implementation-file from a header and 
therefore not compile it. Anything else is extremly untypical and usualy bad style.

This tool is developed to create makefiles for projects that have a structure like 
the one discribed above much more simple.

##State of development 

Although mfc is in an early state, it should work on most projects, that follow the 
described organisation. However, improvements will be done in the future, as there 
are still several possible features, that aren't implemented yet.

##Installation and Requirements

To build mfc you need a compiler that supports C++11 and boost. If these 
requirements are fullfilled, just execute the makefile.

For installation just move the executable to a directory in $PATH.

