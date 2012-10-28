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
#include "OutputCitation.h"

class StyleFormatter{
protected:
	ResourceData data;

	virtual OutputCitation * formatBook();
	virtual OutputCitation * formatConference();
	virtual OutputCitation * formatJournal();
	virtual OutputCitation * formatTechnicalReport();
public:
	StyleFormatter(void);
	~StyleFormatter(void);

	virtual OutputCitation * format(ResourceData data);
};

