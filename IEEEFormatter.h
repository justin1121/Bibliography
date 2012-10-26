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

	OutputCitation * format();
};

