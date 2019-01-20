#include "Author.hxx"

// Constructor
Author::Author(){
	name(); 
	_contracted = false;
	_subsChan = NULL;
}

// Destructor
Author::~Author(){
	for( int i = 0; i < int ( _trabajos.size() ); i++ ){
		if( _trabajos[i] ) 
			delete _trabajos[i];	
	}
}

const string Author::catalogue(){
	if(_cat.empty()){
		string a = "";
		_cat = a;
	}						
	return _cat;
}

workL Author::getTrabajos(){
	return _trabajos;
}

const string Author::name(const string& aut){	
	if(this->_name[0] == 0){
		if(aut.empty()){ 
			this->_name = ""; 
		}else{ 
			this->_name = aut; 
		}	
	}else{
		if(!(aut.empty())){ 
			this->_name = aut; 
		}
	}

	return(this->_name);
}

const string Author::description(){
	string out;
	if(_contracted == false){
		out = out + _name + " [external]\n" + _cat;
	}else{
		out = out + _name + " [contracted]\n" + _cat;
	}
	return out;
}

void Author::Notify (const string &aut, const string &work){
	for(int i = 0; i < int(_subsCli.size()); i++){
		if(_subsCli[ i ]){
			_subsCli[ i ]->Update(aut, work);
		}
	}

	if(_subsChan != NULL){
		_subsChan->Update(aut, work);
	} 
}

void Author::addWork(const string& titulo, int ref, string file){
	string w;
	Work *trabajo = new Work();
	trabajo->title(titulo);
	trabajo->isbn(ref);
	trabajo->originalFile(file);
	_trabajos.push_back(trabajo);
	w = trabajo->aText();
	_cat = _cat + "\t" + w + "\n";
	if(_subsCli.size() > 0){

		Notify(name(), titulo);

	}else if(_subsChan != NULL){

		Notify(name(), titulo);

	}
}
	
Work& Author::findWork(const string& tit){
	for( int i = 0; i < int( _trabajos.size() ); i++ ){
		if( _trabajos[ i ]->title() == tit ){
			return *_trabajos[ i ];
		}
	}
	throw WorkException();
}

bool const Author::isContracted(){
	return this->_contracted;
}
	
void Author::contract(){
	this->_contracted = true;
}

void Author::setSubsClient(Client &newsubsCl){
	_subsCli.push_back(&newsubsCl);
}

void Author::addsubChannel(Channel & newsubsChannel){
	_subsChan = &newsubsChannel;
}