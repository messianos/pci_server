
#ifndef DATABASEINTERFACE_H_
#define DATABASEINTERFACE_H_

// Includes
#include "Clarification.h"
#include "Problem.h"
#include "Solution.h"
#include "User.h"
#include <cppdb/frontend.h>
#include <list>
#include <string>

class DatabaseInterface {

private:
	static cppdb::session database_handler;

public:
	static User *searchUser(std::string user_name);
	static Problem *searchProblem(std::string id);
	static std::list<Problem *> *searchProblems(/* TODO: define parameters */);
	static std::list<Problem *> *searchProblemsByUser(std::string user_name);
	static std::list<Problem *> *searchProblemsRandom(int amount);
	static Solution *searchSolution(std::string id);
	static Solution *searchAcceptedSolution(std::string problem_id);
	static std::list<Solution *> *searchSolutions(std::string problem_id);
	static std::list<Solution *> *searchSolutionsByUser(std::string user_name);
	static Clarification *searchClarification(std::string id);
	static std::list<Clarification *> *searchClarifications(std::string associated_publication_id);
	static void signUpUser(User *user, std::string encrypted_password);
	static void insertProblem(Problem *problem);
	static void deleteProblem(std::string id);
	static void insertSolution(Solution *solution, std::string problem_id);
	static void deleteSolution(std::string id);
	static void insertClarification(Clarification *clarification);
	static void deleteClarification(std::string id);
};

#endif /* DATABASEINTERFACE_H_ */
