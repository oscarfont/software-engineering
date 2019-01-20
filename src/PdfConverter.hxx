#ifndef PDFCONVRT_H
#define PDFCONVRT_H

#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "libLibreOffice2Pdf.hxx"
#include "Converter.hxx"
#include <iostream>
#include <fstream>

using namespace std;

class PdfConverter : public Converter
{

private:
	//boolean that indicates the mode: printable or watermark.
	bool _printable;
	string _watermark;

public:
	//Constructor
	PdfConverter();

	//Destructor
	~PdfConverter();

	void convert (const string &dir1, const string &dir2);
	void activateWatermark(const string &wtmrk);

};

#endif