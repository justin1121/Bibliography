/*
 *	Name: 			Logan Pitman
 *	Date: 			10/26/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	Formats ResourceData objects into IEEE format
 */

#pragma once
#include "StyleFormatter.h"

class IEEEFormatter : public StyleFormatter{
private:
	OutputCitation * formatBook(BookData * data);
	OutputCitation * formatConference(ConferenceData * data);
	OutputCitation * formatJournal(JournalData * data);
	OutputCitation * formatTechnicalReport(TechnicalReportData * data);
public:
	IEEEFormatter(void);
	~IEEEFormatter(void);

	OutputCitation * format(ResourceData * data);
};

