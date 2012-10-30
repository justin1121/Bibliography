/*
 *	Name: 			Logan Pitman
 *	Date: 			10/29/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	Formats ResourceData objects into APA format
 */

#pragma once
#include "StyleFormatter.h"

class APAFormatter : public StyleFormatter{
private:
	OutputCitation * formatBook(ResourceData data);
	OutputCitation * formatConference(ResourceData data);
	OutputCitation * formatJournal(ResourceData data);
	OutputCitation * formatTechnicalReport(ResourceData data);
public:
	APAFormatter(void);
	~APAFormatter(void);

	OutputCitation * format(ResourceData data);
};

