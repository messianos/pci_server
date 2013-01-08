

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

	/*Insert problem into de database*/
	void insertProblem(Problem *problem);

	/*Insert solution into de database*/
	void insertSolution(Solution *solution);

	/*Insert clarification into de database*/
	void insertClarification(Clarification *clarification);

	/*remove problem with de id delete_id*/
	void removeProblem (long deleted_id);

	/*remove solution with de id delete_id*/
	void removeSolution(long deleted_id);

	/*remove clarification with de id delete_id*/
	void removeClarification(long deleted_id);
};

#endif /* DATABASEINTERFACE_H_ */
