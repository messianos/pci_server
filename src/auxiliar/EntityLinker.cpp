
// Includes
#include "EntityLinker.h"

// Namespaces
using namespace std;

void EntityLinker::linkProblems() {
	for (map<string, Problem *>::iterator problem_iterator = problems.begin(); problem_iterator != problems.end(); ++problem_iterator) {
		Problem *problem = problem_iterator->second;
		
		map<string, User *>::iterator user_iterator = users.find(problem->creator_user_name);
		if(user_iterator != users.end())
			problem->link_user = user_iterator->second;
	}
}

void EntityLinker::linkSolutions() {
	for (map<string, Solution *>::iterator solution_iterator = solutions.begin(); solution_iterator != solutions.end(); ++solution_iterator) {
		Solution *solution = solution_iterator->second;
		
		map<string, User *>::iterator user_iterator = users.find(solution->creator_user_name);
		if(user_iterator != users.end())
			solution->link_user = user_iterator->second;
		
		map<string, Problem *>::iterator problem_iterator = problems.find(solution->problem_id);
		if(problem_iterator != problems.end())
			solution->link_problem = problem_iterator->second;
	}
}

void EntityLinker::linkClarifications() {
	for (map<string, Clarification *>::iterator clarification_iterator = clarifications.begin(); clarification_iterator != clarifications.end(); ++clarification_iterator) {
		Clarification *clarification = clarification_iterator->second;
		
		map<string, User *>::iterator user_iterator = users.find(clarification->creator_user_name);
		if(user_iterator != users.end())
			clarification->link_user = user_iterator->second;
		
		string publication_id = clarification->publication_id;
		if (publication_id[1] == '0') {
			// publication_id has the prefix "50"
			map<string, Problem *>::iterator problem_iterator = problems.find(publication_id);
			if(problem_iterator != problems.end())
				clarification->link_publication = problem_iterator->second;
		} else {
			// publication_id has the prefix "53"
			map<string, Solution *>::iterator solution_iterator = solutions.find(publication_id);
			if(solution_iterator != solutions.end())
				clarification->link_publication = solution_iterator->second;
		}
	}
}

void EntityLinker::linkProposals() {
	for (map<string, Proposal *>::iterator proposal_iterator = proposals.begin(); proposal_iterator != proposals.end(); ++proposal_iterator) {
		Proposal *proposal = proposal_iterator->second;
		
		map<string, User *>::iterator user_iterator = users.find(proposal->creator_user_name);
		if(user_iterator != users.end())
			proposal->link_user = user_iterator->second;
		
		map<string, Solution *>::iterator solution_iterator = solutions.find(proposal->solution_id);
		if(solution_iterator != solutions.end())
			proposal->link_solution = solution_iterator->second;
	}
}

EntityLinker::EntityLinker() {
	// TODO: initialize attributes with default values
}

EntityLinker::~EntityLinker() {}

void EntityLinker::insert(User *user) {
	users[user->user_name] = user;
}

void EntityLinker::insert(Problem *problem) {
	problems[problem->id] = problem;
}

void EntityLinker::insert(Solution *solution) {
	solutions[solution->id] = solution;
}

void EntityLinker::insert(Clarification *clarification) {
	clarifications[clarification->id] = clarification;
}

void EntityLinker::insert(Proposal *proposal) {
	proposals[proposal->id] = proposal;
}

void EntityLinker::linkEntities() {
	linkProblems();
	linkSolutions();
	linkClarifications();
	linkProposals();
}
