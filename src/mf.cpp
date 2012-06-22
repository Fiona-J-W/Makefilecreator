#include "mf.hpp"

#include <fstream>
using namespace std;

#include "output.hpp"
#include "settings.hpp"

/// Replaces the fileending with new_ending
string replace_ending(path file, string new_ending);

void write_settings(ofstream &output,path relative_dir, map<path,list<path>> dependencies){
	output<<"\n####################\n#Settings:\n\n\n";
	
	output<<"CC = "<<settings::compiler<<"\n";
	
	output<<"CFLAGS = ";
	for(auto opt:settings::compiler_opts){
		output<<opt<<" ";
	}
	output<<"\n";
	
	output<<"CLIBS = ";
	for(auto libdir:settings::lib_dirs){
		output<<"-L"<<libdir<<" ";
	}
	for(auto lib:settings::libs){
		output<<"-l"<<lib<<" ";
	}
	output<<"\n";
	
	output<<"INCLUDES = ";
	for(auto include:settings::include_dirs){
		output<<"-I"<<include<<" ";
	}
	output<<"\n";
	
	output<<"TARGET = "<<(relative_dir/settings::target).string()<<"\n";
	
	output<<"OBJECTS =";//<<settings::includes<<endl;
	if( dependencies.size() <= 3){
		for(auto object:dependencies){
			output<<" "<<replace_ending(relative_dir/settings::build_dir/(object.first.filename()),"o");
		}
	}
	else{
		output << " \\\n";
		for(auto object:dependencies){
			output<<"\t"<<replace_ending(relative_dir/settings::build_dir/(object.first.filename()),"o")<<" \\\n";
		}
	}
	output<<"\n"<<endl;
	
}

void write_rules(ofstream &output,path relative_dir){
	output<<"\n####################\n#Rules:\n\n\n";
	
	output<<"$(TARGET) : $(OBJECTS)\n"
		<<"\t$(CC) $(CFLAGS) $(CLIBS) -o $(TARGET) $(OBJECTS)\n"<<endl;
	
	path build_dir = relative_dir/settings::build_dir;
	
	output << build_dir.string() << "/%.o:\n";
	if( build_dir != path(".") ){
		output << "\t@if test ! -d "<< build_dir.string()
		       << "; then mkdir "<< build_dir.string()
		       << "; echo \"created "<< build_dir.string()
		       << "\" ; fi"<<endl;
	}
	output<<"\t$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<\n\n";
	
	output<<"clean:\n\trm "<<build_dir.string()<<"/*.o\n\n";
	
	output<<"all: $(TARGET)\n"<<endl;
}

void write_dependencies(ofstream &output,path relative_dir, map<path,list<path>> dependencies){
	output<<"\n####################\n#Dependencies:\n\n"<<endl;
	
	path build_dir = relative_dir/settings::build_dir;
	
	for(auto rule:dependencies){
		string obj_name=replace_ending(build_dir/rule.first.filename(),"o");
		output<<obj_name<<": "<<(relative_dir/rule.first).relative_path().string()<<" ";
		for(auto dep:rule.second){
			output<<(relative_dir/dep).string()<<" ";
		}
		//output<<"\n\t$(CC) $(CFLAGS) $(INCLUDES) -c "<<rule.first.string()<<" -o "<<obj_name<<"\n"<<endl;
		output<<"\n\n";
	}
}

int create_makefile(map<path,list<path>> dependencies){
	
	path relative_path(".");
	
	ofstream output(settings::output.c_str());
	
	output<<"# Makefile for "<<settings::target<<"\n# created with makefile-creator\n\n";
	
	write_settings(output,relative_path,dependencies);
	
	write_rules(output,relative_path);
	
	write_dependencies(output,relative_path,dependencies);
	
	output.close();
	
	return 0;
}

string replace_ending(path file, string new_ending){
	string filename=file.string();
	filename.erase(filename.rfind(".")+1);
	return filename+new_ending;
}
