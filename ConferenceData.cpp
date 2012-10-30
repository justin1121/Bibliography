/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * Contains the implemention for all of the getters and setters for
 * the ConferenceData, pretty straight-forward.
 ******************************************************************/
#include "ConferenceData.h"

ConferenceData::ConferenceData(void){
  proceedingsToken       = "Proceedings";
  placeOfConferenceToken = "Place-of-Conference";
  dateOfConferenceToken  = "Date-of-Conference";
  cityToken              = "City";
  publisherToken         = "Publisher";
  pagesToken             = "Pages";
}

ConferenceData::~ConferenceData(void){
}

string ConferenceData::getProceedings(){
	return proceedings;
}

string ConferenceData::getPlaceOfConference(){
	return placeOfConference;
}

string ConferenceData::getDateOfConference(){
	return dateOfConference;
}

string ConferenceData::getCity(){
	return city;
}

string ConferenceData::getPublisher(){
	return publisher;
}

string ConferenceData::getPages(){
	return pages;
}

void ConferenceData::setProceedings(string proceedings){
	ConferenceData::proceedings = proceedings;
}

void ConferenceData::setPlaceOfConference(string place){
	ConferenceData::placeOfConference = place;
}

void ConferenceData::setDateOfConference(string date){
	ConferenceData::dateOfConference = date;
}

void ConferenceData::setCity(string city){
	ConferenceData::city = city;
}

void ConferenceData::setPublisher(string publisher){
	ConferenceData::publisher = publisher;
}

void ConferenceData::setPages(string pages){
	ConferenceData::pages = pages;
}

