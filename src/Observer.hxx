#ifndef OBSERVER_H
#define OBSERVER_H

#include <fstream>

using namespace std;

class Observer{


public:

	virtual void Update(const string &aut, const string &work);
};

#endif 