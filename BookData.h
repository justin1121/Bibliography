#pragma once
#include "resourcedata.h"
class BookData : public ResourceData{
private:
	char * place;
	char * publisher;
public:
	BookData(void);
	~BookData(void);
	char * getPlace();
	char * getPublisher();
	void setPlace(char *);
	void setPublisher(char *);
};

