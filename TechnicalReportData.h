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
	string organization;
	string number;
	string place;
	string publisher;
public:
	TechnicalReportData(void);
	~TechnicalReportData(void);

    const char * organizationToken;
    const char * numberToken;
    const char * placeToken;
    const char * publisherToken;

	string getOrganization(void);
	string getNumber(void);
	string getPlace(void);
	string getPublisher(void);
    void setOrganization(string);
    void setNumber(string);
    void setPlace(string);
    void setPublisher(string);
};

