#include <iostream>
// just included so will run on wins :)
#include <sstream>
#include <fstream>
#include "BibliographyGenerator.h"
#include "BibliographyParser.h"

using namespace std;

int main (int argc, char * const argv[]){
	string iFileName;
	string pFileName;

	cout << "Please enter bib file name: " << endl;

	// same with this just here to run on wins used to be:
	// cin >> iFileName ... dunno why VS doesn't like it
	/*

	     REMOVE BEFORE SUBMISSION

	*/
	getline(cin, iFileName);
	const char* bFileName= iFileName.c_str();

	cout << "Please enter the text file name: " << endl;
	getline(cin, pFileName);
	const char * tFileName = pFileName.c_str();

	BibliographyParser bParser(bFileName, tFileName);
		
	bParser.openFiles();
	bParser.parseBibliographyItems();
  bParser.parseInputFile();
	
	BibliographyGenerator bgen(bParser.getCitationList(), 1);
	
	bgen.generate();
		
	return 0;
}
