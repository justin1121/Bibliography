#pragma once
#include "ResourceData.h"

class TechnicalReportData : public ResourceData{
private:
	char * organization;
	char * number;
	char * place;
	char * publisher;

  const char * organizationToken;
  const char * numberToken;
  const char * placeToken;
  const char * publisherToken;
  
	void setOrganization(char *);
	void setNumber(char *);
	void setPlace(char *);
	void setPublisher(char *);
  void setItem(char *);
public:
	TechnicalReportData(void);
	~TechnicalReportData(void);
	char * getOrganization(void);
	char * getNumber(void);
	char * getPlace(void);
	char * getPublisher(void);
};

