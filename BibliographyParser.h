/*
 *  BibliographyParser.h
 *  BibProcessor
 *
 *  Created by Jocelyne Faddoul on 12-10-15.
 *  Copyright 2012 Dalhousie University. All rights reserved.
 *
 */

#ifndef BIBLIOGRAPHYPARSER_HPP
#define BIBLIOGRAPHYPARSER_HPP

#include <iostream>
#include <fstream>
using namespace std;

class BibliographyParser {
	
	
private:
	ifstream* myfile;				/*file stream object pointing to the bibliography file*/
	const char* mybibFileName;		/*bibliography file name*/
	const char* bookToken;			/*string token used to identify book items e.g., @book{ */
	const char* conferenceToken;	/*string token used to identify conference items e.g., @conference{ */
	const char* journalToken ;		/*string token used to identify journal items e.g., @journal{ */
	const char* techReportToken ;	/*string token used to identify book technical report e.g., @technicalreport{ */
	const char* enfOfItem ;			/*string token used to identify end of item  e.g., }  */
	const char* endOfFile ;			/*string token used to identify end of file  e.g., }; */
	
public:
	BibliographyParser(const char* bibfilename); /*constructor*/
	~BibliographyParser();						 /*destructor*/	
	
	void parseBibliographyItems();				/*parse the bibliography file*/	
	void printBibliography();					/*display bibliography file into standard output*/	
	void openBibFile();							/*open bibliography file stream*/	
	void closeBibFile();						/*close bibliography file streamr*/	
	
};

#endif