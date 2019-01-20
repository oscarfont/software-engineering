#ifndef CONVGROUP_H
#define CONVGROUP_H

#include "HtmlConverter.hxx"
#include "PdfConverter.hxx"
#include "Exception.hxx"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<Converter*> VecConv;

class ConverterGroup
{
private:

	VecConv _Converters;
	
public:
	//Constructor
	ConverterGroup();

	//Destructor
	~ConverterGroup();
	
	void add( const string &mode = "");
	void convert ( const string &dir1, const string &dir2 );
};

#endif