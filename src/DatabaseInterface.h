

#ifndef DATABASEINTERFACE_H_
#define DATABASEINTERFACE_H_

#include "Problem.h"
#include "Solution.h"
#include "Clarification.h"
#include "User.h"

class DatabaseInterface {
public:
	DatabaseInterface();
	virtual ~DatabaseInterface();

	// Problem-related queries
	Problem getProblem(long id);
	/* TODO: define returned data structure */ searchProblems(/* TODO: define parameters */);

	// Solution-related queries
	Solution getSolution(long id);
	/* TODO: define returned data structure */ searchSolutions(long problem_id);

	// Clarification-related queries
	Clarification getClarification(long id);
	/* TODO: define returned data structure */ searchClarifications(long associated_publication_id);

	// User-related queries
	User getUser(long user_name);
};

#endif /* DATABASEINTERFACE_H_ */
