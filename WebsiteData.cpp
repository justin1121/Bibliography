/******************************************************************
 * Name: Logan Pitman
 * Date: Oct 27, 2012
 * Organization: Dalhousie University, Faculty of Computer Science
 *
 * Description:
 *
 * Contains the implemention for all of the getters and setters for
 * the WebsiteData, pretty straight-forward.
 ******************************************************************/
#include "WebsiteData.h"

WebsiteData::WebsiteData(void){
  siteToken = "Site";
  urlToken  = "URL";
}

WebsiteData::~WebsiteData(void){
}

string WebsiteData::getSite(){
	return site;
}
string WebsiteData::getURL(){
	return url;
}

void WebsiteData::setSite(string site){
	WebsiteData::site = site;
}
void WebsiteData::setURL(string url){
	WebsiteData::url = url;
}


