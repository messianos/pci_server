

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
	void connectToDatabase();

public:
	DatabaseInterface();
	virtual ~DatabaseInterface();

	// Problem-related queries
	Problem *getProblem(long id);
	list<Problem>* searchProblems(/* TODO: define parameters */);

	// Solution-related queries
	Solution *getSolution(long id);
	list<Solution>* searchSolutions(long problem_id);

	// Clarification-related queries
	Clarification *getClarification(long id);
	list<Clarification>* searchClarifications(long associated_publication_id);

	// User-related queries
	User *getUser(long user_name);
};

#endif /* DATABASEINTERFACE_H_ */
