/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * Contains the implemention for all of the getters and setters for
 * the JournalData, pretty straight-forward.
 ******************************************************************/
#include "JournalData.h"

JournalData::JournalData(void){
  journalToken = "Journal";
  volumeToken  = "Volume";
  numberToken  = "Number";
  pagesToken   = "Pages";
}

JournalData::~JournalData(void){
}

string JournalData::getJournal(){
	return journal;
}
string JournalData::getVolume(){
	return volume;
}
string JournalData::getNumber(){
	return number;
}
string JournalData::getPages(){
	return pages;
}
void JournalData::setJournal(string journal){
	JournalData::journal = journal;
}
void JournalData::setVolume(string volume){
	JournalData::volume = volume;
}
void JournalData::setNumber(string number){
	JournalData::number = number;
}
void JournalData::setPages(string pages){
	JournalData::pages = pages;
}

