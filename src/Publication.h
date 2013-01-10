
#ifndef PUBLICATION_H_
#define PUBLICATION_H_

// Includes
#include <ctime>
#include <string>

class Publication {

public:
	std::string content;
	time_t creation_datetime;
	std::string creator_user_name;
	std::string description;
	std::string id;
	short int is_anonymous;
	time_t last_edition_datetime;
	Publication();
	virtual ~Publication();
};

#endif /* PUBLICATION_H_ */
