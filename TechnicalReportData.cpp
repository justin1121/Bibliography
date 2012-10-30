/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * Contains the implemention for all of the getters and setters for
 * the TechnicalReportData, pretty straight-forward.
 ******************************************************************/
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

