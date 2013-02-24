#ifndef NOTIFICATIONANNOUNCER_H_
#define NOTIFICATIONANNOUNCER_H_

//Includes
#include <list>
#include <set>
#include <string>
#include "../entity/User.h"
#include "../entity/Solution.h"
#include "../service/DatabaseInterface.h"
#include <iosfwd>

class NotificationAnnouncer {
public:
	NotificationAnnouncer();
	virtual ~NotificationAnnouncer();

	struct classcomp {
		bool operator()(const std::string& lhs, const std::string& rhs) const {
			return lhs.compare(rhs) < 0;
		}
	};

	static std::set<std::string, NotificationAnnouncer::classcomp> *postSolution(std::string user_name, std::string problem_id);
	static std::set<std::string, NotificationAnnouncer::classcomp> *postProposal(std::string user_name, std::string solution_id);
	static std::set<std::string, NotificationAnnouncer::classcomp> *postClarificationInProblem(std::string problem_id);
	static std::set<std::string, NotificationAnnouncer::classcomp> *postClarificationInSolution(std::string solution_id);

	static std::set<std::string, NotificationAnnouncer::classcomp> *replyClarification(std::string id);

	static std::set<std::string, NotificationAnnouncer::classcomp> *voteProblem(std::string problem_id);
	static std::set<std::string, NotificationAnnouncer::classcomp> *voteSolution(std::string solution_id);
	static std::set<std::string, NotificationAnnouncer::classcomp> *voteProposal(std::string proposal_id);

	static std::set<std::string, NotificationAnnouncer::classcomp> *acceptSolution(std::string solution_id);

};

#endif /* NOTIFICATIONANNOUNCER_H_ */
