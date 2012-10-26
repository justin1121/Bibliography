#include "JournalData.h"

JournalData::JournalData(void){
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