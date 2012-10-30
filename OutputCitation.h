/*
 *	Name: 			Logan Pitman
 *	Date: 			10/27/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *		Simple object to hold citations. 	
 */
 
#pragma once
#include <string>
using namespace std;

class OutputCitation
{
// Holds the formatted reference with a string

private:
	string citation;
public:
	OutputCitation(void);
	~OutputCitation(void);
	string getCitation(void);
	void setCitation(string);
};

