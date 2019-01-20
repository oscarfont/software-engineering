#include "Topic.hxx"
	
// Constructor
Topic::Topic(){
	_subsChan = NULL;
}
	
// Destructor
Topic::~Topic(){
	MailStub::theInstance().removeSent();
}
	
string Topic::getName(){
	return _name;
}
	
void Topic::setName(const string &n){
	_name = n;
}
	
void Topic::subscribeClient(Client &client){
	_clients.push_back(&client);
}
	
vecclients Topic::getSubscribedClients(){
	return _clients;
}

string Topic::listSubscribed(){
	string out;
	for(int i = 0; i < int(_clients.size()); i++){
		out = out + _clients[ i ]->getName() + "\n";
	}
	return out;
}
	
Client& Topic::findClient(const string &clientName){ 
	for( int i = 0; i < int ( _clients.size() ); i++ ){ 
		if(clientName == _clients[ i ]->getName()){
			return *_clients[ i ];
		}
	}
	throw InexistentClient();
}

int Topic::findClientIndex(const string &clientName){ 
	for( int i = 0; i < int ( _clients.size() ); i++ ){ 
		if(clientName == _clients[ i ]->getName()){
			return i;
		}
	}
	throw InexistentClient();
}
	
void Topic::notify(const string &c, const string &e, const string &w, const string &a){
	int clInd= findClientIndex(c);
	_clients[clInd]->Update(a, w);
}

void Topic::Notify(const string &aut, const string &work){
	if(_subsChan != NULL){
		_subsChan->Update(aut, work);
	}
}

void Topic::addsubsChannel(Channel & newChan){
	_subsChan = &newChan;
}