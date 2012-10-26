#pragma once
#include "CitationList.h"
#include "StyleFormatter.h"
#include "OutputCitation.h"

class BibliographyGenerator{
	CitationList list;
	StyleFormatter formatter;
	OutputCitation * citation;
public:
	BibliographyGenerator(void);
	~BibliographyGenerator(void);
	void generate(void);
	void printCitations(void);
};

