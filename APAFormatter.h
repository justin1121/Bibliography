#pragma once
#include "StyleFormatter.h"
class APAFormatter : public StyleFormatter{
private:
	OutputCitation formatBook();
	OutputCitation formatConference();
	OutputCitation formatJournal();
	OutputCitation formatTechnicalReport();
public:
	APAFormatter(void);
	~APAFormatter(void);

	OutputCitation format();
};

