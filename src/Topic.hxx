#ifndef TOPIC_H
#define TOPIC_H

#include "Client.hxx"
#include "Exception.hxx"
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "MailStub.hxx"
#include "Subject.hxx"
#include "Channel.hxx"
#include <fstream>

using namespace std;
typedef vector<Client*> vecclients;

class Topic : public Subject{
	
	// Attributes
	string _name;
	vecclients _clients;
	Channel* _subsChan;
	
public:
	
	// Constructor
	Topic();
	
	// Destructor
	~Topic();
	
	string getName();
	void setName(const string &n);
	void subscribeClient(Client &client);
	vecclients getSubscribedClients();
	string listSubscribed();
	Client& findClient(const string &clientName);
	int findClientIndex(const string &clientName);
	void notify(const string &c, const string &e, const string &w, const string &a);
	void Notify(const string &aut, const string &work);
	void addsubsChannel(Channel & newChan);
};

#endif