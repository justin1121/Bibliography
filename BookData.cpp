#include "BookData.h"


BookData::BookData(void){
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
