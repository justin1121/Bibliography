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
#include <cstdlib>
using namespace std;

class BibliographyGenerator{
	CitationList 	citeList;
	StyleFormatter 	* formatter;
	OutputCitation 	* citation;
	//list 			outputlist;
	
public:
	BibliographyGenerator(CitationList list, int style);
	~BibliographyGenerator(void);
	void generate(void);
	void printCitations(void);

	
};

