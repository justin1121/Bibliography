/*
 *	Name: 			Logan Pitman
 *	Date: 			10/26/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	
 */

#pragma once
#include "StyleFormatter.h"

class IEEEFormatter : public StyleFormatter{
private:
	OutputCitation * formatBook();
	OutputCitation * formatConference();
	OutputCitation * formatJournal();
	OutputCitation * formatTechnicalReport();
public:
	IEEEFormatter(void);
	~IEEEFormatter(void);

	OutputCitation * format(ResourceData data);
};

