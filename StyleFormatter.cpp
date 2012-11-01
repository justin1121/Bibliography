/*
 *	Name: 			Logan Pitman
 *	Date: 			10/26/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *		Base class for the different types of formatters. 
 */

#include <cstddef>
#include <iostream>
#include "StyleFormatter.h"

using namespace std;
StyleFormatter::StyleFormatter(){
}

StyleFormatter::~StyleFormatter(){
}

OutputCitation * StyleFormatter::format(ResourceData * data){
  cout << "HELLO!\n";
	return NULL; 
}

OutputCitation * StyleFormatter::formatBook(BookData * data){
	return NULL; 
}

OutputCitation * StyleFormatter::formatConference(ConferenceData * data){
	return NULL;
}

OutputCitation * StyleFormatter::formatJournal(JournalData * data){
	return NULL;
}

OutputCitation * StyleFormatter::formatTechnicalReport(TechnicalReportData * data){
	return NULL;
}

string reverseNames(string author){
	string result = "";
	int lastName = 0;
	
	int i;
	for(i = author.length(); i > 0; i--){
		if(author[i-1] = ' '){
			lastName = i+1;
		}
	}
	
	result += author.substr(lastname, author.length());
	re
	
	return result;
}
