/*
 *  BibliographyParser.cpp
 *  BibProcessor
 *
 *  Created by Jocelyne Faddoul on 12-10-15.
 *  Modified by Justin Patriquin 12-10-26.
 *  Copyright 2012 Dalhousie University. All rights reserved.
 *
 */

#include <string>
#include <map>
#include <cstdlib>
#include <regex.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>
#include <fcntl.h>
#include <cstddef>

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
  keys                              = new string[MAX_REF];
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

	if (bibFile->is_open()){
		cout << "Bibliography file opened successfully!\n";
	}
	else{
		cout << "Unable to open bibliography file!\n";
	}
  if((inputFile = open(inputFileName, O_RDONLY)) != -1){
    cout << "Input file opened successfully!\n";
  }
  else{
    cout << "Unabled to open input file!\n";
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

		ResourceData * d;
		while(bibFile->good())
		{
			string idenToken, tempToken, valueString;
			getline (*bibFile,line);
			
			stringstream sStream(line);
			//this gets the identifying token for each value possible
			while (sStream >> idenToken){
				if (idenToken.compare(bookToken) == 0){
					/* "reading book information"*/
					itemIdentifier = 1;
					d = new BookData();
				}else if (idenToken.compare(conferenceToken) == 0){
					/* "reading conference information"*/
					itemIdentifier = 2;
					d = new ConferenceData();
				}else if (idenToken.compare(journalToken) == 0){
					/* "reading journal information"*/
					itemIdentifier = 3;
					d = new JournalData();
				}else if (idenToken.compare(techReportToken)==0){
					/* "reading technical report information"*/
					itemIdentifier = 4;
					d = new TechnicalReportData();
				}else if ((idenToken.compare(endOfItem)==0) || (idenToken.compare(endOfFile)==0)){
					/* Set the data type and add it to the citation list */
					d->setType(itemIdentifier);

					addCitationList(d);
					/*reset item's identifier and information string*/
					itemIdentifier = 0;
				}else{
					// pop the equals sign and than the value off the stream
					sStream >> tempToken;
					sStream >> tempToken;
					
					//continue until a ';' is found
					while(tempToken.compare(";") != 0){
						// add the value to the value string
						valueString = valueString + tempToken + " "; 
						//pop next value part of the value off or ';' if it is the end
						sStream >> tempToken;
					}
					//checks the identifying token with each base data parameter.
					setBaseResourceData(d, idenToken, valueString);

					//checks the type and then checks the identifier with all of the
					//different types of values for each of the different types of works
					switch(itemIdentifier){
					case 1:
						setBookData((BookData *)d, idenToken, valueString);
						break;
					case 2:
						setConferenceData((ConferenceData *)d, idenToken, valueString);
						break;
					case 3:
						setJournalData((JournalData *)d, idenToken, valueString);
						break;
					case 4:
						setTechnicalReportData((TechnicalReportData *)d, idenToken, valueString);
						break;
					}
					//pops the last thing off 
					sStream >> tempToken;
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

/****************************************************************
 * getCitationList
 *
 * Returns the list.
 ***************************************************************/
CitationList BibliographyParser::getCitationList(void){
	return list;
}

/****************************************************************
 * addCitationList
 *
 * Adds a citation data to a list. 
 ***************************************************************/
void BibliographyParser::addCitationList(ResourceData * data){
	list.addCitation(data);
}


void BibliographyParser::parseInputFile(void){
  string line;
  int err;

  char regex[32] = "\\\\cite";
  char errbuf[128];
  char * chLine;
  regex_t p; 

  if(err = regcomp(&p, regex, REG_ICASE)){
    regerror(err, &p, errbuf, 128);
    cout << errbuf << "\n";
    exit(1);
  } 

  regmatch_t q[1];

  int index = 0;
  while((chLine = readInputFileLine()) != NULL){
    while(regexec(&p, chLine, 1, q, 0) == 0){
      addValidKey(getSubStringKey(q[0].rm_eo, chLine), index);
      index++;
    }
    delete chLine;
  }
}

/******************************************************************
 * setBaseResourceData 
 *
 * Checks each of the tokens against each of the types of parameter
 * and then sets the type to the value of valueToken if it exists
 * here.
 *****************************************************************/
void BibliographyParser::setBaseResourceData(ResourceData * data, string token, string valueToken){
    if(token.compare(data->keyToken) == 0){
        data->setKey(valueToken);
    }  
    else if(token.compare(data->authorToken) == 0){
        data->setAuthor(valueToken);
    }  
    else if(token.compare(data->dateToken) == 0){
        data->setDate(valueToken);
    }  
    else if(token.compare(data->titleToken) == 0){
        data->setTitle(valueToken);
    }  
}

/******************************************************************
 * setBookData
 *
 * Similar to the above but specific to the Book type.
 *****************************************************************/
void BibliographyParser::setBookData(BookData * data, string token, string valueToken){
    if(token.compare(data->placeToken) == 0){
        data->setPlace(valueToken);
    }  
    else if(token.compare(data->publisherToken) == 0){
        data->setPublisher(valueToken);
    }  

}

/******************************************************************
 * setJournalData
 *
 * Similar to the above but specific to the Journal type.
 *****************************************************************/
void BibliographyParser::setJournalData(JournalData * data, string token, string valueToken){
    if(token.compare(data->journalToken) == 0){
        data->setJournal(valueToken);
    }  
    else if(token.compare(data->volumeToken) == 0){
        data->setVolume(valueToken);
    }  
    else if(token.compare(data->numberToken) == 0){
        data->setNumber(valueToken);
    }  
    else if(token.compare(data->pagesToken) == 0){
        data->setPages(valueToken);
    }  
}

/******************************************************************
 * setConferenceData
 *
 * Similar to the above but specific to the Conference type.
 *****************************************************************/
void BibliographyParser::setConferenceData(ConferenceData * data, string token, string valueToken){
    if(token.compare(data->proceedingsToken) == 0){
        data->setProceedings(valueToken);
    }  
    else if(token.compare(data->placeOfConferenceToken) == 0){
        data->setPlaceOfConference(valueToken);
    }  
    else if(token.compare(data->dateOfConferenceToken) == 0){
        data->setDateOfConference(valueToken);
    }  
    else if(token.compare(data->cityToken) == 0){
        data->setCity(valueToken);
    }  
    else if(token.compare(data->publisherToken) == 0){
        data->setPublisher(valueToken);
    }  
    else if(token.compare(data->pagesToken) == 0){
        data->setPages(valueToken);
    }   
}

/******************************************************************
 * setTechnicalReportData
 *
 * Similar to the above but specific to the TechnicalReport type.
 *****************************************************************/
void BibliographyParser::setTechnicalReportData(TechnicalReportData * data, 
                                                string token, string valueToken){
    if(token.compare(data->organizationToken) == 0){
        data->setOrganization(valueToken);
    }  
    else if(token.compare(data->numberToken) == 0){
        data->setNumber(valueToken);
    }  
    else if(token.compare(data->placeToken) == 0){
        data->setPlace(valueToken);
    }  
    else if(token.compare(data->publisherToken) == 0){
        data->setPublisher(valueToken);
    }  

}

char * BibliographyParser::readInputFileLine(){
  char * strbuf = new char[sizeof(char) * MAX_LINE];
  char chbuf[1];
  int index = 0;
  int err;

  err = read(inputFile, chbuf, 1);
  while(chbuf[0] != '\n'){
    if(err == 0){
      return NULL;
    }
    
    strbuf[index] = chbuf[0];
    index++;
    err = read(inputFile, chbuf, 1);
  }

  strbuf[index] = '\n';

  if(err == 0){
    return NULL;
  }  

  return strbuf;
}

char * BibliographyParser::getSubStringKey(int endOffset, char * data){
  char * key = new char[sizeof(char) * MAX_KEY];
  int index = 0,
      dataIndex = endOffset + 1;
  
  while(data[dataIndex] != '}'){
    key[index] = data[dataIndex];
    index++;
    dataIndex++;
  }
  key[index++] = '\0';
  
  index = 0;
  dataIndex++;
  while(data[dataIndex] != '\n'){
    data[index] = data[dataIndex];
    index++;
    dataIndex++;
  }

  data[index] = '\n';
  data[index++] = '\0';

  return key;
}

void BibliographyParser::addValidKey(char * key, int index){
  keys[index] = key;
}
