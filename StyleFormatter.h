/*
 *	Name: 			Logan Pitman
 *	Date: 			10/26/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	This is the base class of all of the different types of formatters
 *	
 */

#pragma once
#include "ResourceData.h"
#include "BookData.h"
#include "ConferenceData.h"
#include "JournalData.h"
#include "TechnicalReportData.h"
#include "WebsiteData.h"
#include "OutputCitation.h"
#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
using namespace std;

class StyleFormatter{
/*	This class's derived classes take the Resource datas that have been
 *	parsed from the Bibliography and format it so that it fits the 
 * 	desired style of references. 
*/
private:
	virtual OutputCitation * formatBook(BookData * data);
	virtual OutputCitation * formatConference(ConferenceData * data);
	virtual OutputCitation * formatJournal(JournalData * data);
	virtual OutputCitation * formatTechnicalReport(TechnicalReportData * data);
	virtual OutputCitation * formatWebsite(WebsiteData * data);

public:
	StyleFormatter(void);
	~StyleFormatter(void);

	OutputCitation * format(ResourceData * data);

};

