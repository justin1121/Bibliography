#include "ConferenceData.h"

ConferenceData::ConferenceData(void){
  proceedingsToken = "Proceedings";
  placeToken       = "Place-of-Conference";
  dateToken        = "Date-of-Conference";
  cityToken        = "City";
  publisherToken   = "Publisher";
  pagesToken       = "Pages";
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

void ConferenceData::setItem(char * data){
  char * token;

  strtok(data, "=");

  while((token = strtok(NULL, "=")) != NULL){
    if((strcmp(token, proceedingsToken) == 0)){
      setProceedings(strtok(NULL, "="));
    }
    else if((strcmp(token, placeToken) == 0)){
      setPlace(strtok(NULL, "="));
    }
    else if((strcmp(token, dateToken) == 0)){
      setDate(strtok(NULL, "="));
    }
    else if((strcmp(token, cityToken) == 0)){
      setCity(strtok(NULL, "="));
    }
    else if((strcmp(token, publisherToken) == 0)){
      setPublisher(strtok(NULL, "="));
    }
    else if((strcmp(token, pagesToken) == 0)){
      setPages(strtok(NULL, "="));
    }
  }
}
