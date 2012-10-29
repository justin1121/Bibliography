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
#include "OutputCitation.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class StyleFormatter{
protected:
	ResourceData data;

	OutputCitation * formatBook(BookData data);
	OutputCitation * formatConference(ConferenceData data);
	OutputCitation * formatJournal(JournalData data);
	OutputCitation * formatTechnicalReport(TechnicalReportData data);
public:
	StyleFormatter(void);
	~StyleFormatter(void);

	OutputCitation * format(ResourceData data);
};

