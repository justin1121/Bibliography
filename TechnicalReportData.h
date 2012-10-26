#pragma once
#include "resourcedata.h"
class TechnicalReportData : public ResourceData{
private:
	char * organization;
	char * number;
	char * place;
	char * publisher;
public:
	TechnicalReportData(void);
	~TechnicalReportData(void);
	char * getOrganization(void);
	char * getNumber(void);
	char * getPlace(void);
	char * getPublisher(void);
	void setOrganization(char *);
	void setNumber(char *);
	void setPlace(char *);
	void setPublisher(char *);
};

