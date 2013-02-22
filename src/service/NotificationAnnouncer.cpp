#include "NotificationAnnouncer.h"


using namespace std;

NotificationAnnouncer::NotificationAnnouncer() {
	// TODO Auto-generated constructor stub

}

NotificationAnnouncer::~NotificationAnnouncer() {
	// TODO Auto-generated destructor stub
}

/*
 * Return a list of interested users about posting a solution in a problem which id is problem_id
 * they are 1) the problem creator. 2) the users that posted a solution in the problem.
 */
set<string, NotificationAnnouncer::classcomp> *NotificationAnnouncer::postSolution(string user_name, string problem_id){

	set<string,classcomp> *interestedUser = new set<string,classcomp>();
	string problem_creator = DatabaseInterface::searchProblem(problem_id)->creator_user_name;
	if (problem_creator.compare(user_name) != 0)
		interestedUser->insert(problem_creator);

	list<Solution *> *solutionPostList = DatabaseInterface::searchSolutions(problem_id);
	list<Solution *>::iterator iteration;

	//For each user that post a solution in the problem!
	for(iteration = solutionPostList->begin(); iteration != solutionPostList->end(); iteration++){
		string user = (*iteration)->creator_user_name;
		if (user.compare(user_name) != 0)
			interestedUser->insert(user);
	}

	return interestedUser;
}

/*
 * Return a list of interested users about posting of a proposal in a solution
 * They are 1) The creator of the solution 2) Users that post a proposal in the same solution
 */
list<User *> *NotificationAnnouncer::postProposal(string solution_id){
	list<User *> *interestedUser = new list<User *>();
	User * solution_creator = DatabaseInterface::searchUserBySolution(solution_id);
	if (solution_creator != NULL)
		interestedUser->push_back(solution_creator);

	list<Proposal *> *proposalPostList = DatabaseInterface::searchProposals(solution_id);
	list<Proposal *>::iterator iteration;

	//For each user that post a proposal in the solution!
	for(iteration = proposalPostList->begin(); iteration != proposalPostList->end(); iteration++){
		interestedUser->push_back(DatabaseInterface::searchUserByProposal( (*iteration)->id ) );
	}

	return interestedUser;
}

/*
 * Return a list of interested users about posting a clarification in a problem
 * who is the creator of the problem
 */
list<User *> *NotificationAnnouncer::postClarificationInProblem(string problem_id){
	list<User *> *interestedUser = new list<User *>();
	User* problem_creator = DatabaseInterface::searchUserByProblem(problem_id);
	if (problem_creator!= NULL)
		interestedUser->push_back(problem_creator);

	return interestedUser;
}

/*
 * Return a list of interested users about posting a clarification in a solution
 * Interested: who is the creator of the solution
 */
list<User *> *NotificationAnnouncer::postClarificationInSolution(string solution_id){
	list<User *> *interestedUser = new list<User *>();
	User *solution_creator = DatabaseInterface::searchUserBySolution(solution_id);
	if (solution_creator != NULL)
	interestedUser->push_back(solution_creator);

	return interestedUser;
}

/*
 * Return a list of interested users about replying a clarification in a publication
 * They are who is the creator of the clarification. 2)other clarification poster in the same publication ?
 */
list<User *> *NotificationAnnouncer::replyClarification(string id){
	list<User *> *interestedUser = new list<User *>();
	User *clarification_creator = DatabaseInterface::searchUserByClarification(id);
	if (clarification_creator != NULL)
			interestedUser->push_back(clarification_creator);

	string associated_publication_id = DatabaseInterface::searchClarification(id)->associated_publication_id;

	list<Clarification *> *clarificationPostList = DatabaseInterface::searchClarifications(associated_publication_id);
	list<Clarification *>::iterator iteration;

	//For each user that post a proposal in the solution!
	for(iteration = clarificationPostList->begin(); iteration != clarificationPostList->end(); iteration++){
		interestedUser->push_back(DatabaseInterface::searchUserByClarification( (*iteration)->id ) );
	}

	return interestedUser;
}


/*
 * Return a list of interested users about voting a problem
 * This is 1)the creator of the problem
 */
list<User *> *NotificationAnnouncer::voteProblem(string problem_id){
	list<User *> *interestedUser = new list<User *>();
	User *problem_creator = DatabaseInterface::searchUserByProblem(problem_id);
	if (problem_creator != NULL)
		interestedUser->push_back(problem_creator);
	return interestedUser;
}

/*
 * Return a list of interested users about voting a solution
 * This is 1)the creator of the solution
 */
list<User *> *NotificationAnnouncer::voteSolution(string solution_id){
	list<User *> *interestedUser = new list<User *>();
	User *solution_creator = DatabaseInterface::searchUserBySolution(solution_id);
	if (solution_creator != NULL)
		interestedUser->push_back(solution_creator);
	return interestedUser;
}

/*
 * Return a list of interested users about voting a proposal
 * This is 1)the creator of the proposal
 */
list<User *> *NotificationAnnouncer::voteProposal(string proposal_id){
	list<User *> *interestedUser = new list<User *>();
	User *proposal_creator = DatabaseInterface::searchUserByProposal(proposal_id);
	if (proposal_creator != NULL)
		interestedUser->push_back(proposal_creator);
	return interestedUser;
}


//TODO changes in policy??
/*
 * Return a list of interested users about accepting a solution as problem solution
 * They are 1) the creator of the solution. 2) other solution posters in the problem. 3) who vote the solution
 */
list<User *> *NotificationAnnouncer::acceptSolution(string solution_id){
	list<User *> *interestedUser = new list<User *>();
	User *solution_creator = DatabaseInterface::searchUserBySolution(solution_id);
	if (solution_creator != NULL)
		interestedUser->push_back(solution_creator);

	string associated_problem_id = DatabaseInterface::searchProblemByAcceptedSolution(solution_id)->id;

	list<Solution *> *solutionPostList = DatabaseInterface::searchSolutions(associated_problem_id);
	list<Solution *>::iterator iteration;

	//For each user that post a solution in the problem!
	for(iteration = solutionPostList->begin(); iteration != solutionPostList->end(); iteration++){
		interestedUser->push_back(DatabaseInterface::searchUserBySolution( (*iteration)->id ) );
	}




	//For each user who post the solution



	return interestedUser;
}




