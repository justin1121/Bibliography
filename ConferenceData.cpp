#include "ConferenceData.h"

ConferenceData::ConferenceData(void){
}

ConferenceData::~ConferenceData(void){
}

char * ConferenceData::getProceedings(){
	return proceedings;
}
char * ConferenceData::getPlace(){
	return placeOfConference;
}
char * ConferenceData::getDate(){
	return dateOfConference;
}
char * ConferenceData::getCity(){
	return city;
}
char * ConferenceData::getPublisher(){
	return publisher;
}
char * ConferenceData::getPages(){
	return pages;
}
void ConferenceData::setProceedings(char * proceedings){
	ConferenceData::proceedings = proceedings;
}
void ConferenceData::setPlace(char * place){
	ConferenceData::placeOfConference = place;
}
void ConferenceData::setDate(char * date){
	ConferenceData::dateOfConference = date;
}
void ConferenceData::setCity(char * city){
	ConferenceData::city = city;
}
void ConferenceData::setPublisher(char * publisher){
	ConferenceData::publisher = publisher;
}
void ConferenceData::setPages(char * pages){
	ConferenceData::pages = pages;
}