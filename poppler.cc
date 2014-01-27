#include "poppler.h"
#include "TextOutputDev.h"
#include <sstream>
#include <cstring>
#include <iostream>
#include "PDFDocFactory.h"


const double PopplerParser::resolution = 72.0;

PopplerParser::PopplerParser (const std::string inputFilename) {
		GooString *ownerPW, *userPW;
		ownerPW = NULL;
		userPW = NULL;   //assume no user and owner passwords
		char st[inputFilename.length()+1];
		strcpy(st,inputFilename.c_str());
		GooString* fileName;
		fileName = new  GooString(st);
		//create the document
		//assumes no owner or userpassword
		PopplerParser::doc = PDFDocFactory().createPDFDoc(*fileName, ownerPW, userPW);
		PopplerParser::numPages = PopplerParser::doc->getNumPages();
		delete fileName;
	}

int PopplerParser::getPages() {
	return PopplerParser::numPages; 
}


PopplerParser::~PopplerParser() {
	//delete PopplerParser::numPages;
	delete PopplerParser::doc;
}

std::string PopplerParser::Parse() {

		GBool physLayout = gTrue;
		double fixedPitch = 0;
		GBool rawOrder = gFalse;
		GBool htmlMeta = gTrue;  // required to get the bounding box information
		int firstPage = 1;
		int lastPage = PopplerParser::doc->getNumPages();

		TextOutputDev *textOut;
		std::string page_text;
		std::string pages_text_data;

		std::stringstream ss;

		//Word Features
		double xMinA, yMinA, xMaxA, yMaxA, r, g, b, fontSize;
        int tokenNo, lineNo;
		TextWord *word;
		GooString* fontName;
		GBool underLined;
		
		TextFontInfo *fontInfo; 

 		GBool fixedWidth = gFalse; 
  		GBool serif = gFalse;
  		GBool symbolic = gFalse;
  		GBool italic = gFalse;
  		GBool bold =gFalse;


		//create our page
		 // read config file this is requried 
  		globalParams = new GlobalParams();

        // debug
        //std::cout << "firstPage " << firstPage << std::endl;
        //std::cout << "lastPage " << lastPage << std::endl;
        //std::cout << "resolution " << std::endl;
        //std::cout << "physLayout " << physLayout << std::endl;
        //std::cout << "fixedPitch " << fixedPitch << std::endl;
        //std::cout << "rawOrder " << rawOrder << std::endl;
        //std::cout << "htmlMeta " << htmlMeta << std::endl;

		//create a textOut
		textOut = new TextOutputDev(NULL, physLayout, fixedPitch, rawOrder, htmlMeta);
		
		//walk over the pages
		for (int page = firstPage; page <= lastPage; ++page) {
			PopplerParser::doc->displayPage(textOut, page, resolution, resolution, 0, gTrue, gFalse, gFalse);
			TextWordList *wordlist = textOut->makeWordList();
			const int word_length = wordlist != NULL ? wordlist->getLength() : 0;

			if (word_length > 0) {
				//words on the page
        		for (int i = 0; i < word_length; ++i) {
          			word = wordlist->get(i);

          			//Word Features
          			word->getColor(&r , &g, &b);
          			underLined = word->isUnderlined();
          			fontSize = word->getFontSize();
          			word->getBBox(&xMinA, &yMinA, &xMaxA, &yMaxA);
                    word->getTokenNo(&tokenNo);
                    word->getLineNo(&lineNo);
          			fontName = word->getFontName(0);
          			const std::string wordString = word->getText()->getCString();
                    // debug
                    //std::cout << wordString.c_str() << std::endl;
          			//fontIno
          			fontInfo = word->getFontInfo(0);  //do this for the first char in the word
          			fontName = fontInfo->getFontName();
          			fixedWidth = fontInfo ->isFixedWidth();
          			serif = fontInfo->isSerif();
          			symbolic = fontInfo->isSymbolic();
          			italic = fontInfo->isItalic();
          			bold = fontInfo->isBold();

                    // escape quotes in string
                    std::stringstream newStr;
                    for (int i = 0; i < wordString.length(); ++i) {
                        if (wordString[i] == '"' || wordString[i] == '\\') {
                            newStr << "\\";
                        }                
                        newStr << wordString[i];       
                    }
          			//construct our string output
                    ss << "{"
          			<<  "\"xMin\":\"" << xMinA << "\",\"yMin\":\"" << yMinA << "\",\"xMax\":\"" << xMaxA << "\",\"yMax\":\"" << yMaxA 
                    << "\",lineNo\":\"" << lineNo << "\",\"tokenNo\":\"" << tokenNo
          			<< "\",\"red\":\"" << r << "\",\"green\":\"" << g << "\",\"blue\":\""<< b 
          			<< "\",\"fontSize\":\"" << fontSize 
          			<< "\",\"italic\":\"" << italic 
          			<< "\",\"serif\":\"" << serif
          			<< "\",\"symbolic\":\"" << symbolic
          			<< "\",\"fixedWidth\":\"" << fixedWidth
          			<< "\",\"bold\":\""  << bold
          			<< "\",\"fontName\":\"" << fontName->getCString()
          			<< "\",\"word\":\"" << newStr.str() << "\",\"page\":\""<< page 
                    << "\"}"
                    << std::endl;
          			//std::cout << ss.str() << std::endl;
        		}
			}
		}

		delete textOut;
		delete globalParams;
		//delete wordlist;
		pages_text_data = ss.str();
		return pages_text_data;
}

