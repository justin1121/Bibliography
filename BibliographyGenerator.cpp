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
	citeList = list;
	
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
			cout << "Error: that ain't a style";
			exit(1);
	}
	
	outputlist = new list<string>();
}

BibliographyGenerator::~BibliographyGenerator(void){
	delete formatter;
	cout << "\ndead\n";
}

//This function takes in each item in the citation list 
//and sends it to the formatter to be output in the correct style
void BibliograpyGenerator::generate(void){
	string referenceUnit = "";
	
	while(!testList.empty()){
		tempString = testList.front();
		tempList.pop_front();
		
		formatter.format(tempString);
	}
}

void BibliograpyGenerator::printCitations(void){

}