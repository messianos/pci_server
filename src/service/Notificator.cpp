
// Includes
#include "Notificator.h"

// Namespaces
using namespace std;

/*
 * Problem methods
 */

void Notificator::editProblem(Problem *problem) {
	// FIXME: SEE THE SOLUTION EDIT
	UserNameSet involved_users;

	// Notify subclass_elements

	list<Solution*>* solutions = DatabaseInterface::searchSolutions(problem->id);
	for (Solution* solution : *solutions) {
		// --- Creators
		involved_users[solution->creator_user_name] = solution->creator_user_name;

		// --- Voters
		list<string>* solution_voters = DatabaseInterface::searchSolutionVoters(solution->id);
		for (string user : *solution_voters) {
			involved_users[user] = user;
		}
	}

	// Remove the problem creator
	involved_users.erase(problem->creator_user_name);

	// Add notifications to DB
	for (auto user : involved_users) {
		Notification* notification = new Notification();

		notification->event_code = "0";
		notification->originator_user_name = problem->creator_user_name;
		notification->user_name = user.second;
		notification->url = "/publication/" + problem->id;

		DatabaseInterface::insertNotification(notification);
	}
}

void Notificator::voteProblem(Problem *problem, std::string originator_user_name) {
	// Notify class creator

	Notification* notification = new Notification();

	notification->event_code = "0";
	notification->originator_user_name = originator_user_name;
	notification->seen = 0;
	notification->url = "/publication/" + problem->id;
	notification->user_name = problem->creator_user_name;

	DatabaseInterface::insertNotification(notification);
}

void Notificator::setAcceptedSolution(Problem* problem, Solution* solution) {
	// Notify problem subclass_elements
	// Notify voters
	// Notify solution creator
	// Notify solution subclass_members
}

void Notificator::unsetAcceptedSolution(Problem* problem) {
}

/*
 * Solution methods
 */

void Notificator::publicateSolution(Solution* solution) {
	UserNameSet problem_voters;

	// Notify parent class creator
	Problem* problem = DatabaseInterface::searchProblem(solution->problem_id);

	Notification* notification = new Notification();

	notification->event_code = "0";
	notification->originator_user_name = solution->creator_user_name;
	notification->seen = 0;
	notification->url = "/publication/" + solution->id;
	notification->user_name = problem->creator_user_name;

	DatabaseInterface::insertNotification(notification);

	// Notify parent class voters
	list<string>* voters = DatabaseInterface::searchProblemVoters(problem->id);

	for (string user : *voters) {
		problem_voters[user] = user;
	}

	// Delete solution poster
	problem_voters.erase(solution->creator_user_name);

	// Delete problem creator (already notified with different event_code)
	problem_voters.erase(problem->creator_user_name);

	// Add notifications to DB
	for (auto user : problem_voters) {
		Notification* notification = new Notification();

		notification->event_code = "0";
		notification->originator_user_name = solution->creator_user_name;
		notification->seen = 0;
		notification->url = "/publication/" + solution->id;
		notification->user_name = user.second;

		DatabaseInterface::insertNotification(notification);
	}
}

void Notificator::editSolution(Solution* solution) {

	// Notify parent class creator
	Problem* problem = DatabaseInterface::searchProblem(solution->problem_id);

	// Notify parent class voters
	UserNameSet problem_voters;
	list<string>* voters = DatabaseInterface::searchProblemVoters(problem->id);

	for (string user : *voters) {
		problem_voters[user] = user;
	}


	// Notify proposal creators and voters (separately)

	UserNameSet proposal_creators;
	UserNameSet proposal_voters;

	list<Proposal*>* proposals = DatabaseInterface::searchProposals(solution->id);
	for (Proposal* proposal : *proposals) {
		// --- Creators
		proposal_creators[proposal->creator_user_name] = proposal->creator_user_name;

		// --- Voters
		list<string>* proposal_voters_list = DatabaseInterface::searchProposalVoters(proposal->id);
		for (string user : *proposal_voters_list) {
			if(proposal_creators.find(user) == proposal_creators.end())
				proposal_voters[user] = user;
		}
	}

	// Delete solution poster
	proposal_creators.erase(solution->creator_user_name);
	proposal_voters.erase(solution->creator_user_name);

	// Delete problem creator (already notified with different event_code)
	proposal_creators.erase(problem->creator_user_name);
	proposal_voters.erase(problem->creator_user_name);


	// Add notifications to DB

	// Problem creator

	Notification* notification = new Notification();

	notification->event_code = "0";
	notification->originator_user_name = solution->creator_user_name;
	notification->seen = 0;
	notification->url = "/publication/" + solution->id;
	notification->user_name = problem->creator_user_name;

	DatabaseInterface::insertNotification(notification);

	// Problem voters
	for (auto user : problem_voters) {
		Notification* notification = new Notification();

		notification->event_code = "0";
		notification->originator_user_name = solution->creator_user_name;
		notification->seen = 0;
		notification->url = "/publication/" + solution->id;
		notification->user_name = user.second;

		DatabaseInterface::insertNotification(notification);
	}

	// Proposal
	// 		Creators
	for (auto user : proposal_creators) {
		Notification* notification = new Notification();

		notification->event_code = "0";
		notification->originator_user_name = solution->creator_user_name;
		notification->seen = 0;
		notification->url = "/publication/" + solution->id;
		notification->user_name = user.second;

		DatabaseInterface::insertNotification(notification);
	}

	//		Voters
	for (auto user : proposal_voters) {
		Notification* notification = new Notification();

		notification->event_code = "0";
		notification->originator_user_name = solution->creator_user_name;
		notification->seen = 0;
		notification->url = "/publication/" + solution->id;
		notification->user_name = user.second;

		DatabaseInterface::insertNotification(notification);
	}
}

void Notificator::voteSolution(Solution* post, std::string originator_user_name) {
	// Notify class creator

}

/*
 * Clarification methods
 */
void Notificator::askClarification(Publication* publication, std::string originator_user_name) {
	// Notify the class creator

	Notification* notification = new Notification();

	notification->event_code = "0";
	notification->originator_user_name = originator_user_name;
	notification->seen = 0;
	notification->url = "/publication/" + publication->id;
	notification->user_name = publication->creator_user_name;

	DatabaseInterface::insertNotification(notification);

}

void Notificator::answerClarification(Publication* publication, Clarification* clarification) {
	// Notify the asking user
	Notification* notification = new Notification();

	notification->event_code = "0";
	notification->originator_user_name = publication->creator_user_name;
	notification->seen = 0;
	notification->url = "/publication/" + publication->id;
	notification->user_name = clarification->creator_user_name;

	DatabaseInterface::insertNotification(notification);
}

/*
 * Proposal methods
 */

void Notificator::publicateProposal(Proposal* proposal) {
	// Notify parent class creator

	// Notify parent class voters
}

void Notificator::editProposal(Proposal* proposal) {

	// Notify parent class creator

	// Notify parent class voters

}

void Notificator::voteProposal(Proposal* proposal, std::string originator_user_name) {
	// Notify the class creator
}
