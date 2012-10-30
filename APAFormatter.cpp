/*
 *	Name: 			Logan Pitman
 *	Date: 			10/29/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	Formats ResourceData objects into APA format
 */
#include "APAFormatter.h"

APAFormatter::APAFormatter(void){
}

APAFormatter::~APAFormatter(void){
}

OutputCitation * APAFormatter::format(ResourceData data){
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
			exit (1);
	}
	
	return outCite;
}

OutputCitation * APAFormatter::formatBook(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into APA Book style
	//Author, A. A. (Year). Title of work. Location: Publisher.
	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append("(");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append("). ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getPlace());
	referenceUnit = referenceUnit.append(": ");
	referenceUnit = referenceUnit.append((string)data.getPublisher());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}

OutputCitation * APAFormatter::formatConference(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into APA Conference style
	//Author(s). (Year). Title. Proceedings, Place, Date-of-Conference. City: Publisher. pages
	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append("(");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append("). ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getProceedings());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getPlace());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getDateOfConference());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getCity());
	referenceUnit = referenceUnit.append(": ");
	referenceUnit = referenceUnit.append((string)data.getPublisher());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getPages());
	referenceUnit = referenceUnit.append(". ");	
	
	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}

OutputCitation * APAFormatter::formatJournal(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into APA Journal style
	//Author, A. (date). Name of Article. Name of Journal, Volume(Issue), Page.

	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append("(");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append("). ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getJournal());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getVolume());
	referenceUnit = referenceUnit.append("( ");
	referenceUnit = referenceUnit.append((string)data.getNumber());
	referenceUnit = referenceUnit.append("), ");
	referenceUnit = referenceUnit.append((string)data.getPages());
	referenceUnit = referenceUnit.append(". ");	
	
	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}

OutputCitation * APAFormatter::formatTechnicalReport(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into APA Technical Report style
	//Author (year). Title (Organization Report No. number). place: publisher.
	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append("(");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append("). ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(" (");
	referenceUnit = referenceUnit.append((string)data.getOrganization());
	referenceUnit = referenceUnit.append(" Report No. ");
	referenceUnit = referenceUnit.append((string)data.getNumber());
	referenceUnit = referenceUnit.append("). ");
	referenceUnit = referenceUnit.append((string)data.getPlace());
	referenceUnit = referenceUnit.append(": ");
	referenceUnit = referenceUnit.append((string)data.getPublisher());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation
}