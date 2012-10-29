/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * This class extends the ResourceData base class. It adds the 
 * variables that are specific to it. 
 * They are: organization
 *           number
 *           place
 *           publisher
 * This class also provides the correct setItem implementation to
 * work with these new variables. Plus all the getters and setters.
 ******************************************************************/
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

