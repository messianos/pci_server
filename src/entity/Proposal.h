
#ifndef PROPOSAL_H_
#define PROPOSAL_H_

#include "../auxiliar/Datetime.h"
#include "Solution.h"
#include "User.h"
#include <string>

class Proposal {

public:
	std::string content;
	Datetime *creation_datetime;
	std::string creator_user_name;
	std::string id;
	short int is_anonymous;
	Datetime *last_edition_datetime;
	int vote_balance;
	std::string solution_id;
	User *link_user;
	Solution *link_solution;
	Proposal();
	virtual ~Proposal();
};

#endif /* PROPOSAL_H_ */
