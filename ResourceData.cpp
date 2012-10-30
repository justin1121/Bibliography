#include <iostream>
#include "ResourceData.h"

using namespace std;
ResourceData::ResourceData(){
  keyToken    = "Key";
  authorToken = "Author";
  dateToken   = "Date";
  titleToken  = "Title";
}

string ResourceData::getKey(){
	return key;
}

string ResourceData::getAuthor(){
	return author;
}

string ResourceData::getDate(){
	return date;
}

string ResourceData::getTitle(){
	return title;
}

int ResourceData::getType(){
	return type;
}

void ResourceData::setKey(string key){
	ResourceData::key = key;
}

void ResourceData::setAuthor(string author){
	ResourceData::author = author;
}

void ResourceData::setDate(string date){
	ResourceData::date = date;
}

void ResourceData::setTitle(string title){
	ResourceData::title = title;	
}

void ResourceData::setType(int type){
	ResourceData::type = type;
}

