
#ifndef PUBLICATION_H_
#define PUBLICATION_H_

// Includes
#include "Datetime.h"
#include <string>

class Publication {

public:
	std::string content;
	Datetime *creation_datetime;
	std::string creator_user_name;
	std::string description;
	std::string id;
	short int is_anonymous;
	Datetime *last_edition_datetime;
	int vote_balance;
	Publication();
	virtual ~Publication();

	//TODO: Compares last_editon_datetime
	static bool publicationComparator(Publication* first, Publication* second);

};

#endif /* PUBLICATION_H_ */
