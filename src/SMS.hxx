#ifndef SMS_H
#define SMS_H

#include <iostream>
#include "Strategy.hxx"

using namespace std;

class SMS : public Strategy{

private:

public:
	
	SMS();
	~SMS();

	virtual void sendNotification(const string & body, const string & cl, const string & cnt);
};

#endif