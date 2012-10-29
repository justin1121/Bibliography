/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * This is the base class from where each type of data extends.
 * It also provides an implementation of setData, which sets the
 * data and a virtual function setItem which should be exteneded by
 * the subclasses.
 ******************************************************************/
#pragma once
#include <string>

using namespace std;

class ResourceData{
private:
	string key;
	string author;
	string date;
	string title;
	int type;
public:
	ResourceData();

	const char * keyToken;
	const char * authorToken; 
	const char * dateToken;
	const char * titleToken;

	string getKey(void);
	string getAuthor(void);
	string getDate(void);
	string getTitle(void);
	int getType(void);
	void setKey(string);
	void setAuthor(string);
	void setDate(string);
	void setTitle(string);
	void setType(int);
};

