
#ifndef ENTITYLINKER_H_
#define ENTITYLINKER_H_

// Includes
#include "../entity/Clarification.h"
#include "../entity/Problem.h"
#include "../entity/Proposal.h"
#include "../entity/Solution.h"
#include "../entity/User.h"
#include <map>
#include <string>

class EntityLinker {

private:
	std::map<std::string, User *> users;
	std::map<std::string, Problem *> problems;
	std::map<std::string, Solution *> solutions;
	std::map<std::string, Clarification *> clarifications;
	std::map<std::string, Proposal *> proposals;
	void linkProblems();
	void linkSolutions();
	void linkClarifications();
	void linkProposals();

public:
	EntityLinker();
	virtual ~EntityLinker();
	void insert(User *user);
	void insert(Problem *problem);
	void insert(Solution *solution);
	void insert(Clarification *clarification);
	void insert(Proposal *proposal);
	void linkEntities();
};

#endif /* ENTITYLINKER_H_ */
