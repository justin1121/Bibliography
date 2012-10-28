#include "TechnicalReportData.h"

TechnicalReportData::TechnicalReportData(void){
  organizationToken = "Organization";
  numberToken       = "Number";
  placeToken        = "Place";
  publisherToken    = "Publisher";
}

TechnicalReportData::~TechnicalReportData(void){
}

char * TechnicalReportData::getOrganization(){
	return organization;
}
char * TechnicalReportData::getNumber(){
	return number;
}
char * TechnicalReportData::getPlace(){
	return place;
}
char * TechnicalReportData::getPublisher(){
	return publisher;
}
void TechnicalReportData::setOrganization(char * organization){
	TechnicalReportData::organization = organization;
}
void TechnicalReportData::setNumber(char * number){
	TechnicalReportData::number = number;
}
void TechnicalReportData::setPlace(char * place){
	TechnicalReportData::place = place;
}
void TechnicalReportData::setPublisher(char * publisher){
	TechnicalReportData::publisher = publisher;
}

void TechnicalReportData::setItem(char * data){
  char * token;

  strtok(data, "=");

  while((token = strtok(NULL, "=")) != NULL){
    if((strcmp(token, organizationToken) == 0)){
      setOrganization(strtok(NULL, "="));
    }
    else if((strcmp(token, numberToken) == 0)){
      setNumber(strtok(NULL, "="));
    }
    else if((strcmp(token, placeToken) == 0)){
      setPlace(strtok(NULL, "="));
    }
    else if((strcmp(token, publisherToken) == 0)){
      setPublisher(strtok(NULL, "="));
    }
  }
}
