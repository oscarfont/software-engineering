#ifndef MLTPTON_H
#define MLTPTON_H

#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Author.hxx"
#include "ConverterGroup.hxx"
#include "Channel.hxx"
#include "gui/Model.hxx"
#include <fstream>

using namespace std;
typedef vector<Author*> vecauthors;
typedef vector<Topic*> vectopics;
typedef vector<Client*> vecclients;
typedef vector<Channel*> vecchannels;

class MeltingPotOnline : public Model{
	
	// Attributes
	vecauthors _autors;
	ConverterGroup _ConverterGroup;
	vectopics _topics;
	vecclients _clients;
	vecchannels _channels;

public:

	// Constructor
	MeltingPotOnline();
	MeltingPotOnline(const string &configFile);
	
	// Destructor
	~MeltingPotOnline();
	
	string catalogue() const;
	void addAuthor( const string & name, bool contracted );
	void addWork( const string & authorName, const string & title, int isbn, const string & original );
	int findAuthorindex(const string &n);
	void addTopic( const string & name );
	string listTopics() const;
	Topic& findTopic(const string &topicName);
	Client& findClient(const string &clientName);
	void associateTopicWithWork( const string & topicName, const string & authorName, const string & workTitle );
	string listClients();
	void addClient(const string &c, const string &e);
	void subscribeClientToTopic(const string &c, const string &t);
	string listSubscribedToTopic(const string &t);
	void subscribeClientToAuthor(const string &c, const string &a);
	void addChannel(const string & name, const string & des);
	string listThematicChannels();
	string rssByChannel(const string &a);
	int findChannelindex(const string &c);
	void subscribeChannelToAuthor(const string &c, const string &a);
	int findTopicIndex(const string &topicName);
	void subscribeChannelToTopic(const string &c, const string &t);
	void clientPrefersSms(const string & client, const string &numb);
	void clientPrefersWhatsapp(const string & client, const string &numb);
	int findClientIndex(const string &clientName);
};

#endif
