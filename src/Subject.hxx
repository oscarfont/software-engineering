#ifndef SUBJECT_H
#define SUBJECT_H

#include "Exception.hxx"
#include "Observer.hxx" 
#include <fstream>
#include <vector>

using namespace std;
typedef vector<Observer*> vecobservers;

class Subject{
	
	vecobservers _observers;

public:

	Subject();
	
	virtual~Subject();
	
	void Attach(Observer &observer);
	void Detach(Observer &observer);
	void Notify(const string &aut, const string &work);
};

#endif 