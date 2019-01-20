#ifndef COLLECTION_H
#define COLLECTION_H

#include "Work.hxx"

using namespace std;
typedef vector<Work*> workL;

class Collection{
	
	// Attributes
	string _titulo;
	workL _libros;
	bool _published;
	
public:	
	
	// Constructor
	Collection();

	// Destructor
	~Collection();

	string title(const string& a = "");
	bool const isPublished();
	void publish();
	void withdraw();
	string IntToString ( int number );	
	string workList();
	void addWork(Work &trabajo);
};

#endif