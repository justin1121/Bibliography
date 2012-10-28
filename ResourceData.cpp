#include "ResourceData.h"

ResourceData::ResourceData(){
  keyToken    = "Key";
  authorToken = "Author";
  dateToken   = "Date";
  titleToken  = "Title";
}

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

int ResourceData::getType(){
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

void ResourceData::setType(int type){
	ResourceData::type = type;
}

void ResourceData::setBaseItem(char * data){
  char * token;

  strtok(data, "=");

  while((token = strtok(NULL, "=")) != NULL){
    if((strcmp(token, keyToken) == 0)){
      setKey(strtok(NULL, "="));
    }
    else if((strcmp(token, authorToken) == 0)){
      setAuthor(strtok(NULL, "="));
    }
    else if((strcmp(token, dateToken) == 0)){
      setDate(strtok(NULL, "="));
    }
    else if((strcmp(token, titleToken) == 0)){
      setTitle(strtok(NULL, "="));
    }
  }
}

void ResourceData::setItem(char * data){
  return;
}

void ResourceData::setData(int type, char * data){
  char * token;

  setType(type);

  strtok(data, ";"); 

  while((token = strtok(NULL, ";")) != NULL){
	setBaseItem(token); 
  }

  strtok(data, ";");

  while((token = strtok(NULL, ";")) != NULL){
	setItem(token);
  }
}
