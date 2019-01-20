#include "Work.hxx"
	
// Constructor
Work::Work(){
	title();
	_checkout = false;
	originalFile();
	isbn();
}

// Destructor
Work::~Work(){}

string Work::title(string s){
	if(this->_stitulo[0] == 0){
		if(s[0] == 0){ 
			this->_stitulo = "-- Untitled --"; 
		}else{ 
			this->_stitulo = s; 
		}	
	}else{
		if(s[0] != 0){ 
			this->_stitulo = s; 
		}
	}
	return(this->_stitulo);
}

int Work::isbn(){
	if(_checkout == false){
		this->_refisbn = -1;
	}
	return(this->_refisbn);	
}

int Work::isbn(int in_ref){
	_checkout = true;
	this->_refisbn = in_ref;
	return(this->_refisbn);
}

string Work::originalFile(std::string o){
	if(this->_ofile[0] == 0){
		if(o[0] == 0){ 
			this->_ofile = ""; 
		}else{ 
			this->_ofile = o; 
		}	
	}else{
		if(o[0] != 0){ 
			this->_ofile = o; 
		}
	}

	return(this->_ofile);
}

string Work::aText(){
	string outString;
	ostringstream stream;
	if(_stitulo == "" || _stitulo == "-- Untitled --"){
		stream << outString << -1;
		outString = stream.str();
		outString = outString + ", '" + "-- Untitled --" + "', ''";
	}else{
		stream << outString << _refisbn;
		outString = stream.str();
		outString = outString + ", '" + _stitulo + "', 'originals/" + _ofile + "'";
	}
		
	return outString;
}

string Work::topics() const {
	string out;
	for(int i = 0; i < int(_topicos.size()); i++){
		out = out + "\t\t'" + _topicos[ i ]->getName() + "'\n";
	}
	return out;
}
	
void Work::associateTopic(Topic &topic){
	_topicos.push_back(&topic);
}