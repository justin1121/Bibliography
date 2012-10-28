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

}
