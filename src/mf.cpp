#include "mf.hpp"

#include <fstream>
using namespace std;

#include "output.hpp"
#include "settings.hpp"
#include "tools.hpp"

/// Replaces the fileending with new_ending
string replace_ending(path file, string new_ending);

void write_settings(ofstream &output,path relative_dir, map<path,vector<path>> dependencies){
	output<<"\n####################\n#Settings:\n\n\n";
	
	if(settings::compiler.empty()) {
		output<<"CXX ?= g++\n";
	}
	else {
		output<<"CXX = " << settings::compiler<<"\n";
	}
	
	output<<"FLAGS += ";
	for(auto opt:settings::compiler_opts){
		output<<opt<<" ";
	}
	output<<"\n";
	
	output<<"LIBS += ";
	for(auto libdir:settings::lib_dirs){
		output<<"-L"<<libdir<<" ";
	}
	for(auto lib:settings::libs){
		output<<"-l"<<lib<<" ";
	}
	for(auto lib:settings::pkg_libs){
		output<<" $$( pkg-config --libs "<<lib<<" ) ";
	}
	output<<"\n";
	
	output<<"INCLUDES += ";
	for(auto include:settings::include_dirs){
		output<<"-I"<<include<<" ";
	}
	for(auto include:settings::pkg_libs){
		output<<" $$( pkg-config --cflags "<< include <<" ) ";
	}
	output<<"\n";
	
	output<<"TARGET = "<<(clean_path(relative_dir/settings::target)).string()<<"\n";
	
	output<<"OBJECTS =";
	if( dependencies.size() <= 3){
		for(auto object:dependencies){
			output<<" "<<replace_ending(clean_path(relative_dir/settings::build_dir/(object.first.filename())),"o");
		}
	}
	else{
		output << " \\\n";
		for(auto object:dependencies){
			output<<"\t"<<replace_ending(clean_path(relative_dir/settings::build_dir/(object.first.filename())),"o")<<" \\\n";
		}
	}
	output<<"\n"<<endl;
	
}

void write_rules(ofstream &output,path relative_dir){
	output<<"\n####################\n#Rules:\n\n\n";
	
	//be nice to ubuntu and put the libs to the end of the commandline m(
	output<<"$(TARGET) : $(OBJECTS)\n"
		<<"\t$(CXX) $(FLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)\n"<<endl;
	
	path build_dir = clean_path(relative_dir/settings::build_dir);
	
	if( build_dir != path("") ){
		output << build_dir.string() << "/%.o:\n";
	}
	else{
		output << "%.o:\n";
	}
	if( build_dir != path(".") && build_dir != path("") ){
		output << "\t@if test ! -d '"<< build_dir.string()
		       << "'; then mkdir '"<< build_dir.string()
		       << "'; echo \"created '"<< build_dir.string()
		       << "'\" ; fi"<<endl;
	}
	output<<"\t$(CXX) $(FLAGS) $(INCLUDES) -c -o $@ $<\n\n";
	
	if( build_dir != path("") ){
		output<<"clean:\n\trm "<<build_dir.string()<<"/*.o\n\n";
	}
	else{
		output<<"clean:\n\trm *.o\n\n";
	}
	
	output<<"all: $(TARGET)\n"<<endl;
}

void write_dependencies(ofstream &output,path relative_dir, map<path,vector<path>> dependencies,
		const std::string& makefile){
	output<<"\n####################\n#Dependencies:\n\n"<<endl;
	
	path build_dir = clean_path(relative_dir/settings::build_dir);
	
	for(auto rule:dependencies){
		string obj_name=replace_ending(build_dir/rule.first.filename(),"o");
		output<<obj_name<<": "<<clean_path(relative_dir/rule.first).relative_path().string()<<" ";
		for(auto dep:rule.second){
			output<<clean_path(relative_dir/dep).string()<<" ";
		}
		output << makefile << "\n\n";
	}
}

int create_makefile(map<path,vector<path>> dependencies){
	
	for(auto filename: cut(settings::output,",")){
		debug(1, string("output=")+filename);
		path relative_path(get_rel_path(path(strip(filename)),path(".")));
		debug(2, string("relative path=")+relative_path.string());
		
		ofstream output(strip(filename).c_str());
		
		output<<"# Makefile for "<<settings::target<<"\n# created with makefile-creator\n\n";
		
		write_settings(output,relative_path,dependencies);
		
		write_rules(output,relative_path);
		
		write_dependencies(output,relative_path,dependencies, path(filename).filename().string());
		
		output.close();
	}
	debug(3, "outputs written");
	return 0;
}

string replace_ending(path file, string new_ending){
	string filename=file.string();
	filename.erase(filename.rfind(".")+1);
	return filename+new_ending;
}
