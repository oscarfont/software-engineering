#ifndef WORK_H
#define WORK_H

#include "Topic.hxx"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;
typedef vector<Topic*> vectopics;

class Work{

	// Attributes
	string _stitulo;
	string _ofile;
	int _refisbn;
	bool _checkout;
	vectopics _topicos;
	
public:	
	
	// Constructor
	Work();

	// Destructor
	~Work();

	string title(string s = "");
	int isbn();
	int isbn(int in_ref);
	string originalFile(std::string o = "");
	string aText();
	string topics() const ;
	void associateTopic(Topic &topic);
};

#endif