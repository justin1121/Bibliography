#pragma once
#include "resourcedata.h"
class ConferenceData : public ResourceData{
private:
	char * proceedings;
	char * placeOfConference;
	char * dateOfConference;
	char * city;
	char * publisher;
	char * pages;
public:
	ConferenceData(void);
	~ConferenceData(void);
	char * getProceedings();
	char * getPlace();
	char * getDate();
	char * getCity();
	char * getPublisher();
	char * getPages();
	void setProceedings(char *);
	void setPlace(char *);
	void setDate(char *);
	void setCity(char *);
	void setPublisher(char *);
	void setPages(char *);
};

