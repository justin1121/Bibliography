/*
 *  BibliographyParser.cpp
 *  BibProcessor
 *
 *  Created by Jocelyne Faddoul on 12-10-15.
 *  Copyright 2012 Dalhousie University. All rights reserved.
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "BibliographyParser.h"
#include "BookData.h"
#include "ConferenceData.h"
#include "JournalData.h"
#include "TechnicalReportData.h"

using namespace std;

/*
 * BibliographyParser constructor
 * - initializes the bibliography file name
 */
BibliographyParser::BibliographyParser (const char* bibFleName ) {
  list = new CitationList[1];

	mybibFileName = bibFleName;
	bookToken= "@book{";
	conferenceToken = "@conference{";
	journalToken = "@journal{";
	techReportToken = "@technicalreport{";
	endOfItem = "}";
	endOfFile = "};";
}

/*
 * BibliographyParser destructor
 */
BibliographyParser::~BibliographyParser(){
}

/*
 * Open the bibliography file 
 * - initialize a file stream object, ifstream, to read from the bibliography.txt file
 */
void BibliographyParser::openBibFile(){
	myfile= new ifstream(mybibFileName);
	if (myfile->is_open())
	{
		cout<< "bibliography file opened successfully \n";
		
	}
	else cout << "Unable to open bibliography file \n";
	
}

/*
 * Close the bibliography file 
 * - close the file stream associated with biliography.txt file
 */
void BibliographyParser:: closeBibFile(){
	if (myfile->is_open())
	{
		myfile->close();
		cout<< "bibliography file closed successfully \n";
		
	}else cout<< "Unable to close bibliography file \n";
}

/*
 * Parse the bibliography items in the bibliography file 
 * - requires an open file stream associated with bibliography.txt file
 * - the bibliography items are collected into a multimap container
 * - the multimap container elements consists of key value pairs used to fetch and organize the bibliography items
 * - 
 * - 
 */
void BibliographyParser::parseBibliographyItems(){
	
	if (myfile->is_open())
	{
		/* type of the collection holding the bibliography items' information
		 * - a multimap of key,value pairs such that the key is used to identify the item's type
		 * - the following key identification are used 
		 * - 1: book
		 * - 2: conference article
		 * - 3: journal article
		 * - 4: technical report
		 * - the value is a string representing information about the item.
		 */
		string line;
		int itemIdentifier = 0;
		string itemString="";
		
		while(myfile->good())
		{
			string stringToken;
			getline (*myfile,line);
			
			string itemStream;
			
			stringstream sStream(line);
			while (sStream >> stringToken){
				if (stringToken.compare(bookToken) == 0){
					/* "reading book information"*/
					itemIdentifier = 1;
					itemString = "";
				}else if (stringToken.compare(conferenceToken) == 0){
					/* "reading conference information"*/
					itemIdentifier = 2;
					itemString="";
				}else if (stringToken.compare(journalToken) == 0){
					/* "reading journal information"*/
					itemIdentifier = 3;
					itemString = "";
				}else if (stringToken.compare(techReportToken)==0){
					/* "reading technical report information"*/
					itemIdentifier = 4;
					itemString = "";
				}else if ((stringToken.compare(endOfItem)==0) || (stringToken.compare(endOfFile)==0)){
					/* add the item to the collection */
					itemString = itemString + "\n";

					/*reset item's identifier and information string*/
					itemIdentifier = 0;
					itemString = "";
				}else{
					itemString = itemString + " " + stringToken;
				}
			}
		}
	}
	else {
    cout << "bibliography file not opened \n";
  }
}

/*
 *This function prints the bibliography file
 *- line by line, to the standard output
 *- requires an open file stream object, myfile
 */
void BibliographyParser::printBibliography(){
	
	if (myfile->is_open())
	{
		string line;
		while(myfile->good())
		{
			string val;
			// get file information line by line
			getline (*myfile,line);
			// display each line
			cout <<line << endl;
			
		}
		
	}
	else cout << "bibliography file not opened \n";
	
	
}
