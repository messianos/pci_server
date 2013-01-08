

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

using namespace std;

class DatabaseInterface {

private:
	static cppdb::session database_handler;

public:
	static User *searchUser(std::string user_name);
	static Problem *searchProblem(std::string id);
	static std::list<Problem *> *searchProblems(/* TODO: define parameters */);
	static Solution *searchSolution(std::string id);
	static Solution *searchAcceptedSolution(std::string problem_id);
	static std::list<Solution *> *searchSolutions(std::string problem_id);
	static Clarification *searchClarification(std::string id);
	static std::list<Clarification *> *searchClarifications(std::string associated_publication_id);

	std::list<Problem *> *searchProblemsByUser(std::string user_name);
	std::list<Solution *> *searchSolutionsByUser(std::string user_name);
	std::list<Problem *> *searchProblemsRandom(int number);

	void insertUser(User *user);
	void insertProblem(Problem *problem);
	void insertSolution(Solution *solution);
	void insertClarification(Clarification *clarification);
	void deleteProblem(std::string id);
	void deleteSolution(std::string id);
	void deleteClarification(std::string id);
};

#endif /* DATABASEINTERFACE_H_ */
