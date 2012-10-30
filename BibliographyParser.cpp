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
					/* Set the data and add it to the citation list */
          d->setType(itemIdentifier);

        	addCitationList(*d);
          delete d;
					/*reset item's identifier and information string*/
					itemIdentifier = 0;
				}else{

          sStream >> tempToken;
          sStream >> tempToken;
          while(tempToken.compare(";") != 0){
            valueString = valueString + tempToken + " "; 
            sStream >> tempToken;
          }
          setBaseResourceData(d, idenToken, valueString);
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


CitationList BibliographyParser::getCitationList(void){
	return list;
}


void BibliographyParser::addCitationList(ResourceData data){
	list.addCitation(data);
}


void BibliographyParser::parseInputFile(void){
  string line;
  int err;

  char * regex = "\\\\cite{.*}";
  char * chLine = new char[sizeof(char) * 128];
  regex_t * p = new regex_t[sizeof(regex_t)];

  if(err = regcomp(p, regex, REG_ICASE)){
    printf("%s\n", strerror(err));
    exit(1);
  } 

  regmatch_t q[10];

  while((chLine = readInputFileLine()) != NULL){
    printf("%s", chLine);
    regexec(p, chLine, 10, q, 0);
      
    printf("Offset Start 1: %d\n"
           "Offset End   1: %d\n", q[0].rm_so, q[0].rm_eo); 
  }
}

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

void BibliographyParser::setBookData(BookData * data, string token, string valueToken){
    if(token.compare(data->placeToken) == 0){
        data->setPlace(valueToken);
    }  
    else if(token.compare(data->publisherToken) == 0){
        data->setPublisher(valueToken);
    }  

}

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
  char strbuf[128];
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

  if(err == 0 || chbuf[0] == '\n'){
    return NULL;
  }
  return strbuf;
}
