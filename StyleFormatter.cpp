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

OutputCitation * StyleFormatter::formatWebsite(WebsiteData * data){
	return NULL;
}

list getInTextList(){
	return N;
}

void addInText(string citation){
	inTextList.push_back(citation);
}
