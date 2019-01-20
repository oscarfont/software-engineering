#include "Subject.hxx"

//Constructor
Subject::Subject(){}

//Destructor
Subject::~Subject(){}

void Subject::Attach(Observer &observer){
	_observers.push_back(&observer);
}
	
void Subject::Detach(Observer &observer){
	_observers.erase(_observers.end());
}