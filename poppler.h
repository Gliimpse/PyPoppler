#include <string>
#include <iostream>
#include <poppler-document.h>
#include <poppler-page.h>


using namespace std;

class PopplerParser 
{
	poppler::document *doc;
	std::string f;
public:

	PopplerParser (const std::string inputFilename, const std::string outputFilename); 
	std::string Parse(int page_idx); 
	int getPages();
	//~PopplerParser();
	int numPages;
};
