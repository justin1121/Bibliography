#include "ResourceData.h"

char * ResourceData::getKey(){
	return key;
}

char * ResourceData::getAuthor(){
	return author;
}

char * ResourceData::getDate(){
	return date;
}

char * ResourceData::getTitle(){
	return title;
}

char * ResourceData::getType(){
	return type;
}

void ResourceData::setKey(char * key){
	ResourceData::key = key;
}
void ResourceData::setAuthor(char * author){
	ResourceData::author = author;
}
void ResourceData::setDate(char * date){
	ResourceData::date = date;
}
void ResourceData::setTitle(char * title){
	ResourceData::title = title;	
}
void ResourceData::setType(char * type){
	ResourceData::type = type;
}
