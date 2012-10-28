#pragma once
#include <list>

#include "ResourceData.h"

using namespace std;

static int count = 0;

class CitationList{
private:
	list<ResourceData> dataList;
public:
	CitationList(void);
	~CitationList(void);
	void addCitation(ResourceData);
	bool empty(void);
	ResourceData nextCitation(void);
};

