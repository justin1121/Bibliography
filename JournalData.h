#pragma once
#include "resourcedata.h"

class JournalData : public ResourceData{
private:
	char * journal;
	char * volume;
	char * number;
	char * pages;
public:
	JournalData(void);
	~JournalData(void);
	char * getJournal(void);
	char * getNumber(void);
	char * getPages(void);
	char * getVolume(void);
	void setJournal(char *);
	void setNumber(char *);
	void setPages(char *);
	void setVolume(char *);
};

