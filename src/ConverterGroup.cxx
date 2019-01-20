#include "ConverterGroup.hxx"

//Constructor
ConverterGroup::ConverterGroup(){}

//Destructor
ConverterGroup::~ConverterGroup(){
	for(int i = 0; i < int(_Converters.size()); i++){			
		if( _Converters[ i ]) 
			delete (_Converters[ i ]);	
	}
}
	
void ConverterGroup::add( const string &mode ){
		
	Converter* c;

	if(mode == "html"){
		c = new HtmlConverter();
		_Converters.push_back(c);
	}

	else if(mode == "pdf_print"){
		c = new PdfConverter();
		_Converters.push_back(c);
	}

	else if(mode == "pdf_mark"){
		c = new PdfConverter();
		((PdfConverter*) c)->activateWatermark( "watermark" );
		_Converters.push_back(c);
	}
		
	else if(mode == ""){
		throw NoConverterException();
	}
	
	else
		throw UnknownConverter();

}
	
void ConverterGroup::convert ( const string &dir1, const string &dir2 ){
		
	for(int i = 0; i < int(_Converters.size()); i++){			
		_Converters[ i ]->convert( dir1, dir2 );	
	}

}