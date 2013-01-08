
#ifndef PUBLICATION_H_
#define PUBLICATION_H_

// Includes
#include <string>

class Publication {

public:
	std::string content;
	//time_t creation_datetime; TODO
	std::string creator_user_name;
	std::string description;
	std::string id;
	bool is_anonymous;
	//time_t last_edition_datetime; TODO
	Publication();
	virtual ~Publication();
};

#endif /* PUBLICATION_H_ */
