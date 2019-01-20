#ifndef WHATSAPP_H
#define WHATSAPP_H

#include <iostream>
#include "Strategy.hxx"

using namespace std;

class Whatsapp : public Strategy{

private:

public:
	
	Whatsapp();
	~Whatsapp();

	virtual void sendNotification(const string & body, const string & cl, const string & cnt);
};

#endif