#pragma once
#include "ResourceData.h"

static int count = 0;

class CitationList{
private:
  ResourceData * data;
public:
	CitationList(void);
	~CitationList(void);
	void addCitation(int, ResourceData);
	ResourceData nextCitation(void);
};

