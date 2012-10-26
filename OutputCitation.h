#pragma once
class OutputCitation
{
private:
	char * citation;
public:
	OutputCitation(void);
	~OutputCitation(void);
	char * getCitation(void);
	void setCitation(char *);
};

