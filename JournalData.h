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
	char * journal;
	char * volume;
	char * number;
	char * pages;

  const char * journalToken;
  const char * volumeToken;
  const char * numberToken;
  const char * pagesToken;

	void setJournal(char *);
	void setNumber(char *);
	void setPages(char *);
	void setVolume(char *);
  void setItem(char *);
public:
	JournalData(void);
	~JournalData(void);
	char * getJournal(void);
	char * getNumber(void);
	char * getPages(void);
	char * getVolume(void);
};

