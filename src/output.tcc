#ifndef output_hpp
	#error "don't include output.tcc directly, use output.hpp instead."
#endif

#ifndef output_tcc
#define output_tcc

namespace logging {

using std::string;
using std::stringstream;
using std::vector;
using std::tuple;


template<typename T>
void _text_helper(stringstream& stream, T arg){
	stream << arg;
}

template<typename T, typename... argT>
void _text_helper(stringstream& stream, T arg,  argT...args){
	stream << arg;
	_text_helper(stream, args...);
}

template<typename... T>
string text(T...args){
	stringstream returnstream;
	_text_helper(returnstream, args...);
	return returnstream.str();
}



template<typename T>
void _textf_helper(vector<string>& vec, T arg){
	stringstream tmpstream;
	tmpstream << arg;
	vec.push_back(tmpstream.str());
}

template<typename T, typename... argT>
void _textf_helper(vector<string>& vec, T arg, argT...args){
	stringstream tmpstream;
	tmpstream << arg;
	vec.push_back(tmpstream.str());
	_textf_helper(vec, args...);
}

string _textf_impl(const string& formatstring, const std::vector<string>& strings);

template<typename...T>
string textf(const string& formatstring, T...args){
	vector<string> strings;
	_textf_helper(strings, args...);
	return _textf_impl(formatstring, strings);
}


} //logging namespace

#endif
