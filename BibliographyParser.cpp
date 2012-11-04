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
#include "WebsiteData.h"

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
  websiteToken                      = "@website{";
	endOfItem                         = "}";
	endOfFile                         = "};";
	startOfInputToken                 = "/{";
  keys                              = new string[MAX_NUM_REF];
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
				}else if(idenToken.compare(websiteToken)==0){
          itemIdentifier = 5;
          d = new WebsiteData();
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
          valueString = valueString.substr(0, valueString.size()-1); 
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
          case 5:
            setWebsiteData((WebsiteData *) d, idenToken, valueString);
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


/****************************************************************
 * parseInputFile 
 *
 * Parses the input file for all of the keys and the spots in the
 * text that will be needed for in text citation. 
 *
 * For some reason I used regular expressions. Turned out it was 
 * a bad idea, but I crossed the point of no return....before
 * I realised.
 ***************************************************************/
void BibliographyParser::parseInputFile(string *  file_string){
  // regular expression, search for \cite
  char regex[32] = "\\\\cite";

  char errbuf[128];
  regex_t p; 
  int err;

  // compile the regex and spit out an error if there is any
  // shouldn't be any though
  if(err = regcomp(&p, regex, REG_ICASE)){
    regerror(err, &p, errbuf, 128);
    cout << "Regex Error: "<< errbuf << "\n";
    exit(1);
  } 

  regmatch_t q[1];
  char * chLine;
  int index = 0;
  bool check;

  // read in a line from the input file.
  while((chLine = readInputFileLine()) != NULL){
    check = false;
    // execute the search until there is no more found
    // on the line
    while((err = regexec(&p, chLine, 1, q, 0)) == 0){
      check = true;
      // add a valid key to a list of keys by gettings the substring
      addValidKey(getSubStringKey(q[0].rm_eo, chLine, file_string), 
                                              index);
      index++;
    }
    // if not check then there shouldn't \cite markers on the line
    // so just add the whole thing to the file_string
    if(!check){
      *file_string += chLine;
    }
    // if there is some then add a newline
    else{
      *file_string += "\n";
    }
    
    //delete the line and then get another!
    delete[] chLine;
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

/******************************************************************
 * setWebsiteData
 *
 * Similar to the above but specific to the Website type.
 *****************************************************************/
void BibliographyParser::setWebsiteData(WebsiteData * data, 
                                        string token, string valueToken){
    if(token.compare(data->siteToken) == 0){
        data->setSite(valueToken);
    }  
    else if(token.compare(data->urlToken) == 0){
        data->setURL(valueToken);
    }  
}

/******************************************************************
 * readInputFileLine 
 *
 * Reads a line of text from the input file one at a time. Returns
 * null when it reaches the end of the file and a line every
 * other time.
 *****************************************************************/
char * BibliographyParser::readInputFileLine(){
  char * strbuf = new char[sizeof(char) * MAX_SZ_LINE];
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
  strbuf[index + 1] = '\0';

  if(err == 0){

    return NULL;
  }  

  return strbuf;
}

/******************************************************************
 * getSubStringKey 
 *
 * This is a pretty weird function and does more than the name of
 * it. Some smelly code...
 *
 * First is search through the list to get the key and then it
 * calls a format method to format the text body for in text 
 * citations. Then, it rights over the data string to get rid of
 * the text that was already searched.
 *****************************************************************/
char * BibliographyParser::getSubStringKey(int endOffset, char * data,
                                           string * file_string){
  char * key = new char[sizeof(char) * MAX_SZ_KEY];
  int index = 0,
      dataIndex = endOffset + 1;

  while(data[dataIndex] != '}'){
    key[index] = data[dataIndex];
    index++;
    dataIndex++;
  }
  key[index + 1] = '\0';
  
  formatTextBody(file_string, data, endOffset - 5, dataIndex);

  dataIndex++;

  index = 0;
  while(dataIndex < strlen(data)){
    data[index] = data[dataIndex];
    dataIndex++;
    index++;
  }

  data[index] = '\n';
  data[index + 1] = '\0';

  return key;
}

/******************************************************************
 * addValidKey 
 *
 * Takes in a key and an index and adds the key to that index in
 * the list of keys.
 *****************************************************************/
void BibliographyParser::addValidKey(char * key, int index){
  keys[index] = key;
}
/******************************************************************
 * formatTextBody
 *
 * Takes in the file string and inserts the data with identifiers
 * for where the in text citations will go in the future!.
 *****************************************************************/
void BibliographyParser::formatTextBody(string * file_string, 
                                        char * line,
                                        int startToken, 
                                        int endToken){
  string temp = line;
  
  // if it is the end of the line then make sure
  // that it grabs the character at the end.
  if(temp[endToken + 3] == '\n'){
    temp = temp.substr(0, endToken + 2);
  }
  else{
    temp = temp.substr(0, endToken + 1);
  }

  // erase the citation from the line
  temp.erase(startToken, endToken - startToken + 1);

  // place in the identifying character, in this case 
  // it is '~'
  temp.insert(startToken, "~");

  *file_string += temp;
}
