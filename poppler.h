#include <string>
#include <iostream>
#include "PDFDoc.h"
#include "Page.h"
#include "GlobalParams.h"

using namespace std;

class PopplerParser 
{
	PDFDoc *doc;
	std::string f;
public:

	PopplerParser (const std::string inputFilename); 
	std::string Parse(); 
	int getPages();
	//~PopplerParser();
	int numPages;
	static const double resolution;
};
