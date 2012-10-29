/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * This class extends the ResourceData base class. It adds the 
 * variables that are specific to it. 
 * They are: journal 
 *           volume
 *           number
 *           pages
 * This class also provides the correct setItem implementation to
 * work with these new variables. Plus all the getters and setters.
 ******************************************************************/
#pragma once
#include "ResourceData.h"

class JournalData : public ResourceData{
private:
	string journal;
	string volume;
	string number;
	string pages;
public:
	JournalData(void);
	~JournalData(void);

	const char * journalToken;
	const char * volumeToken;
	const char * numberToken;
	const char * pagesToken;

	string getJournal(void);
	string getNumber(void);
	string getPages(void);
	string getVolume(void);
	void setJournal(string);
	void setNumber(string);
	void setPages(string);
	void setVolume(string);
};

