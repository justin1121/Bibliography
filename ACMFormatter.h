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
/*	Each function in this object takes in a pointer to a piece of resource
 *	data and returns a pointer to the ACM Output Citation 	
*/

private:
	OutputCitation * formatBook(BookData * data);
	OutputCitation * formatJournal(JournalData * data);
	OutputCitation * formatConference(ConferenceData * data);
	OutputCitation * formatTechnicalReport(TechnicalReportData * data);
	OutputCitation * formatWebsite(WebsiteData * data);

public:
	ACMFormatter(void);
	~ACMFormatter(void);

	OutputCitation * format(ResourceData * data);
};

