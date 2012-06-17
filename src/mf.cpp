#include "mf.hpp"

#include <fstream>
using namespace std;

#include "output.hpp"
#include "settings.hpp"

/// Replaces the fileending with @param new_ending
string replace_ending(path file, string new_ending);

int create_makefile(map<path,list<path>> dependencies){
	ofstream output(settings::output.c_str());
	debug("makefile opened for writing",2);
	output<<"# Makefile for "<<settings::target<<"\n# created with makefile-creator\n\n";
	debug("header written",4);
	
	debug("start writing sections „Settings“",3);
	//Settings:
	output<<"\n####################\n#Settings:\n\n"<<endl;
	
	output<<"CC = "<<settings::compiler<<endl;
	debug("written compiler",4);
	
	output<<"CFLAGS = ";
	for(auto opt:settings::compiler_opts){
		output<<opt<<" ";
	}
	output<<endl;
	debug("written compilerflags",4);
	
	output<<"CLIBS = ";
	for(auto libdir:settings::libdirs){
		output<<"-L"<<libdir<<" ";
	}
	for(auto lib:settings::libs){
		output<<"-l"<<lib<<" ";
	}
	output<<endl;
	debug("written libs",4);
	
	
	output<<"INCLUDES = ";
	for(auto include:settings::include_dirs){
		output<<"-I"<<include<<" ";
	}
	output<<endl;
	debug("written includes",4);
	
	output<<"TARGET = "<<settings::target<<endl;
	debug("written target",4);
	
	output<<"OBJECTS =";//<<settings::includes<<endl;
	if( dependencies.size() <= 3){
		for(auto object:dependencies){
			output<<" "<<replace_ending(settings::build_dir/(object.first.filename()),"o");
		}
	}
	else{
		output << " \\\n";
		for(auto object:dependencies){
			output<<"\t"<<replace_ending(settings::build_dir/(object.first.filename()),"o")<<" \\\n";
		}
	}
	output<<endl<<endl;
	debug("written objects",4);
	
	
	debug("start writing sections „Rules“",3);
	//Rules:
	output<<"\n####################\n#Rules:\n\n"<<endl;
	
	output<<"$(TARGET) : $(OBJECTS)\n"
		<<"\t$(CC) $(CFLAGS) $(CLIBS) -o $(TARGET) $(OBJECTS)\n"<<endl;
	
	debug("objectfiles",4);
	output <<settings::build_dir.string()<<"/%.o:\n";
	if( settings::build_dir != path(".") ){
		output <<"\t@if test ! -d "<<settings::build_dir.string()
		       <<"; then mkdir "<<settings::build_dir.string()
		       <<"; echo \"created "<<settings::build_dir.string()
		       <<"\" ; fi"<<endl;
	}
	output<<"\t$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<\n"<<endl;
	
	output<<"clean:\n\trm "<<settings::build_dir.string()<<"/*.o\n"<<endl;
	
	output<<"all: $(TARGET)\n"<<endl;
	
	debug("start writing sections „Dependencies“",3);
	//Dependencies:
	output<<"\n####################\n#Dependencies:\n\n"<<endl;
	
	for(auto rule:dependencies){
		string obj_name=replace_ending(settings::build_dir/rule.first.filename(),"o");
		output<<obj_name<<": "<<rule.first.string()<<" ";
		for(auto dep:rule.second){
			output<<dep.string()<<" ";
		}
		//output<<"\n\t$(CC) $(CFLAGS) $(INCLUDES) -c "<<rule.first.string()<<" -o "<<obj_name<<"\n"<<endl;
		output<<"\n\n";
	}
	
	output.close();
	debug("writing makefile done",2);
	return 0;
}

string replace_ending(path file, string new_ending){
	string filename=file.string();
	filename.erase(filename.rfind(".")+1);
	return filename+new_ending;
}
