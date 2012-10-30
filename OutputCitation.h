#pragma once
#include <string>
using namespace std;

class OutputCitation
{
private:
	string citation;
public:
	OutputCitation(void);
	~OutputCitation(void);
	string getCitation(void);
	void setCitation(string);
};

