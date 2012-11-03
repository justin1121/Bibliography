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

OutputCitation * ACMFormatter::format(ResourceData * data){
	OutputCitation * outCite;
	
	//find out which type the resource is
	switch (data->getType()){
		case 1:
			//format the resource as a book
			outCite = formatBook((BookData*)data);		
		  break;	
		case 2:
			//format the resource as a conference
			outCite = formatConference((ConferenceData*)data);
			break;
		case 3:
			//format the resource as a journal
			outCite = formatJournal((JournalData*)data);
			break;
		case 4:
			//format the resource as a technical report
			outCite = formatTechnicalReport((TechnicalReportData*)data);
			break;
		default :
      cout << data->getType() << ": " <<"Style doesn't exist!" << "\n";
			exit(1);
	}
	
	return outCite;
}

OutputCitation * ACMFormatter::formatBook(BookData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Book style
	//Authors. Date. Title. Publisher, Place
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getPublisher());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getPlace());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}

OutputCitation * ACMFormatter::formatConference(ConferenceData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Conference style
	//Authors. Date. Title. Proceedings, place of conf, date of conf., pub, city of pub, pages.
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getProceedings());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getPlaceOfConference());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getDateOfConference());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getPublisher());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getCity());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getPages());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}

OutputCitation * ACMFormatter::formatJournal(JournalData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Journal style
	//Author(s). year. Title. Journal. volume, issue, pages. 
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getJournal());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getVolume());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getNumber());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getPages());
	referenceUnit = referenceUnit.append(". ");

	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}

OutputCitation * ACMFormatter::formatTechnicalReport(TechnicalReportData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Technical Report style
	//Author. Date. Title. Company, TR No. #. Publisher, Place
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getDate());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getOrganization());
	referenceUnit = referenceUnit.append(", TR No. ");
	referenceUnit = referenceUnit.append((string)data->getNumber());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getPublisher());
	referenceUnit = referenceUnit.append(", ");
	referenceUnit = referenceUnit.append((string)data->getPlace());
	referenceUnit = referenceUnit.append(". ");
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}

OutputCitation * ACMFormatter::formatWebsite(WebsiteData * data){
	OutputCitation * finalCitation = new OutputCitation();
	string referenceUnit = "";
	
	//Format the resource into ACM Website style
	//author. date. Title. Site. URL
	referenceUnit = referenceUnit.append((string)data->getAuthor());
	referenceUnit = referenceUnit.append(". ");      
	referenceUnit = referenceUnit.append((string)data->getDate());
	referenceUnit = referenceUnit.append(". ");      
	referenceUnit = referenceUnit.append((string)data->getTitle());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getSite());
	referenceUnit = referenceUnit.append(". ");
	referenceUnit = referenceUnit.append((string)data->getURL());
	referenceUnit = referenceUnit.append(". ");      
	
	
	finalCitation->setCitation(referenceUnit);
	
	return finalCitation;
}
