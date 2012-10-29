#include "TechnicalReportData.h"

TechnicalReportData::TechnicalReportData(void){
  organizationToken = "Organization";
  numberToken       = "Number";
  placeToken        = "Place";
  publisherToken    = "Publisher";
}

TechnicalReportData::~TechnicalReportData(void){
}

string TechnicalReportData::getOrganization(){
	return organization;
}
string TechnicalReportData::getNumber(){
	return number;
}
string TechnicalReportData::getPlace(){
	return place;
}
string TechnicalReportData::getPublisher(){
	return publisher;
}
void TechnicalReportData::setOrganization(string organization){
	TechnicalReportData::organization = organization;
}
void TechnicalReportData::setNumber(string number){
	TechnicalReportData::number = number;
}
void TechnicalReportData::setPlace(string place){
	TechnicalReportData::place = place;
}
void TechnicalReportData::setPublisher(string publisher){
	TechnicalReportData::publisher = publisher;
}