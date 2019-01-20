#include "PdfConverter.hxx"

//Constructor
PdfConverter::PdfConverter():
_printable(true){}

//Destructor
PdfConverter::~PdfConverter(){
}

void PdfConverter::convert (const string &dir1, const string &dir2){

	string filename;
	if(_printable == false){
		filename = dir2 + " [" + _watermark + "].pdf";
		LibreOfficeTools::convertToPdf( dir1, filename, _watermark );
	}else{
		filename = dir2 + " [printable].pdf";
		std::ofstream os(filename.c_str());
		os << "Already in PDF format!";
	}		
}
	
void PdfConverter::activateWatermark(const string &wtmrk){
	_printable = false;
	_watermark = wtmrk;
}