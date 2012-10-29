/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * This class extends the ResourceData base class. It adds the 
 * variables that are specific to it. 
 * They are: place 
 *           publisher 
 * This class also provides the correct setItem implementation to
 * work with these new variables. Plus all the getters and setters.
 ******************************************************************/
#pragma once
#include "ResourceData.h"

class BookData : public ResourceData{
private:
	string place;
	string publisher;
public:
	BookData(void);
	~BookData(void);

	const char * placeToken;
	const char * publisherToken;

	string getPlace();
	string getPublisher();
    void setPlace(string);
    void setPublisher(string);
};

