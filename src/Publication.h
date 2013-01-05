/*
 * Publication.h
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#include <string>
#include <ctime>
using namespace std;

#ifndef PUBLICATION_H_
#define PUBLICATION_H_

class Publication {
public:
	string content;
	time_t creation_datetime;
	string creator_user_name;
	string description;
	long id;
	bool is_anonymous;
	time_t last_edition_datetime;

	Publication();
	virtual ~Publication();

};

#endif /* PUBLICATION_H_ */
