

#ifndef DATABASEINTERFACE_H_
#define DATABASEINTERFACE_H_

#include "Problem.h"
#include "Solution.h"
#include "Clarification.h"
#include "User.h"
#include <cppdb/frontend.h>
#include <list>

using namespace std;

class DatabaseInterface {
private:
	cppdb::session databaseHandler;

public:
	DatabaseInterface();
	virtual ~DatabaseInterface();

	// Problem-related queries
	Problem *getProblem(long searched_id);
	list<Problem*>* searchProblems(/* TODO: define parameters */);

	// Solution-related queries
	Solution *getSolution(long searched_id);
	list<Solution*>* searchSolutions(long problem_id);

	// Clarification-related queries
	Clarification *getClarification(long searched_id);
	list<Clarification*>* searchClarifications(long associated_publication_id);

	// User-related queries
	User *getUser(long user_name);

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

	list<Problem*>* searchProblemsbyUser(string user);

	list<Solution*>* searchSolutionsbyUser(string user);

	list<Problem*>* searchProblemsRandom(int number);

};

#endif /* DATABASEINTERFACE_H_ */
