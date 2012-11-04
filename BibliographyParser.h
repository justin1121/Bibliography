/*
 *  BibliographyParser.h
 *  BibProcessor
 *
 *  Created by Jocelyne Faddoul on 12-10-15.
 *  Modified by Justin Patriquin on 12-10-25.
 *  Copyright 2012 Dalhousie University. All rights reserved.
 *
 *  Added functions for getting and adding the citationlist. Added
 *  parsing of the input file and extended parsing of the bibliography file.
 *  Did this by adding many functions for parsing the individual values
 *  for the different types of works.
 */

#ifndef BIBLIOGRAPHYPARSER_HPP
#define BIBLIOGRAPHYPARSER_HPP

#include <iostream>
#include <sstream>
#include <fstream>

#include "CitationList.h"
#include "BookData.h"
#include "ConferenceData.h"
#include "JournalData.h"
#include "TechnicalReportData.h"
#include "WebsiteData.h"

const int MAX_SZ_KEY    = 10;
const int MAX_SZ_LINE   = 128;
const int MAX_NUM_REF   = 100;
const int MAX_LINE      = 1000;

using namespace std;

class BibliographyParser {
private:
	ifstream     * bibFile;				/*file stream object pointing to the bibliography file*/
	const char   * bibFileName;		/*bibliography file name*/
	int            inputFile;
	const char   * inputFileName;
	const char   * bookToken;			/*string token used to identify book items e.g., @book{ */
	const char   * conferenceToken;	/*string token used to identify conference items e.g., @conference{ */
	const char   * journalToken ;		/*string token used to identify journal items e.g., @journal{ */
	const char   * techReportToken ;	/*string token used to identify book technical report e.g., @technicalreport{ */
  const char   * websiteToken;
	const char   * endOfItem ;			/*string token used to identify end of item  e.g., }  */
	const char   * endOfFile ;			/*string token used to identify end of file  e.g., }; */
	const char   * startOfInputToken;
	CitationList list;
  string * keys;

	void addCitationList(ResourceData *);
	void setBaseResourceData(ResourceData *, string, string);
	void setBookData(BookData *, string, string);
	void setJournalData(JournalData *, string, string);
	void setConferenceData(ConferenceData *, string, string);
	void setTechnicalReportData(TechnicalReportData *, string, string);
  void setWebsiteData(WebsiteData *, string, string);
  char * readInputFileLine();
  char * getSubStringKey(int, char *, string *);
  void addValidKey(char *, int);
  void formatTextBody(string *,char *, int, int);
public:
	BibliographyParser(const char *, const char *); /*constructor*/
	~BibliographyParser();						 /*destructor*/	
	
	void openFiles(void);
	void closeFiles(void);
	void parseBibliographyItems(void);				/*parse the bibliography file*/	
	void parseInputFile(string *);
	void printBibliography(void);					/*display bibliography file into standard output*/	

	CitationList getCitationList(void);
};

#endif
