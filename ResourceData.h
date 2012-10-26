#pragma once

class ResourceData{
private:
	char * key;
	char * author;
	char * date;
	char * title;
	char * type;
public:
	char * getKey(void);
	char * getAuthor(void);
	char * getDate(void);
	char * getTitle(void);
	char * getType(void);
	void setKey(char *);
	void setAuthor(char *);
	void setDate(char *);
	void setTitle(char *);
	void setType(char *);
};

