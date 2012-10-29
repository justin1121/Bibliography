/*
 *	Name: 			Logan Pitman
 *	Date: 			10/26/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	
 */

#include "IEEEFormatter.h"

IEEEFormatter::IEEEFormatter(void){
	
}

IEEEFormatter::~IEEEFormatter(void){
}

OutputCitation * IEEEFormatter::format(ResourceData data){
	OutputCitation * outCite;
	
	//find out which type the resource is
	switch (data.getType()){
		case 1:
			//format the resource as a book
			outCite = formatBook(data);		
			
		case 2:
			//format the resource as a conference
			outCite = formatConference(data);
			
		case 3:
			//format the resource as a journal
			outCite = formatJournal(data);
			
		case 4:
			//format the resource as a technical report
			outCite = formatTechnicalReport(data);
			
		default :
			cout << "\nFormatter Error: type not found\n";
			exit (1);
	}
}

OutputCitation * IEEEFormatter::formatBook(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into IEEE Book style
	//Author(s), Book Title. Place of publication: Publisher, year
	referenceUnit.append((string)data.getAuthor());

	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}

OutputCitation * IEEEFormatter::formatConference(ResourceData data){
	return 0;
}

OutputCitation * IEEEFormatter::formatJournal(ResourceData data){
	return 0;
}

OutputCitation * IEEEFormatter::formatTechnicalReport(ResourceData data){
	return 0;
}