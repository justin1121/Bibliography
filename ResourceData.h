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
  void setItem(char *);
public:
  ResourceData();

	char * getKey(void);
	char * getAuthor(void);
	char * getDate(void);
	char * getTitle(void);
	int getType(void);
  void setData(int, char *);
};

