#pragma once
#include "ResourceData.h"

class CitationList{
public:
	CitationList(void);
	~CitationList(void);
	void addCitation(ResourceData data);
	ResourceData nextCitation(void);
};

