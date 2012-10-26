#pragma once
#include "styleformatter.h"
class ACMFormatter : public StyleFormatter{
private:
	OutputCitation formatBook();
	OutputCitation formatJournal();
	OutputCitation formatConference();
	OutputCitation formatTechnicalReport();
public:
	ACMFormatter(void);
	~ACMFormatter(void);

	OutputCitation format();
};

