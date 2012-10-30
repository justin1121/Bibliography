/*
 *	Name: 			Logan Pitman
 *	Date: 			10/29/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	Formats ResourceData objects into ACM format
 */

#pragma once
#include "StyleFormatter.h"

class ACMFormatter : public StyleFormatter{
private:
	OutputCitation * formatBook(ResourceData data);
	OutputCitation * formatJournal(ResourceData data);
	OutputCitation * formatConference(ResourceData data);
	OutputCitation * formatTechnicalReport(ResourceData data);
public:
	ACMFormatter(void);
	~ACMFormatter(void);

	OutputCitation * format(ResourceData data);
};

