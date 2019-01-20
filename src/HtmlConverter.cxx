#include "HtmlConverter.hxx"

//Constructor
HtmlConverter::HtmlConverter(){}
	
HtmlConverter::~HtmlConverter(){}

void HtmlConverter::convert (const string &direc1, const string &direc2){
		
	string filename;
	filename = direc2 + " [multiple HTML files].war";		
	std::ofstream os(filename.c_str());
		
	const char* odtFile = direc1.c_str();
	const char* warFile = filename.c_str();
	OO_WarGeneration(odtFile, warFile);
	if(OO_WarGeneration(odtFile, warFile) == -1){
		throw FileException();
	}

}
