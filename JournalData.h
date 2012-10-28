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

