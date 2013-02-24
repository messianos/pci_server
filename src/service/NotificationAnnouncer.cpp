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
set<string, NotificationAnnouncer::classcomp> *NotificationAnnouncer::postProposal(string user_name,string solution_id){
	set<string, NotificationAnnouncer::classcomp> *interestedUser = new set<string, NotificationAnnouncer::classcomp>();
	string solution_creator = DatabaseInterface::searchSolution(solution_id)->creator_user_name;
	interestedUser->insert(solution_creator);

	list<Proposal *> *proposalPostList = DatabaseInterface::searchProposals(solution_id);
	list<Proposal *>::iterator iteration;

	//For each user that post a proposal in the solution!
	for(iteration = proposalPostList->begin(); iteration != proposalPostList->end(); iteration++){
		string interested_user = (*iteration)->creator_user_name;
		if (interested_user.compare(user_name) != 0)
			interestedUser->insert(interested_user);
	}

	return interestedUser;
}

/*
 * Return a list of interested users about posting a clarification in a problem
 * who is the creator of the problem
 */
set<string,NotificationAnnouncer::classcomp > *NotificationAnnouncer::postClarificationInProblem(string problem_id){
	set<string,NotificationAnnouncer::classcomp> *interestedUser = new set<string,NotificationAnnouncer::classcomp>();
	string problem_creator = DatabaseInterface::searchProblem(problem_id)->creator_user_name;
	interestedUser->insert(problem_creator);

	return interestedUser;
}

/*
 * Return a list of interested users about posting a clarification in a solution
 * Interested: who is the creator of the solution
 */
set<string,NotificationAnnouncer::classcomp> *NotificationAnnouncer::postClarificationInSolution(string solution_id){
	set<string,NotificationAnnouncer::classcomp> *interestedUser = new set<string,NotificationAnnouncer::classcomp>();
	string solution_creator = DatabaseInterface::searchSolution(solution_id)->creator_user_name;
	interestedUser->insert(solution_creator);

	return interestedUser;
}

/*
 * Return a list of interested users about replying a clarification in a publication
 * They are who is the creator of the clarification. 2)other clarification poster in the same publication ?
 */
set<string,NotificationAnnouncer::classcomp> *NotificationAnnouncer::replyClarification(string id){
	set<string,NotificationAnnouncer::classcomp> *interestedUser = new set<string,NotificationAnnouncer::classcomp>();
	Clarification *clarification = DatabaseInterface::searchClarification(id);
	/*
	string clarification_creator = clarification->creator_user_name;
	if (clarification_creator != NULL)
			interestedUser->insert(clarification_creator);*/

	string associated_publication_id = clarification->associated_publication_id;

	list<Clarification *> *clarificationPostList = DatabaseInterface::searchClarifications(associated_publication_id);
	list<Clarification *>::iterator iteration;

	//For each user that post a clarification in the solution!
	for(iteration = clarificationPostList->begin(); iteration != clarificationPostList->end(); iteration++){
			interestedUser->insert((*iteration)->creator_user_name);
	}

	return interestedUser;
}


/*
 * Return a list of interested users about voting a problem
 * This is 1)the creator of the problem
 */
set<string,NotificationAnnouncer::classcomp> *NotificationAnnouncer::voteProblem(string problem_id){
	set<string,NotificationAnnouncer::classcomp> *interestedUser = new set<string,NotificationAnnouncer::classcomp>();
	string problem_creator = DatabaseInterface::searchProblem(problem_id)->creator_user_name;
	interestedUser->insert(problem_creator);
	return interestedUser;
}

/*
 * Return a list of interested users about voting a solution
 * This is 1)the creator of the solution
 */
set<string,NotificationAnnouncer::classcomp> *NotificationAnnouncer::voteSolution(string solution_id){
	set<string,NotificationAnnouncer::classcomp> *interestedUser = new set<string,NotificationAnnouncer::classcomp>();
	string solution_creator = DatabaseInterface::searchSolution(solution_id)->creator_user_name;
	interestedUser->insert(solution_creator);
	return interestedUser;
}

/*
 * Return a list of interested users about voting a proposal
 * This is 1)the creator of the proposal
 */
set<string,NotificationAnnouncer::classcomp> *NotificationAnnouncer::voteProposal(string proposal_id){
	set<string,NotificationAnnouncer::classcomp> *interestedUser = new set<string,NotificationAnnouncer::classcomp>();
	string proposal_creator = DatabaseInterface::searchProposal(proposal_id)->creator_user_name;
	interestedUser->insert(proposal_creator);
	return interestedUser;
}


//TODO changes in policy??
/*
 * Return a list of interested users about accepting a solution as problem solution
 * They are 1) the creator of the solution. 2) other solution posters in the problem. 3) who vote the solution
 */
set<string,NotificationAnnouncer::classcomp> *NotificationAnnouncer::acceptSolution(string solution_id){
	set<string,NotificationAnnouncer::classcomp> *interestedUser = new set<string,NotificationAnnouncer::classcomp>();
	/*
	string solution_creator = DatabaseInterface::searchSolution(solution_id)->creator_user_name;
	interestedUser->insert(solution_creator);*/

	string associated_problem_id = DatabaseInterface::searchProblemByAcceptedSolution(solution_id)->id;
	string problem_creator_user_name = DatabaseInterface::searchProblem(associated_problem_id)->creator_user_name;

	list<Solution *> *solutionPostList = DatabaseInterface::searchSolutions(associated_problem_id);
	list<Solution *>::iterator iteration;

	//For each user that post a solution in the problem!
	for(iteration = solutionPostList->begin(); iteration != solutionPostList->end(); iteration++){
		string solution_poster_user_name = (*iteration)->creator_user_name;
		if (solution_poster_user_name.compare(problem_creator_user_name) != 0)
			interestedUser->insert(solution_poster_user_name);
	}
	//For each user who post the solution

	return interestedUser;
}




