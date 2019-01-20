#ifndef HTMLCONV_H
#define HTMLCONV_H

#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "libLibreOffice2Html.hxx"
#include "Converter.hxx"
#include "Exception.hxx"
#include <iostream>
#include <fstream>

using namespace std;

class HtmlConverter : public Converter
{

private:

	
public:
	//Constructor
	HtmlConverter();
	
	~HtmlConverter();

	void convert (const string &direc1, const string &direc2);

}; 

#endif