/******************************************************************
 * Name: Justin Patriquin
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * Contains the implemention for all of the functions that 
 * encapsulate all of the methods that are needed for the 
 * CitationList to functions correctly.
 ******************************************************************/
#include "CitationList.h"

CitationList::CitationList(){

}

CitationList::~CitationList(){

}
/*******************************************************************
 * addCitation
 *
 * Reads in a pointer to a ResourceData object and pushes it into
 * the front of the list.
 ******************************************************************/
void CitationList::addCitation(ResourceData * data){
	dataList.push_front(data);
}

/*******************************************************************
 * nextCitation
 *
 * Returns the last ResourceData object that was put into the list.
 ******************************************************************/
ResourceData * CitationList::nextCitation(void){
   ResourceData * temp = dataList.front();
   dataList.pop_front();

   return temp;
}

/*******************************************************************
 * empty 
 *
 * Return true or false depending on if the list is empty or not.
 ******************************************************************/
bool CitationList::empty(void){
	return dataList.empty();
}

/*******************************************************************
 * size 
 *
 * Returns the number of ResourceData objects in the list. 
 ******************************************************************/
int CitationList::size(void){
	return dataList.size();
}
