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

	virtual OutputCitation * format();
};

