/*
 *  BibliographyParser.cpp
 *  BibProcessor
 *
 *  Created by Jocelyne Faddoul on 12-10-15.
 *  Modified by Justin Patriquin 12-10-26.
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
BibliographyParser::BibliographyParser(const char* bibFleName, const char * inputFileName) {
	BibliographyParser::bibFileName   = bibFleName;
	BibliographyParser::inputFileName = inputFileName;
	bookToken                         = "@book{";
	conferenceToken                   = "@conference{";
	journalToken                      = "@journal{";
	techReportToken                   = "@technicalreport{";
	endOfItem                         = "}";
	endOfFile                         = "};";
	startOfInputToken                 = "/{";
}

/*
 * BibliographyParser destructor
 */
BibliographyParser::~BibliographyParser(void){
}

/*
 * Open the bibliography file 
 * - initialize a file stream object, ifstream, to read from the bibliography.txt file
 */
void BibliographyParser::openFiles(void){
	bibFile   = new ifstream(bibFileName);
	inputFile = new ifstream(inputFileName);

	if (bibFile->is_open()){
		cout << "Bibliography file opened successfully!\n";
	}
	else{
		cout << "Unable to open bibliography file!\n";
	}
	if(inputFile->is_open()){
		cout << "Input file opened successfully!\n";
	}
	else{
		cout << "Unable to open inputfile!\n";
	}
}

/*
 * Close the bibliography file 
 * - close the file stream associated with biliography.txt file
 */
void BibliographyParser::closeFiles(void){
	if (bibFile->is_open()){
		bibFile->close();
		cout << "bibliography file closed successfully \n";
	}
	else{ 
		cout << "Unable to close bibliography file \n";
	}
	if(inputFile->is_open()){
		inputFile->close();
		cout << "Input file close successfully!\n";
	}
	else{
		cout << "Unable to close input file!\n";
	}
}

/*
 * Parse the bibliography items in the bibliography file 
 * - requires an open file stream associated with bibliography.txt file
 * - the bibliography items are collected into a multimap container
 * - the multimap container elements consists of key value pairs used to fetch and organize the bibliography items
 * - 
 * - 
 */
void BibliographyParser::parseBibliographyItems(void){
	if (bibFile->is_open())
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

		ResourceData * d;
		while(bibFile->good())
		{
			string stringToken;
			getline (*bibFile,line);
			
			string itemStream;
			
			stringstream sStream(line);
			while (sStream >> stringToken){
				cout << stringToken << "\n";
				if (stringToken.compare(bookToken) == 0){
					/* "reading book information"*/
					itemIdentifier = 1;
					itemString = "";
					d = new BookData();
				}else if (stringToken.compare(conferenceToken) == 0){
					/* "reading conference information"*/
					itemIdentifier = 2;
					itemString="";
					d = new ConferenceData();
				}else if (stringToken.compare(journalToken) == 0){
					/* "reading journal information"*/
					itemIdentifier = 3;
					itemString = "";
					d = new JournalData();
				}else if (stringToken.compare(techReportToken)==0){
					/* "reading technical report information"*/
					itemIdentifier = 4;
					itemString = "";
					d = new TechnicalReportData();
				}else if ((stringToken.compare(endOfItem)==0) || (stringToken.compare(endOfFile)==0)){
					/* add the item to the collection */
					itemString = itemString + "\n";
					
					/* Set the data and add it to the citation list */
					d->setData(itemIdentifier, (char *)itemString.c_str());
					if(d->getType() == 1){
						d->print();
					}
					addCitationList(*d);

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
void BibliographyParser::printBibliography(void){
	
	if (bibFile->is_open()){
		string line;
		while(bibFile->good()){
			string val;
			// get file information line by line
			getline(*bibFile, line);
			// display each line
			cout << line << endl;
		}
	}
	else{
		cout << "bibliography file not opened \n";
	}
}


CitationList BibliographyParser::getCitationList(void){
	return list;
}


void BibliographyParser::addCitationList(ResourceData data){
	list.addCitation(data);
}


void BibliographyParser::parseInputFile(void){
}