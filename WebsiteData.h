/******************************************************************
 * Name: Logan Pitman
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * This class extends the ResourceData base class. It adds the 
 * variables that are specific to it. 
 * They are: Site 
 *           URL
 * This class also provides the correct setItem implementation to
 * work with these new variables. Plus all the getters and setters.
 ******************************************************************/
#pragma once
#include "ResourceData.h"

class WebsiteData : public ResourceData{
private:
	string site;
	string url;

public:
	WebsiteData(void);
	~WebsiteData(void);

	const char * siteToken;
	const char * urlToken;

	string getSite(void);
	string getURL(void);

	void setSite(string);
	void setURL(string);
};

