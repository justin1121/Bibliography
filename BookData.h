#pragma once
#include "ResourceData.h"

class BookData : public ResourceData{
private:
	char * place;
	char * publisher;

  const char * placeToken;
  const char * publisherToken;

	void setPlace(char *);
	void setPublisher(char *);
  void setItem(char *);
public:
	BookData(void);
	~BookData(void);
	char * getPlace();
	char * getPublisher();
};

