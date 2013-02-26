
#ifndef CLARIFICATION_H_
#define CLARIFICATION_H_

// Includes
#include "Publication.h"
#include "User.h"
#include <string>

class Clarification {

public:
	std::string answer;
	std::string publication_id;
	std::string creator_user_name;
	std::string id;
	std::string question;
	User *link_user;
	Publication *link_publication;
	Clarification();
	virtual ~Clarification();
};

#endif /* CLARIFICATION_H_ */
