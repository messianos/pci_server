
#ifndef DATABASEINTERFACE_H_
#define DATABASEINTERFACE_H_

// Includes
#include "../auxiliar/ErrorCode.h"
#include "../entity/Clarification.h"
#include "../entity/Notification.h"
#include "../entity/Problem.h"
#include "../entity/Solution.h"
#include "../entity/Proposal.h"
#include "../entity/User.h"
#include <cppdb/frontend.h>
#include <ctime>
#include <list>
#include <string>
#include <sstream>

class DatabaseInterface {

private:
	static cppdb::session database_handler;

public:

	/*
	 * User operations
	 */
	static User *searchUser(std::string user_name);
	static bool signInUser(std::string user_name, std::string encrypted_password);
	static ErrorCode *signUpUser(User *user, std::string encrypted_password);
	static User *searchUserByProblem(std::string problem_id);
	static User *searchUserBySolution(std::string solution_id);
	static User *searchUserByProposal(std::string proposal_id);
	static User *searchUserByClarification(std::string clarification_id);

	static int getUserVoteOnProblem(std::string user_name, std::string problem_id);
	static int getUserVoteOnSolution(std::string user_name, std::string solution_id);

	/*
	 * Publication operations
	 */
	static Publication* searchPublication(std::string publication_id);

	/*
	 * Problem operations
	 */
	static Problem *searchProblem(std::string id);
	static std::list<Problem *> *searchProblems(/* TODO: define parameters */);
	static std::list<Problem *> *searchProblemsByUser(std::string user_name);
	static std::list<Problem *> *searchProblemsRandom(int amount);
	static std::list<Problem *> *searchProblemsUnsolved(int amount);
	static std::list<Problem *> *searchProblemsLatest(int amount);
	static std::list<Problem *> *searchProblemsNoSolutions(int amount);
	static std::list<Problem *> *searchProblemsMostVoted(int amount);
	static Problem *searchProblemByAcceptedSolution(std::string solution_id);

	static ErrorCode *insertProblem(Problem *problem);
	static ErrorCode *deleteProblem(std::string id);
	static ErrorCode *updateProblemContent(std::string id, std::string content);

	static ErrorCode *voteProblem(std::string problem_id, std::string user_name, bool is_positive);

	static ErrorCode *setAcceptedSolution(std::string problem_id, std::string solution_id);
	static ErrorCode *unsetAcceptedSolution(std::string problem_id);

	static int getProblemVoteBalance(std::string problem_id);

	/*
	 * Solution operations
	 */
	static Solution *searchSolution(std::string id);
	static Solution *searchAcceptedSolution(std::string problem_id);
	static std::list<Solution *> *searchSolutions(std::string problem_id);
	static std::list<Solution *> *searchSolutionsByUser(std::string user_name);

	static ErrorCode *insertSolution(Solution *solution, std::string problem_id);
	static ErrorCode *deleteSolution(std::string id);

	static ErrorCode *voteSolution(std::string solution_id, std::string user_name, bool is_positive);
	static int getSolutionVoteBalance(std::string solution_id);


	/*
	 * Proposal operations
	 */
	static Proposal *searchProposal(std::string id);
	static std::list<Proposal *> *searchProposals(std::string solution_id);
	static std::list<Proposal *> *searchProposalsByUser(std::string user_name);
	static ErrorCode *insertProposal(Proposal *proposal, std::string solution_id);
	static ErrorCode *deleteProposal(std::string id);

	/*
	 * Clarification operations
	 */
	static Clarification *searchClarification(std::string id);
	static std::list<Clarification *> *searchClarifications(std::string associated_publication_id);
	static ErrorCode *insertClarification(Clarification *clarification);
	static ErrorCode *deleteClarification(std::string id);

	static ErrorCode *answerClarification(std::string id, std::string answer);
	static std::list<Clarification*>* searchAnsweredClarifications(std::string problem_id);
	static std::list<Clarification*>* searchAnsweredClarifications(std::string problem_id, std::string user_name);

	/*
	 * Statistical operations
	 */
	static int numberOfSolutionsByUser(std::string user_name);
	static int numberOfProblemsByUser(std::string user_name);
	static int numberOfAcceptedSolutionsByUser(std::string user_name);
	static int numberOfSolutions(std::string problem_id);
	static std::list<Publication *> * getRecentActivityByUser(std::string user_name);

	/*
	 * Notifications operations
	 */
	static ErrorCode* insertNotification(Notification* notification);
	static std::list<Notification *> *getUnseenNotifications(std::string user_name);


	/*
	 * Generalized data structure fetchers
	 */
	static Clarification* fetchClarification(cppdb::result result);
	static Problem* fetchProblem(cppdb::result result);
	static Solution* fetchSolution(cppdb::result result);
	static Proposal* fetchProposal(cppdb::result result);
	static User* fetchUser(cppdb::result result);
	static Notification* fetchNotification(cppdb::result result);


};

#endif /* DATABASEINTERFACE_H_ */
