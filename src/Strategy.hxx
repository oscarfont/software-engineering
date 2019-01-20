#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <string>
#include "MailStub.hxx"

using namespace std;

class Strategy{

private: 

public:

	Strategy();
	virtual ~Strategy();

	virtual void sendNotification(const string & body, const string & cl, const string & cnt) = 0;

};

#endif