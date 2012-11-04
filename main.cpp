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

	cin >> iFileName;
	const char* bFileName= iFileName.c_str();

	cout << "Please enter the text file name: " << endl;
	cin >>  pFileName;
	const char * tFileName = pFileName.c_str();

	BibliographyParser bParser(bFileName, tFileName);

  string file_string;

	bParser.openFiles();
	bParser.parseBibliographyItems();
  bParser.parseInputFile(&file_string);

  cout << "Please enter type of formatter: (1) IEEE (2) ACM (3) APA\n";

  int type;
  string outputFileName = "text-output-";

  cin >> type;
  
  switch(type){
    case 1:
      outputFileName += "IEEE";
      break;
    case 2:
      outputFileName += "ACM";
      break;
    case 3:
      outputFileName += "APA";
      break;
    default:
      cout << "Unknown type...exitting!";
      exit(1);
  }

  outputFileName += ".txt";

	BibliographyGenerator bgen(bParser.getCitationList(), type);
  bgen.generate();

  bgen.printInText(file_string, outputFileName.c_str());
  bgen.printCitations(outputFileName.c_str());
	
	return 0;
}
