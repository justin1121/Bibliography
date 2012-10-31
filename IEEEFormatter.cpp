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

OutputCitation * IEEEFormatter::format(ResourceData * data){
	OutputCitation * outCite;
	
	//find out which type the resource is
	switch (data->getType()){
		case 1:
			//format the resource as a book
			outCite = formatBook((BookData*)data);		
			
		case 2:
			//format the resource as a conference
			outCite = formatConference((ConferenceData*)data);
			
		case 3:
			//format the resource as a journal
			outCite = formatJournal((JournalData*)data);
			
		case 4:
			//format the resource as a technical report
			outCite = formatTechnicalReport((TechnicalReportData*)data);
			
		default :
			exit (1);
	}
	
	return outCite;
}

OutputCitation * IEEEFormatter::formatBook(BookData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into IEEE Book style
	//Author(s), Book Title. Place of publication: Publisher, year
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(". ");      
	referenceUnit = referenceUnit.append((string)data->getPlace());
	referenceUnit = referenceUnit.append(": ");      
	referenceUnit = referenceUnit.append((string)data->getPublisher());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getDate());
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}

OutputCitation * IEEEFormatter::formatConference(ConferenceData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into IEEE Conference style
	//Author, “Title of paper,” Proceedings, date, pp.
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(", \"");    
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(",\" ");    
	referenceUnit = referenceUnit.append((string)data->getProceedings());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getDate());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getPages());
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}

OutputCitation * IEEEFormatter::formatJournal(JournalData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into IEEE Journal style
	//Author(s), "Article title", Journal Title, vol. #, no. #, pp. #, date
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(", \"");    
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(",\" ");    
	referenceUnit = referenceUnit.append((string)data->getJournal());
	referenceUnit = referenceUnit.append(", vol. "); 
	referenceUnit = referenceUnit.append((string)data->getVolume());
	referenceUnit = referenceUnit.append(", no. ");  
	referenceUnit = referenceUnit.append((string)data->getNumber());
	referenceUnit = referenceUnit.append(", pp. ");  
	referenceUnit = referenceUnit.append((string)data->getPages());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getDate());
	
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}

OutputCitation * IEEEFormatter::formatTechnicalReport(TechnicalReportData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into IEEE TechnicalReport style
	//Author, Title, Abbrev. Name of Co., Report xxx. City of Co., Abbrev. State, Publisher, year
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getOrganization());
	referenceUnit = referenceUnit.append(", Report ");
	referenceUnit = referenceUnit.append((string)data->getNumber());
	referenceUnit = referenceUnit.append(". ");      
	referenceUnit = referenceUnit.append((string)data->getPlace());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getPublisher());
	referenceUnit = referenceUnit.append(", ");      
	referenceUnit = referenceUnit.append((string)data->getDate());
	
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
	}
