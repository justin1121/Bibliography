#include "CitationList.h"

CitationList::CitationList(int numEntries){
  data = new ResourceData[numEntries]
}

CitationList::~CitationList(void){
}

void CitationList::addCitation(int i, ResourceData data){
  data[i] = &data;
}

ResourceData CitationList::nextCitation(void){
   Resource d;

	 d = data[count];
   index++;
    
   return d;
}
