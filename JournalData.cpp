#include "JournalData.h"

JournalData::JournalData(void){
  journalToken = "Journal";
  volumeToken  = "Volume";
  numberToken  = "Number";
  pagesToken   = "Pages";
}

JournalData::~JournalData(void){
}

char * JournalData::getJournal(){
	return journal;
}
char * JournalData::getVolume(){
	return volume;
}
char * JournalData::getNumber(){
	return number;
}
char * JournalData::getPages(){
	return pages;
}
void JournalData::setJournal(char * journal){
	JournalData::journal = journal;
}
void JournalData::setVolume(char * volume){
	JournalData::volume = volume;
}
void JournalData::setNumber(char * number){
	JournalData::number = number;
}
void JournalData::setPages(char * pages){
	JournalData::pages = pages;
}

void JournalData::setItem(char * data){
  char * token;

  strtok(data, "=");

  while((token = strtok(NULL, "=")) != NULL){
    if((strcmp(token, journalToken) == 0)){
      setJournal(strtok(NULL, "="));
    }
    else if((strcmp(token, volumeToken) == 0)){
      setVolume(strtok(NULL, "="));
    }
    else if((strcmp(token, numberToken) == 0)){
      setNumber(strtok(NULL, "="));
    }
    else if((strcmp(token, pagesToken) == 0)){
      setPages(strtok(NULL, "="));
    }
  }
}
