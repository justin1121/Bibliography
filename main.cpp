#include "BibliographyParser.h"
#include <iostream>
// just included so will run on wins :)
#include <sstream>
#include <fstream>

using namespace std;

int main (int argc, char * const argv[]){
	string iFileName;

	cout << "please enter bib file name" << endl;

	// same with this just here to run on wins used to be:
	// cin >> iFileName ... dunno why VS doesn't like it
	/*

	     REMOVE BEFORE SUBMISSION

	*/
	getline(cin, iFileName);
	const char* bFileName= iFileName.c_str();
	//const char* bFileName = "/Users/Jocelyne/Desktop/bibliography.txt";
	
	BibliographyParser bParser(bFileName);
		
		//print bibliography
		//bParser.openBibFile();
		//bParser.printBibliography();
		//bParser.closeBibFile();
		
		//parse bibliographyItems;
		bParser.openBibFile();
		bParser.parseBibliographyItems();
		bParser.closeBibFile();
		
	return 0;
	
	
}