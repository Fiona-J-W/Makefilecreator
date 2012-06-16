#include "settings.hpp"

#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

#include "tools.hpp"
#include "output.hpp"


map<string,char> FILE_OPTS={
	{"source-dir",'s'},
	{"build-dir",'b'},
	{"target",'t'},
	{"output",'o'},
	{"verbose",'v'},
	{"debug",'d'},
	{"use",'u'},
	{"ignore",'w'},
	{"compiler",'c'},
	{"link",'l'},
	{"link-dir",'L'},
	{"include-dir",'I'},
	{"compiler-opts",'O'},
	{"import",'i'}
};


//Put the static members with some sane defaults here:
list<path>    settings::header_files;
list<path>    settings::implementation_files;
string        settings::target                  = "a.out";
string        settings::output                  = "makefile";
path          settings::source_dir              = ".";
path          settings::build_dir               = ".";
list<path>    settings::ignore_files;
string        settings::compiler                = "g++";
bool          settings::compile                 = false;
list<string>  settings::include_dirs;
list<string>  settings::libdirs;
list<string>  settings::libs;
list<string>  settings::compiler_opts;
map<string,list<pair<char, string>>> settings::conditional_settings;


void settings::init(int argc, char **argv){
	int opt;
	
	vector<string> config_files={
		"/etc/mfc/mfc.conf",
		(path(getenv("HOME"))/path(".config/mfc/mfc.conf")).string(),
		"./mfc.conf"
	};
	
	for(auto c:config_files){
		if(exists(c)){
			parse_file(c);
		}
	}
	
	
	//parse commandline-opts:
	while ((opt = getopt_long(argc, argv, "s:b:t:o:u:w:c:d:v:l:L:I:O:C",OPTIONS,NULL)) != -1){
		set_opt(opt,optarg?optarg:"");
	}
	
	
	
	if(output.empty()){
		output=(source_dir/"makefile").string();
	}
}


void settings::parse_file(string filename){
	ifstream file(filename.c_str());
	if(!file.is_open()){
		error("file "+filename+" cannot be opened");
		return;
	}
	string line;
	pair<string,string> tmp;
	while(getline(file,line)){
		clean_whitespace(line);
		if(line[0]=='#'){
			continue;
		}
		if(line.empty()){
			continue;
		}
		if(line.find("set ")==0){
			list<pair<char, string>> s;
			string name=line.substr(4);
			clean_whitespace(name);
			size_t pos=min(name.find(' '),name.find('{'));
			if(pos!=string::npos){
				name.erase(pos);
			}
			
			while(getline(file,line)){
				clean_whitespace(line);
				if(line.find("}")==0){
					break;
				}
				if(line[0]=='#'){
					continue;
				}
				if(line.empty()){
					continue;
				}
				tmp=cut_once(line,"=");
				s.push_back(pair<char,string>(FILE_OPTS[tmp.first],tmp.second));
			}
			conditional_settings[name]=s;
			if(!getline(file,line)){
				break;
			}
		}
		tmp=cut_once(line,"=");
		string key=tmp.first;
		set_opt(FILE_OPTS[key],tmp.second);
	}
	
	file.close();
}

void settings::set_opt(char opt,string val){
	switch(opt){
		case 's':
			source_dir=val;
			break;
		case 'b':
			build_dir=val;
			break;
		case 't':
			target=val;
			break;
		case 'o':
			output=val;
			break;
		case 'c':
			compiler=val;
			break;
		case 'v':
			set_verbose_level(atoi(val.c_str()));
			break;
		case 'd':
			set_debug_level(atoi(val.c_str()));
			break;
		case 'u':
			for(auto s:conditional_settings[val]){
				set_opt(s.first,s.second);
			}
			break;
		case 'w':
			ignore_files.push_back(path(val));
			debug("added „"+val+"“ to ignore-list",4);
			break;
		case 'C':
			compile=true;
			break;
		case 'l':
			libs.push_back(val);
			break;
		case 'L':
			libdirs.push_back(val);
			break;
		case 'I':
			include_dirs.push_back(val);
			break;
		case 'O':
			compiler_opts.push_back(val);
			break;
		case 'f':
		case 'i':
			parse_file(val);
			break;
		default:
			warn("Unknown option with value „"+val+"“");
			break;
	}
}

