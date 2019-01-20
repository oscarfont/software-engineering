#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <fstream>

using namespace std;

class Converter{

private:


public:
	//Constructor	
	Converter();
	
	//Destructor
	virtual ~Converter();

	virtual void convert( const string &dir1, const string &dir2 ) = 0;

};

#endif