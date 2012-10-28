/*
 *  BibliographyParser.h
 *  BibProcessor
 *
 *  Created by Jocelyne Faddoul on 12-10-15.
 *  Modified by Justin Patriquin on 12-10-25.
 *  Copyright 2012 Dalhousie University. All rights reserved.
 *
 */

#ifndef BIBLIOGRAPHYPARSER_HPP
#define BIBLIOGRAPHYPARSER_HPP

#include <iostream>
#include <fstream>

#include "CitationList.h"

using namespace std;

class BibliographyParser {
private:
	ifstream     * bibFile;				/*file stream object pointing to the bibliography file*/
	const char   * bibFileName;		/*bibliography file name*/
	ifstream     * inputFile;
	const char   * inputFileName;
	const char   * bookToken;			/*string token used to identify book items e.g., @book{ */
	const char   * conferenceToken;	/*string token used to identify conference items e.g., @conference{ */
	const char   * journalToken ;		/*string token used to identify journal items e.g., @journal{ */
	const char   * techReportToken ;	/*string token used to identify book technical report e.g., @technicalreport{ */
	const char   * endOfItem ;			/*string token used to identify end of item  e.g., }  */
	const char   * endOfFile ;			/*string token used to identify end of file  e.g., }; */
	const char   * startOfInputToken;
	CitationList * list;

	void addCitationList(ResourceData *);
public:
	BibliographyParser(const char *, const char *); /*constructor*/
	~BibliographyParser();						 /*destructor*/	
	
	void openFiles(void);
	void closeFiles(void);
	void parseBibliographyItems(void);				/*parse the bibliography file*/	
	void parseInputFile(void);
	void printBibliography(void);					/*display bibliography file into standard output*/	

	CitationList * getCitationList(void);
};

#endif