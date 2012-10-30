#include <cstdio>
#include "BookData.h"

BookData::BookData(void){
  placeToken     = "Place";
  publisherToken = "Publisher";
}

BookData::~BookData(void){
}

string BookData::getPlace(){
	return place;
}

string BookData::getPublisher(){
	return publisher;
}

void BookData::setPlace(string place){
	BookData::place = place;
}

void BookData::setPublisher(string publisher){
	BookData::publisher = publisher;
}

