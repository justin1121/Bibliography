/*
 *	Name: 			Logan Pitman
 *	Date: 			10/29/12 
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *	Formats ResourceData objects into ACM format
 */

#include "ACMFormatter.h"

ACMFormatter::ACMFormatter(void){
}

ACMFormatter::~ACMFormatter(void){
}

OutputCitation * ACMFormatter::format(ResourceData data){
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

OutputCitation * ACMFormatter::formatBook(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Book style
	//Authors. Date. Title. Publisher, Place
	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getPublisher());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getPlace());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}

OutputCitation * ACMFormatter::formatConference(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Conference style
	//Authors. Date. Title. Proceedings, place of conf, date of conf., pub, city of pub, pages.
	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getProceedings());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getPlace());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getDateOfConference());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getPublisher());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getCity());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getPages());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}

OutputCitation * ACMFormatter::formatJournal(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Journal style
	//Author(s). year. Title. Journal. volume, issue, pages. 
	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getJournal());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getVolume());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getNumber());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getPages());
	referenceUnit = referenceUnit.append(". ");

	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}

OutputCitation * ACMFormatter::formatTechnicalReport(ResourceData data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Technical Report style
	//Author. Date. Title. Company, TR No. #. Publisher, Place
	referenceUnit = referenceUnit.append((string)data.getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getCompany());
	referenceUnit = referenceUnit.append(", TR No. ");
	referenceUnit = referenceUnit.append((string)data.getNumber());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data.getPublisher());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data.getPlace());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation((char *)referenceUnit.c_str());
	
	return finalCitation;
}