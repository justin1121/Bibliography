#include "CitationList.h"

CitationList::CitationList(void){
}

CitationList::~CitationList(void){
}

void CitationList::addCitation(ResourceData data){
	dataList.push_front(data);
}

ResourceData CitationList::nextCitation(void){
   ResourceData temp = dataList.front();
   dataList.pop_front();

   return temp;
}

bool CitationList::empty(void){
	return dataList.empty();
}

int CitationList::size(void){
	return dataList.size();
}
