#include "mf.hpp"

#include <fstream>
using namespace std;

#include "output.hpp"

string replace_ending(path file, string new_ending);

int create_makefile(settings &S,map<path,list<path>> dependencies){
	ofstream output(S.output.c_str());
	debug("makefile opened for writing",2);
	output<<"# Makefile for "<<S.target<<"\n# created with makefile-creator\n\n";
	debug("header written",4);
	
	debug("start writing sections „Settings“",3);
	//Settings:
	output<<"\n####################\n#Settings:\n\n"<<endl;
	
	output<<"CC = "<<S.compiler<<endl;
	debug("written compiler",4);
	
	output<<"CFLAGS = ";
	for(auto opt:S.compiler_opts){
		output<<opt<<" ";
	}
	output<<endl;
	debug("written compilerflags",4);
	
	output<<"CLIBS = ";
	for(auto libdir:S.libdirs){
		output<<"-L"<<libdir<<" ";
	}
	for(auto lib:S.libs){
		output<<"-l"<<lib<<" ";
	}
	output<<endl;
	debug("written libs",4);
	
	
	output<<"INCLUDES = ";
	for(auto include:S.include_dirs){
		output<<"-I"<<include<<" ";
	}
	output<<endl;
	debug("written includes",4);
	
	output<<"TARGET = "<<S.target<<endl;
	debug("written target",4);
	
	output<<"OBJECTS = ";//<<S.includes<<endl;
	for(auto object:dependencies){
		output<<replace_ending(S.build_dir/(object.first.filename()),"o")<<" ";
	}
	output<<endl<<endl;
	debug("written objects",4);
	
	
	debug("start writing sections „Rules“",3);
	//Rules:
	output<<"\n####################\n#Rules:\n\n"<<endl;
	
	output<<"$(TARGET) : $(OBJECTS)\n\t$(CC) $(CFLAGS) $(CLIBS) $(OBJECTS) -o $(TARGET)\n"<<endl;
	
	//output<<"%.o: %.cpp\n\t$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@\n"<<endl;
	
	output<<"clean:\n\trm "<<S.build_dir.string()<<"/*.o\n"<<endl;
	
	output<<"all: $(TARGET)\n"<<endl;
	
	debug("start writing sections „Dependencies“",3);
	//Dependencies:
	output<<"\n####################\n#Dependencies:\n\n"<<endl;
	
	for(auto rule:dependencies){
		string obj_name=replace_ending(S.build_dir/rule.first.filename(),"o");
		output<<obj_name<<": "<<rule.first.string()<<" ";
		for(auto dep:rule.second){
			output<<dep.string()<<" ";
		}
		output<<"\n\t$(CC) $(CFLAGS) $(INCLUDES) -c "<<rule.first.string()<<" -o "<<obj_name<<"\n"<<endl;
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