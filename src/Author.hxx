#ifndef AUTHOR_H
#define AUTHOR_H

#include "Collection.hxx"
#include "Exception.hxx"
#include <sstream>
#include <iterator>
#include "Subject.hxx"
#include "Client.hxx"
#include "Channel.hxx"

using namespace std;
typedef vector<Work*> workL;
typedef vector<Client*> vecSubs;

class Author : public Subject{
	
	// Attributes
	string _name;
	string _cat;
	workL _trabajos;
	bool _contracted;
	vecSubs _subsCli;
	Channel* _subsChan;
	
public:
	
	// Constructor
	Author();

	// Destructor
	~Author();

	const string catalogue();
	workL getTrabajos();
	const string name(const string& aut = "");
	const string description();
	void addWork(const string& titulo, int ref, string file);
	Work& findWork(const string& tit);
	bool const isContracted();
	void contract();
	void setSubsClient(Client &newsubsCl);
	void Notify (const string &aut, const string &work);
	void addsubChannel(Channel & newsubsChannel);
};

#endif