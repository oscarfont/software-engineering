#include "Client.hxx"

// Contructor
Client::Client(){
	_estrat = NULL; 
}

// Destructor
Client::~Client(){
	if(_estrat != NULL){
		delete _estrat;
	}
}

string Client::getName(){
	return _name;
}
	
void Client::setName(const string &n){
	_name = n;
}
	
string Client::getEmail(){
	return _email;
}
	
void Client::setEmail(const string &e){
	_email = e;
}
	
string Client::update(const string &c, const string &e, const string &w, const string &a){
	string mail = "new work " + w + " by " + a;
    return mail;
}

void Client::Update(const string &aut, const string &work){
	string body = update(getName(), getEmail(), work, aut);
	if(_estrat != NULL){
		body = "[MeltingPot] " + body;
		_estrat->sendNotification(body, getName(), getEmail());
	}else{
		_estrat = new Email();
		_estrat->sendNotification(body, getName(), getEmail());
	}
}

void Client::preferSMS(const string &tlf){
	_estrat = new SMS();
	setEmail(tlf);
}

void Client::preferWhastpp(const string &tlf){
	_estrat = new Whatsapp();
	setEmail(tlf);
}