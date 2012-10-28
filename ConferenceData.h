#pragma once
#include "ResourceData.h"

class ConferenceData : public ResourceData{
private:
	char * proceedings;
	char * placeOfConference;
	char * dateOfConference;
	char * city;
	char * publisher;
	char * pages;

  const char * proceedingsToken;
  const char * placeToken;
  const char * dateToken;
  const char * cityToken;
  const char * publisherToken;
  const char * pagesToken;
  
	void setProceedings(char *);
	void setPlace(char *);
	void setDate(char *);
	void setCity(char *);
	void setPublisher(char *);
	void setPages(char *);
  void setItem(char *);
public:
	ConferenceData(void);
	~ConferenceData(void);
	char * getProceedings();
	char * getPlace();
	char * getDate();
	char * getCity();
	char * getPublisher();
	char * getPages();
};

