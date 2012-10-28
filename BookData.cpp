#include "BookData.h"

BookData::BookData(void){
  placeToken     = "Place";
  publisherToken = "Publisher";
}

BookData::~BookData(void){
}

char * BookData::getPlace(){
	return place;
}

char * BookData::getPublisher(){
	return publisher;
}

void BookData::setPlace(char * place){
	BookData::place = place;
}

void BookData::setPublisher(char * publisher){
	BookData::publisher = publisher;
}

void BookData::setItem(char * data){
  char * token;

  strtok(data, "=");

  while((token = strtok(NULL, "=")) != NULL){
    if((strcmp(token, placeToken) == 0)){
      setPlace(strtok(NULL, "="));
    }
    else if((strcmp(token, publisherToken) == 0)){
      setPublisher(strtok(NULL, "="));
    }
  }
}
