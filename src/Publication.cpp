/*
 * Publication.cpp
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#include "Publication.h"

Publication::Publication(){

}

Publication::Publication(long id, string content, string description,
		bool is_anonymous, time_t last_edition_datetime,
		time_t creation_datetime) {
	this->id = id;
	this->content = content;
	this->description = description;
	this->is_anonymous = is_anonymous;
	this->last_edition_datetime = last_edition_datetime;
	this->creation_datetime = creation_datetime;
}

Publication::~Publication() {
// TODO Auto-generated destructor stub
}

long Publication::getID(){
	return id;
}

void Publication::setID(long id){
	this->id = id;
}
