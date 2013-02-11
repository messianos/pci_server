
#ifndef DATABASEINTERFACE_H_
#define DATABASEINTERFACE_H_

// Includes
#include "Clarification.h"
#include "ErrorCode.h"
#include "Problem.h"
#include "Solution.h"
#include "User.h"
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

	static ErrorCode *insertProblem(Problem *problem);
	static ErrorCode *deleteProblem(std::string id);


	/*
	 * Solution operations
	 */
	static Solution *searchSolution(std::string id);
	static Solution *searchAcceptedSolution(std::string problem_id);
	static std::list<Solution *> *searchSolutions(std::string problem_id);
	static std::list<Solution *> *searchSolutionsByUser(std::string user_name);
	static ErrorCode *insertSolution(Solution *solution, std::string problem_id);
	static ErrorCode *deleteSolution(std::string id);

	/*
	 * Clarification operations
	 */
	static Clarification *searchClarification(std::string id);
	static std::list<Clarification *> *searchClarifications(std::string associated_publication_id);
	static ErrorCode *insertClarification(Clarification *clarification);
	static ErrorCode *deleteClarification(std::string id);

	/*
	 * Statistical operations
	 */
	static int numberOfSolutionsByUser(std::string user_name);
	static int numberOfProblemsByUser(std::string user_name);
	static int numberOfAcceptedSolutionsByUser(std::string user_name);
	static std::list<Publication *> * getRecentActivityByUser(std::string user_name);

	/*
	 * Generalized data structure fetchers
	 */
	static Clarification* fetchClarification(cppdb::result result);
	static Problem* fetchProblem(cppdb::result result);
	static Solution* fetchSolution(cppdb::result result);
	static User* fetchUser(cppdb::result result);

};

#endif /* DATABASEINTERFACE_H_ */
