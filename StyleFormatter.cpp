/*
 *	Name: 			Logan Pitman
 *	Date: 			10/26/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *		Base class for the different types of formatters. 
 */

#include "StyleFormatter.h"

StyleFormatter::StyleFormatter(){
}

StyleFormatter::~StyleFormatter(){
}

OutputCitation * StyleFormatter::format(ResourceData * data){
	return 0; 
}

OutputCitation * StyleFormatter::formatBook(ResourceData * data){
	return 0; 
}

OutputCitation * StyleFormatter::formatConference(ResourceData * data){
	return 0;
}

OutputCitation * StyleFormatter::formatJournal(ResourceData * data){
	return 0;
}

OutputCitation * StyleFormatter::formatTechnicalReport(ResourceData * data){
	return 0;
}
