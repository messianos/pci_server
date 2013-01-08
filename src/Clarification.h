
#ifndef CLARIFICATION_H_
#define CLARIFICATION_H_

// Includes
#include <string>

class Clarification {

public:
	std::string answer;
	std::string associated_publication_id;
	std::string creator_user_name;
	std::string id;
	std::string question;
	Clarification();
	virtual ~Clarification();
};

#endif /* CLARIFICATION_H_ */
