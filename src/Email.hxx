#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include "Strategy.hxx"

using namespace std;

class Email : public Strategy{

private:

public:

	Email();
	~Email();

	virtual void sendNotification(const string & body, const string & cl, const string & cnt);
};

#endif