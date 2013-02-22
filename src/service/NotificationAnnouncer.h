#ifndef NOTIFICATIONANNOUNCER_H_
#define NOTIFICATIONANNOUNCER_H_

//Includes
#include <list>
#include <string>
#include "../entity/User.h"
#include "../entity/Solution.h"
#include "../service/DatabaseInterface.h"

class NotificationAnnouncer {
public:
	NotificationAnnouncer();
	virtual ~NotificationAnnouncer();
	static std::list<User *> *postSolution(std::string problem_id);
	static std::list<User *> *postProposal(std::string solution_id);
	static std::list<User *> *postClarificationInProblem(std::string problem_id);
	static std::list<User *> *postClarificationInSolution(std::string solution_id);

	static std::list<User *> *replyClarification(std::string id);

	static std::list<User *> *voteProblem(std::string problem_id);
	static std::list<User *> *voteSolution(std::string solution_id);
	static std::list<User *> *voteProposal(std::string proposal_id);

	static std::list<User *> *acceptSolution(std::string solution_id);
};

#endif /* NOTIFICATIONANNOUNCER_H_ */
