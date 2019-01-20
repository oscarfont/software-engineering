#include "MeltingPotOnline.hxx"

// Constructor
MeltingPotOnline::MeltingPotOnline(){
	_ConverterGroup.add( "html" );
	_ConverterGroup.add( "pdf_print" );
	_ConverterGroup.add( "pdf_mark" );
}
	
MeltingPotOnline::MeltingPotOnline(const string &configFile){
	std::ifstream config ( configFile.c_str() );
	string format;
	while( config >> format )
	{
		_ConverterGroup.add( format );
	}
}
	
// Destructor
MeltingPotOnline::~MeltingPotOnline(){
	for( int i = 0; i < int ( _autors.size() ); i++ ){
		if( _autors[i] ) 
			delete _autors[i];	
	}
	for( int i = 0; i < int ( _topics.size() ); i++ ){
		if( _topics[i] ) 
			delete _topics[i];	
	}
	for( int i = 0; i < int ( _clients.size() ); i++ ){
		if( _clients[i] ) 
			delete _clients[i];	
	}
	for( int i = 0; i < int ( _channels.size() ); i++ ){
		if( _channels[i] ) 
			delete _channels[i];	
	}
}
	
string MeltingPotOnline::catalogue() const{
	string ct;
	vector<Work*> trabajosAutor;
	for( int i = 0; i < int ( _autors.size() ); i++ ){ 
		ct = ct + _autors[ i ]->description();
		trabajosAutor = _autors[ i ]->getTrabajos();
		for(int j = 0; j < int (trabajosAutor.size()); j++){
			ct = ct + trabajosAutor[ i ]->topics();
		}	
	}
	return ct;
}
	
void MeltingPotOnline::addAuthor( const string & name, bool contracted ){
	Author *autor = new Author();
	autor->name(name);
	if(contracted != false){
		autor->contract();
	}
	_autors.push_back(autor);
}
	
void MeltingPotOnline::addWork( const string & authorName, const string & title, int isbn, const string & original ){
	int index = findAuthorindex(authorName);
	_autors[index]->addWork(title, isbn, original);
	std::string fullname( "originals/" );
	fullname += original;
	std::ifstream is( fullname.c_str() );
	if(is == 0){
		throw FileException();
	}
	string outname;
	outname = "generated/" + authorName + " - " + title;
	_ConverterGroup.convert( fullname, outname );
}
	
int MeltingPotOnline::findAuthorindex(const string &n){
	for( int i = 0; i < int( _autors.size() ); i++ ){
		if( _autors[ i ]->name() == n ){
			return i;
		}
	}
	throw AuthorException();
}
	
void MeltingPotOnline::addTopic( const string & name ){
	Topic *topic = new Topic();
	topic->setName(name);
	_topics.push_back(topic);
}
	
string MeltingPotOnline::listTopics() const{
	string top;
	for( int i = 0; i < int ( _topics.size() ); i++ ){ 
		 top = top + _topics[ i ]->getName() + "\n";
	}
	return top;
}
	
Topic& MeltingPotOnline::findTopic(const string &topicName){ 
	for( int i = 0; i < int ( _topics.size() ); i++ ){ 
		if(topicName == _topics[ i ]->getName()){
			return *_topics[ i ];
		}
	}
	throw InexistentTopic();
}
	
Client& MeltingPotOnline::findClient(const string &clientName){ 
	for( int i = 0; i < int ( _clients.size() ); i++ ){ 
		if(clientName == _clients[ i ]->getName()){
			return *_clients[ i ];
		}
	}
	throw InexistentClient();
}
	
void MeltingPotOnline::associateTopicWithWork( const string & topicName, const string & authorName, const string & workTitle ){
	if(topicName == "" || topicName == "Inexistent topic" ){
		throw InexistentTopic();
	}
	int Authorindex = findAuthorindex(authorName);
	int TopicIndex = findTopicIndex(topicName);
	Work & work = _autors[Authorindex]->findWork(workTitle);
	Topic & topic = findTopic(topicName);
	work.associateTopic(topic);	
	vecclients subscribedClients = topic.getSubscribedClients();
	for(int i = 0; i < int( subscribedClients.size() ); i++){
		topic.notify(subscribedClients[i]->getName(), subscribedClients[i]->getEmail(), workTitle, authorName);
	}
	_topics[ TopicIndex ]->Notify(_autors[Authorindex]->name(), work.title());
}
	
string MeltingPotOnline::listClients(){
	string cli;
	for( int i = 0; i < int ( _clients.size() ); i++ ){ 
		 cli = cli + _clients[ i ]->getName() + " <" + _clients[ i ]->getEmail() + ">\n";
	}
	return cli;
}
	
void MeltingPotOnline::addClient(const string &c, const string &e){
	Client *clnt = new Client();
	clnt->setName(c);
	clnt->setEmail(e);
	_clients.push_back(clnt);
}
	
void MeltingPotOnline::subscribeClientToTopic(const string &c, const string &t){
	Client & client = findClient(c);
	Topic & topic = findTopic(t);
	topic.subscribeClient(client);
}
	
string MeltingPotOnline::listSubscribedToTopic(const string &t){
	Topic & topic = findTopic(t);
	return (topic.listSubscribed());
}
	
void MeltingPotOnline::subscribeClientToAuthor(const string &c, const string &a){
	int authIndx = findAuthorindex(a);
	Client &newSub = findClient(c); 
	_autors[authIndx]->setSubsClient(newSub);
}

void MeltingPotOnline::addChannel(const string & name, const string & des){
	Channel *channel = new Channel();
	channel->setName(name);
	channel->setDescription(des);
	channel->generateHtml();
	_channels.push_back(channel);
}

string MeltingPotOnline::listThematicChannels(){
	string aux;
	for( int i = 0; i < int ( _channels.size() ); i++ ){ 
		 aux = aux + _channels[i]->listChannel() + "\n";
	}
	return aux;
}

string MeltingPotOnline::rssByChannel(const string &a){
	int index = findChannelindex(a);
	return _channels[ index ]->html() + "</channel>\n</rss>\n";	
}

int MeltingPotOnline::findChannelindex(const string &c){
	for( int i = 0; i < int( _channels.size() ); i++ ){
		if( _channels[ i ]->name() == c ){
			return i;
		}
	} throw InexistentChannel();
}

void MeltingPotOnline::subscribeChannelToAuthor(const string &c, const string &a){
	int AuthIndex = findAuthorindex(a);
	int ChanIndex = findChannelindex(c);

	_autors[AuthIndex]->addsubChannel(*_channels[ChanIndex]);
}

int MeltingPotOnline::findTopicIndex(const string &topicName){ 
	for( int i = 0; i < int ( _topics.size() ); i++ ){ 
		if(topicName == _topics[ i ]->getName()){
			return i;
		}
	}
	throw InexistentTopic();
}

void MeltingPotOnline::subscribeChannelToTopic(const string &c, const string &t){
	int TopicIndex = findTopicIndex(t);
	int chanIndex = findChannelindex(c);

	_topics[ TopicIndex ]->addsubsChannel(*_channels[ chanIndex ]);
}

int MeltingPotOnline::findClientIndex(const string &clientName){ 
	for( int i = 0; i < int ( _clients.size() ); i++ ){ 
		if(clientName == _clients[ i ]->getName()){
			return i;
		}
	}
	throw InexistentClient();
}

void MeltingPotOnline::clientPrefersSms(const string & client, const string &numb){
	int clienIndx = findClientIndex(client);
	_clients[clienIndx]->preferSMS(numb);
}	

void MeltingPotOnline::clientPrefersWhatsapp(const string & client, const string &numb){
	int clienIndx = findClientIndex(client);
	_clients[clienIndx]->preferWhastpp(numb);
}
