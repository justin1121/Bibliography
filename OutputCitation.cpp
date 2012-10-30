/*
 *	Name: 			Logan Pitman
 *	Date: 			10/27/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *		Simple object to hold citations	
 */

#include "OutputCitation.h"

OutputCitation::OutputCitation(void){
	
}

OutputCitation::~OutputCitation(void){
}

string OutputCitation::getCitation(void){
	return citation;
}

void OutputCitation::setCitation(string citation){
	OutputCitation::citation = citation;
}