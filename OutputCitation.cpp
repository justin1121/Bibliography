#include "OutputCitation.h"

OutputCitation::OutputCitation(void){
}

OutputCitation::~OutputCitation(void){
}

char * OutputCitation::getCitation(void){
	return citation;
}

void OutputCitation::setCitation(char * citation){
	OutputCitation::citation = citation;
}