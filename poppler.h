#include <string>
#include <iostream>
#include "PDFDoc.h"
#include "Page.h"
#include "GlobalParams.h"
#include <stdio.h>

using namespace std;

class PopplerParser 
{
	PDFDoc *doc;
	std::string f;
public:

	PopplerParser (FILE * inputFile); //const std::string inputFilename); 
	std::string Parse(); 
	int getPages();
	~PopplerParser();
	int numPages;
	static const double resolution;
};
