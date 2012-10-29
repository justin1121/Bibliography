/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * This class extends the ResourceData base class. It adds the 
 * variables that are specific to it. 
 * They are: proceedings 
 *           placeOfConference
 *           dateOfConference
 *           city
 *           publisher
 *           pages
 * This class also provides the correct setItem implementation to
 * work with these new variables. Plus all the getters and setters.
 ******************************************************************/
#pragma once
#include "ResourceData.h"

class ConferenceData : public ResourceData{
private:
	string proceedings;
	string placeOfConference;
	string dateOfConference;
	string city;
	string publisher;
	string pages;
public:
	ConferenceData(void);
	~ConferenceData(void);

	const char * proceedingsToken;
	const char * placeOfConferenceToken;
	const char * dateOfConferenceToken;
	const char * cityToken;
	const char * publisherToken;
	const char * pagesToken;

	string getProceedings();
	string getPlaceOfConference();
	string getDateOfConference();
	string getCity();
	string getPublisher();
	string getPages();
	void setProceedings(string);
	void setPlaceOfConference(string);
	void setDateOfConference(string);
	void setCity(string);
	void setPublisher(string);
	void setPages(string);
};

