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
	Publication();
	Publication(long id, string content, string description,
			bool is_anonymous, time_t last_edition_datetime,
			time_t creation_datetime);
	virtual ~Publication();
private:
	long id;
	string content;
	string description;
	bool is_anonymous;
	time_t last_edition_datetime;
	time_t creation_datetime;
};

#endif /* PUBLICATION_H_ */
