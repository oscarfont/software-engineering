#include "Collection.hxx"

// Constructor
Collection::Collection(){
	this->title();
	_published = false;	
}
	
// Destructor
Collection::~Collection(){}

string Collection::title(const string& a){		
	if(this->_titulo[0] == 0){
		if(a[0] == 0){
			this->_titulo = "-- Untitled --";
		}else{
			this->_titulo = a;
		}
	}else{
		if(a[0] != 0){
			this->_titulo = a;
		}
	}
	return (this->_titulo);
}

bool const Collection::isPublished(){
	return this->_published;
}
	
void Collection::publish(){
	this->_published = true;
}
	
void Collection::withdraw(){
	this->_published = false;
}
	
string Collection::IntToString ( int number ){
	ostringstream oss;

	oss<< number;

	return oss.str();
}	
	
string Collection::workList(){
	int i, idx = 1;
	string out, temp, num;
	ostringstream stream;
	for(i = 0; i < (int)_libros.size(); i++){
		num = IntToString(idx);
		temp = _libros[i]->aText();
		out = out + num + ": " + temp + "\n";
		idx++; 
	}
	return out;
}
	
void Collection::addWork(Work &trabajo){
	_libros.push_back(&trabajo);	
}