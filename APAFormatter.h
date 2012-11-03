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
/*	Each function in this object takes in a pointer to a piece of resource
 *	data and returns a pointer to the APA Output Citation 	
*/

private:
	OutputCitation * formatBook(BookData * data);
	OutputCitation * formatConference(ConferenceData * data);
	OutputCitation * formatJournal(JournalData * data);
	OutputCitation * formatTechnicalReport(TechnicalReportData * data);
	OutputCitation * formatWebsite(WebsiteData * data);

public:
	APAFormatter(void);
	~APAFormatter(void);

	OutputCitation * format(ResourceData * data);
};

