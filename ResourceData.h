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
#include <cstring>
#include <cstddef>

class ResourceData{
private:
	char * key;
	char * author;
	char * date;
	char * title;
	int type;
protected:
	const char * keyToken;
	const char * authorToken; 
	const char * dateToken;
	const char * titleToken;

	void setKey(char *);
	void setAuthor(char *);
	void setDate(char *);
	void setTitle(char *);
	void setType(int);
	void setBaseItem(char *);
	virtual void setItem(char *);
public:
	ResourceData();

	char * getKey(void);
	char * getAuthor(void);
	char * getDate(void);
	char * getTitle(void);
	int getType(void);
	void setData(int, char *);
	virtual void print(void);
};

