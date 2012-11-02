/*
 *	Name: 			Logan Pitman
 *	Date: 			10/27/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *		Takes in a citation list and formats each of the refences	
 *		according the chosen style of reference. 
 */

#pragma once
#include "CitationList.h"
#include "StyleFormatter.h"
#include "IEEEFormatter.h"
#include "APAFormatter.h"
#include "ACMFormatter.h"
#include "OutputCitation.h"
#include "ResourceData.h"
#include "BookData.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

class BibliographyGenerator{
	/*	Has an inputted list of citations and creates a 
	*	formatter based on the given type. Adds the formatted
	*	to an output citation object.
	*/
	
	CitationList 	citeList;
	StyleFormatter 	* formatter;
	OutputCitation 	* citation;
	int 			citeCount;
  int style;
public:
	BibliographyGenerator(CitationList list, int style);
	~BibliographyGenerator(void);
	void generate(void);
	void printCitations(string);

	
};

