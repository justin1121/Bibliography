/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * This provides and encapsulation of a list of ResourceDatas and
 * provides methods for add a Citation, checking to see if the list
 * is empty and getting the next Citation in the list.
 ******************************************************************/
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

