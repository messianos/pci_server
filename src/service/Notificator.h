
#ifndef NOTIFICATIONANNOUNCER_H_
#define NOTIFICATIONANNOUNCER_H_

//Includes
#include "../entity/User.h"
#include "../entity/Solution.h"
#include "../service/DatabaseInterface.h"
#include <boost/unordered_map.hpp>
#include <list>
#include <string>

// Type definitions
typedef boost::unordered_map<std::string, std::string> UserNameSet;

class Notificator {
public:
	/** New definitions of methods (specification in gdrive) */
	// FIXME: Edit: missing class voters!

	// Problem methods
	static void editProblem(Problem *problem);
	static void voteProblem(Problem *problem, std::string originator_user_name);

	static void setAcceptedSolution(Problem* problem, Solution* solution);
	static void unsetAcceptedSolution(Problem* problem);

	// Solution methods
	static void publicateSolution(Solution* solution);
	static void editSolution(Solution* solution);
	static void voteSolution(Solution* solution, std::string originator_user_name);

	// Clarification methods
	static void askClarification(Publication* publication, std::string originator_user_name);
	static void answerClarification(Publication* publication, Clarification* clarification);

	// Proposal methods
	static void publicateProposal(Proposal* proposal);
	static void editProposal(Proposal* proposal);
	static void voteProposal(Proposal* proposal, std::string originator_user_name);

};

#endif /* NOTIFICATIONANNOUNCER_H_ */
