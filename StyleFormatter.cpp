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

// This function will be used to switch the names of authors around 
// for APA and ACM format
string reverseNames(string author){
	list<string> 	nameList, revList;
	string 			result = "";
	int 			beg, end, i;
	beg = end = 0;
	
	// This loop adds all the names of the authors to a list
	for(i = 0; i < author.length(); i++){
		if(author[i] == 'a' && author[i+1] == 'n'){
			i = i+4;
			beg = i;
		}
		if(author[i] == ','){
			end = i-1;
			nameList.push_back(author.substr(beg, end));
			beg = i+2;
		}
	}
	
	// now, need to take each name and put the initials at the back
	for(list<string>::iterator iter = nameList.begin(); iter != nameList.end(); iter++){
		string name = *iter;
		for(i = 0; i < name.size(); i++){
			if(name[i] == ' ');
			string revName 	= name.substr(i+1, name.length()-1);
			revName 		+= name.substr(0, i);
			revList.push_back(revName);
		}
	}
	
	// now, create the final list of authors
	if(revList.size() > 2){
		for(i = 0; i < revList.size()-1; i++){
			string name = revList.front();
			revList.pop_front();
			result += " "; 
			result += name;
			result += ",";
		}
		result += " and ";
		result += revList.front();
	}
	
	else if(revList.size() == 2){
		result += revList.front();
		result += " and ";
		result += revList.back();
	}
	
	else{
		result = revList.front();
	}
	
	return result;
}
