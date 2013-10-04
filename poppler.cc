#include "poppler.h"

PopplerParser::PopplerParser (const std::string inputFilename) {
		cout << "input filename " << inputFilename << endl;

		//create the document
		//assumes no owner or userpassword
		PopplerParser::doc = poppler::document::load_from_file(inputFilename);
		PopplerParser::numPages = PopplerParser::doc->pages();
		cout << PopplerParser::numPages << endl;
	}

int PopplerParser::getPages() {
	return PopplerParser::numPages; 
}

std::string PopplerParser::Parse(int page_idx) {
		//make a dummy rectable
		//poppler::rectf rect = poppler::rectf();
		//cout << "rectangle is empty " << endl;
		//cout << rect.is_empty() << endl;

		//lets walk over the pages
		//for (int page_idx = 0; page_idx <= PopplerParser::numPages; ++page_idx) {
			//get a page
		poppler::page *page =  PopplerParser::doc->create_page(page_idx);
		//string to hold our text
		std::string page_text;
		//now we can get the text from the page. 
		//page_text = page->text(rect, poppler::page::physical_layout);
		page_text = page->stringText();
		//cout << "page text " << endl;
		//PopplerParser::f = page_text.to_latin1();
		return page_text;
}

