
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
	Publication();
	virtual ~Publication();
};

#endif /* PUBLICATION_H_ */
