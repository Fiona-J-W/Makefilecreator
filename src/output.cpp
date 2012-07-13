#include "output.hpp"

#include <iostream>
#include <cstdlib>
using namespace std;

static int verbose_level=0;

void set_verbose_level(int v){
	verbose_level=v;
}

void note(string text, int level){
	if(level<=verbose_level){
		cout<<"Note: "<<text<<endl;
	}
}

#if ENABLE_DEBUG == 1
static int debug_level=0;
void debug(string text, int level){
	if( ENABLE_DEBUG ){
		print_debug(text,level);
	}
}

void print_debug(string text, int level){
	if(level<=debug_level){
		cout<<"DEBUG ("<<level<<"): "<<text<<endl;
	}
}

void set_debug_level(int d){
	debug_level=d;
}
#endif

void warn(string text){
	cerr<<"WARNING: "<<text<<endl;
}

void error(string text){
	cerr<<"ERROR: "<<text<<endl;
}

void fatal(string text){
	cerr<<"FATAL: "<<text<<endl;
	exit(1);
}
