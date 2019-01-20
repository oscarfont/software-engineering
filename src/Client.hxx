#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Observer.hxx"
#include "MailStub.hxx"
#include "Strategy.hxx"
#include "Email.hxx"
#include "SMS.hxx"
#include "Whatsapp.hxx"

using namespace std;

class Client : Observer{
	
	// Attributes
	string _name;
	string _email;
	Strategy* _estrat;

public:

	// Contructor
	Client();
	
	// Destructor
	virtual ~Client();
	string getName();
	void setName(const string &n);
	string getEmail();
	void setEmail(const string &e);
	string update(const string &c, const string &e, const string &w, const string &a);
	void Update(const string &aut, const string &work);
	void preferSMS(const string &tlf);
	void preferWhastpp(const string &tlf);
};

#endif