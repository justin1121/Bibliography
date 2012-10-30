/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * Contains the implemention for all of the getters and setters for
 * the BookData, pretty straight-forward.
 ******************************************************************/
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

