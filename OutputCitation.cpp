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