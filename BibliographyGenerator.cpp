/*
 *	Name: 			Logan Pitman
 *	Date: 			10/27/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *		Takes in a citation list and formats each of the refences	
 *		according the chosen style of reference. 	
 */

#include "BibliographyGenerator.h"

BibliographyGenerator::BibliographyGenerator(CitationList list, int style){
	citeCount = 0;
	
	//set the style formatter to the selected type
	switch (style){
		case 1: 
			formatter = new IEEEFormatter();
			break;
		
		case 2:
			formatter = new APAFormatter();
			break;
		
		case 3:
			formatter = new ACMFormatter();
			break;
			
		default :
			cout << "Error: style not known";
			exit(1);
	}
	
}

BibliographyGenerator::~BibliographyGenerator(void){
	//destroy the necessary objects
	delete formatter;
	delete citation;
	cout << "\ndead\n";
}

//This function takes in each item in the citation list 
//and sends it to the formatter to be output in the correct style
void BibliographyGenerator::generate(void){
	//need an array of Output Citations
	citation = new OutputCitation[citeList.size()]();
	
	/*	Now format all the references to the chosen style.
	 * 	The returned references are added to the array.
	 */
	while(!citeList.empty()){		
		citation[citeCount] = *(formatter->format(citeList.nextCitation()));
		citeCount++;
	}
	
}

void BibliographyGenerator::printCitations(string filename){
	/*	This function will add the references to the inputted file.
	 * 	The references will be a appended to the end in a "References"
	 *	section.
	*/
	ofstream outputFile;
	outputFile.open(filename, ios_base::app);
	
	outputFile << "\n\nReferences: \n\n";
	
	int i;
	for(i = 0; i < citeCount; i++){
		outputFile << citation[i];
		outputFile << "\n";
	}
	
	outputFile.close();
}