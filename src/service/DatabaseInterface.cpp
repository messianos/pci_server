// Includes
#include "DatabaseInterface.h"

//TODO
#include <iostream>

// Namespaces
using namespace cppdb;
using namespace std;

// Initializations
//session DatabaseInterface::database_handler = session("mysql: host=pci-server.no-ip.org; database=pci_database; user=pci_user; password=pci_password");
session DatabaseInterface::database_handler = session(
		"mysql: host=localhost; database=pci_database; user=pci_user; password=pci_password");

// Attributes strings for objects
const string clarification_attributes = ""
		"		answer,"
		"		HEX(associated_publication_id) AS associated_publication_id,"
		"		creator_user_name,"
		"		HEX(id) AS id,"
		"		question";

const string proposal_attributes = ""
		"		content,"
		"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
		"		creator_user_name,"
		"		HEX(id) AS id,"
		"		is_anonymous,"
		"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime,"
		"		vote_balance";

const string problem_attributes = ""
		"		content,"
		"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
		"		creator_user_name,"
		"		description,"
		"		HEX(id) AS id,"
		"		is_anonymous,"
		"		is_solved,"
		"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime,"
		"		vote_balance";

const string solution_attributes = ""
		"		content,"
		"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
		"		creator_user_name,"
		"		description,"
		"		HEX(id) AS id,"
		"		is_anonymous,"
		"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime,"
		"		vote_balance";

const string user_attributes = ""
		"		birth_date,"
		"		email,"
		"		first_name,"
		"		genre,"
		"		last_name,"
		"		location,"
		"		preferences,"
		"		profile_content,"
		"		profile_picture_url,"
		"		rank,"
		"		UNIX_TIMESTAMP(sign_up_datetime) AS sign_up_datetime,"
		"		user_name";

// TODO: Define share mode on SELECT statements

bool DatabaseInterface::signInUser(string user_name, string encrypted_password) {
	string query;

	query = "   CALL sign_in_user("
			"       ?,"
			"       ?,"
			"       @out_success"
			"   )";

	database_handler << query << user_name << encrypted_password << exec;

	query = "SELECT @out_success";

	result result = database_handler << query;
	result.next();

	short int sign_in_success;
	result.fetch("@out_success", sign_in_success);

	return sign_in_success;
}

// FIXME: This may return success or fail
ErrorCode *DatabaseInterface::signUpUser(User *user, string encrypted_password) {
	string query = "	CALL sign_up_user("
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";
	// FIXME: In all methods
	try {
		database_handler << query << user->birth_date->toString("%Y-%m-%d") << user->email << user->first_name
				<< user->genre << user->last_name << user->location << user->user_name << encrypted_password << exec;
	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in signUp" << endl;
		return new ErrorCode(ErrorCode::CODE_INVALID_GENRE);
	}
	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

Clarification *DatabaseInterface::searchClarification(string id) {

	stringstream query;
	query << "	SELECT" << clarification_attributes << "	FROM Clarification"
			"	WHERE id = UNHEX(?)"
			"	LIMIT 1";

	result result = database_handler << query.str() << id;

	if (!result.next())
		// Clarification not found
		return NULL;

	return fetchClarification(result);
}

Problem *DatabaseInterface::searchProblem(string id) {

	stringstream query;
	query << "	SELECT" << problem_attributes << "	FROM Problem"
			"	WHERE id = UNHEX(?)"
			"	LIMIT 1";

	result result = database_handler << query.str() << id;

	if (!result.next())
		// Problem not found
		return NULL;

	return fetchProblem(result);
}

Solution *DatabaseInterface::searchSolution(string id) {

	stringstream query;
	query << "	SELECT" << solution_attributes << "	FROM Solution"
			"	WHERE id = UNHEX(?)"
			"	LIMIT 1";

	result result = database_handler << query.str() << id;

	if (!result.next())
		// Solution not found
		return NULL;

	return fetchSolution(result);
}

Proposal *DatabaseInterface::searchProposal(string id) {
	stringstream query;
	query << "	SELECT" << proposal_attributes << "	FROM Proposal"
			"	WHERE id = UNHEX(?)"
			"	LIMIT 1";

	result result = database_handler << query.str() << id;

	if (!result.next())
		// Proposal not found
		return NULL;

	return fetchProposal(result);
}

User *DatabaseInterface::searchUser(string user_name) {
	stringstream query;

	query << "	SELECT" << user_attributes << "	FROM User"
			"	WHERE user_name LIKE BINARY ?"
			"	LIMIT 1";

	result result = database_handler << query.str() << user_name;

	if (!result.next())
		// User not found
		return NULL;

	return fetchUser(result);
}

User *DatabaseInterface::searchUserByProblem(string problem_id) {
	stringstream query;

	query << "	SELECT"
			"	User.birth_date AS	birth_date,"
			"	User.email AS email,"
			"	User.first_name AS first_name,"
			"	User.genre AS genre,"
			"	User.last_name AS last_name,"
			"	User.location AS location,"
			"	User.preferences AS preferences,"
			"	User.profile_content AS profile_content,"
			"	User.profile_picture_url AS profile_picture_url,"
			"	User.rank AS rank,"
			"	UNIX_TIMESTAMP(User.sign_up_datetime) AS sign_up_datetime,"
			"	User.user_name AS user_name"
			"	FROM User JOIN Problem"
			"   ON Problem.creator_user_name = User.user_name "
			"	WHERE Problem.id = UNHEX(?) "
			"	LIMIT 1";

	result result = database_handler << query.str() << problem_id;

	if (!result.next())
		// problem not found
		return NULL;

	return fetchUser(result);

}

User *DatabaseInterface::searchUserBySolution(string solution_id) {
	stringstream query;

	query << "	SELECT"
			"	User.birth_date AS	birth_date,"
			"	User.email AS email,"
			"	User.first_name AS first_name,"
			"	User.genre AS genre,"
			"	User.last_name AS last_name,"
			"	User.location AS location,"
			"	User.preferences AS preferences,"
			"	User.profile_content AS profile_content,"
			"	User.profile_picture_url AS profile_picture_url,"
			"	User.rank AS rank,"
			"	UNIX_TIMESTAMP(User.sign_up_datetime) AS sign_up_datetime,"
			"	User.user_name AS user_name"
			"	FROM User JOIN Solution"
			"   ON Solution.creator_user_name = User.user_name "
			"	WHERE Solution.id = UNHEX(?) "
			"	LIMIT 1";

	result result = database_handler << query.str() << solution_id;

	if (!result.next())
		// problem not found
		return NULL;

	return fetchUser(result);

}

User *DatabaseInterface::searchUserByProposal(string proposal_id) {
	stringstream query;

	query << "	SELECT"
			"	User.birth_date AS	birth_date,"
			"	User.email AS email,"
			"	User.first_name AS first_name,"
			"	User.genre AS genre,"
			"	User.last_name AS last_name,"
			"	User.location AS location,"
			"	User.preferences AS preferences,"
			"	User.profile_content AS profile_content,"
			"	User.profile_picture_url AS profile_picture_url,"
			"	User.rank AS rank,"
			"	UNIX_TIMESTAMP(User.sign_up_datetime) AS sign_up_datetime,"
			"	User.user_name AS user_name"
			"	FROM User JOIN Proposal"
			"   ON Proposal.creator_user_name = User.user_name "
			"	WHERE Proposal.id = UNHEX(?) "
			"	LIMIT 1";

	result result = database_handler << query.str() << proposal_id;

	if (!result.next())
		// problem not found
		return NULL;

	return fetchUser(result);
}

User *DatabaseInterface::searchUserByClarification(string clarification_id) {
	stringstream query;

	query << "	SELECT"
			"	User.birth_date AS	birth_date,"
			"	User.email AS email,"
			"	User.first_name AS first_name,"
			"	User.genre AS genre,"
			"	User.last_name AS last_name,"
			"	User.location AS location,"
			"	User.preferences AS preferences,"
			"	User.profile_content AS profile_content,"
			"	User.profile_picture_url AS profile_picture_url,"
			"	User.rank AS rank,"
			"	UNIX_TIMESTAMP(User.sign_up_datetime) AS sign_up_datetime,"
			"	User.user_name AS user_name"
			"	FROM User JOIN Clarification"
			"   ON Clarification.creator_user_name = User.user_name "
			"	WHERE Clarification.id = UNHEX(?) "
			"	LIMIT 1";

	result result = database_handler << query.str() << clarification_id;

	if (!result.next())
		// problem not found
		return NULL;

	return fetchUser(result);
}

list<Problem *> *DatabaseInterface::searchProblems(/* TODO: define parameters */) {
	// TODO
	return NULL;
}

list<Problem *> *DatabaseInterface::searchProblemsByUser(string user_name) {

	stringstream query;
	query << "	SELECT" << problem_attributes << "	FROM Problem"
			"	WHERE creator_user_name LIKE BINARY ?";

	result result = database_handler << query.str() << user_name;

	list<Problem *> *problem_list = new list<Problem *>();

	while (result.next()) {

		problem_list->push_back(fetchProblem(result));
	}

	return problem_list;
}

Solution *DatabaseInterface::searchAcceptedSolution(string problem_id) {
	string query = ""
			"	SELECT"
			"		Solution.content AS content,"
			"		UNIX_TIMESTAMP(Solution.creation_datetime) AS creation_datetime,"
			"		Solution.creator_user_name AS creator_user_name,"
			"		Solution.description AS description,"
			"		HEX(Solution.id) AS id,"
			"		Solution.is_anonymous AS is_anonymous,"
			"		UNIX_TIMESTAMP(Solution.last_edition_datetime) AS last_edition_datetime,"
			"		Solution.vote_balance AS vote_balance"
			"	FROM"
			"		problem_solved"
			"		JOIN"
			"		Solution"
			"	ON problem_solved.solution_id = Solution.id"
			"	WHERE"
			"		problem_id = UNHEX(?)";

	result result = database_handler << query << problem_id;

	if (!result.next())
		// Solution not found
		return NULL;

	return fetchSolution(result);
}

list<Problem *> *DatabaseInterface::searchProblemsRandom(int amount) {

	stringstream query;
	query << "	SELECT" << problem_attributes << "	FROM Problem"
			"	ORDER BY RAND()"
			"	LIMIT ?";

	result result = database_handler << query.str() << amount;

	list<Problem *> *problem_list = new list<Problem *>();

	while (result.next()) {
		problem_list->push_back(fetchProblem(result));
	}

	return problem_list;
}

list<Problem *> *DatabaseInterface::searchProblemsUnsolved(int amount) {

	stringstream query;
	query << "	SELECT" << problem_attributes << "	FROM Problem"
			"	WHERE"
			"		is_solved = 0"
			"	LIMIT ?";

	result result = database_handler << query.str() << amount;

	list<Problem *> *problem_list = new list<Problem *>();

	while (result.next()) {
		problem_list->push_back(fetchProblem(result));
	}

	return problem_list;
}

list<Problem *> *DatabaseInterface::searchProblemsLatest(int amount) {
	stringstream query;
	query << "	SELECT" << problem_attributes << "	FROM Problem"
			"	ORDER BY creation_datetime DESC"
			"	LIMIT ?";

	result result = database_handler << query.str() << amount;

	list<Problem *> *problem_list = new list<Problem *>();

	while (result.next()) {
		problem_list->push_back(fetchProblem(result));
	}

	problem_list->sort(&Publication::publicationComparator);

	while (problem_list->size() > amount) {
		problem_list->pop_back();
	}

	return problem_list;
}

Problem *DatabaseInterface::searchProblemByAcceptedSolution(string solution_id) {
	string query = ""
			"	SELECT"
			"		Problem.content AS content,"
			"		UNIX_TIMESTAMP(Problem.creation_datetime) AS creation_datetime,"
			"		Problem.creator_user_name AS creator_user_name,"
			"		Solution.description AS description,"
			"		HEX(Problem.id) AS id,"
			"		Problem.is_anonymous AS is_anonymous,"
			"		Problem.is_solved AS is_solved"
			"		UNIX_TIMESTAMP(Problem.last_edition_datetime) AS last_edition_datetime,"
			"		Problem.vote_balance AS vote_balance"
			"	FROM"
			"		problem_solved"
			"		JOIN"
			"		Problem"
			"	ON problem_solved.problem_id = Problem.id"
			"	WHERE"
			"		solution_id = UNHEX(?)";

	result result = database_handler << query << solution_id;

	if (!result.next())
		// Solution not found
		return NULL;

	return fetchProblem(result);
}

ErrorCode * DatabaseInterface::insertProblem(Problem *problem) {
	string query = "	CALL insert_problem("
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << problem->content << problem->creator_user_name << problem->description << problem->id
			<< problem->is_anonymous << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode * DatabaseInterface::deleteProblem(string id) {
	string query = "CALL delete_problem(?)";
	database_handler << query << id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

// FIXME: READ FROM problems_solved
list<Solution *> *DatabaseInterface::searchSolutions(string problem_id) {

	string query = "	SELECT"
			"		Solution.content AS content,"
			"		UNIX_TIMESTAMP(Solution.creation_datetime) AS creation_datetime,"
			"		Solution.creator_user_name AS creator_user_name,"
			"		Solution.description AS description,"
			"		HEX(Solution.id) AS id,"
			"		Solution.is_anonymous AS is_anonymous,"
			"		UNIX_TIMESTAMP(Solution.last_edition_datetime) AS last_edition_datetime,"
			"		Solution.vote_balance"
			"	FROM"
			"		Problem"
			"		JOIN"
			"		problem_solutions"
			"		JOIN"
			"		Solution"
			"	ON"
			"		Problem.id = problem_solutions.problem_id"
			"		AND"
			"		Solution.id = problem_solutions.solution_id"
			"	WHERE Problem.id = UNHEX(?)";

	result result = database_handler << query << problem_id;

	list<Solution *> *solution_list = new list<Solution *>();

	while (result.next()) {
		solution_list->push_back(fetchSolution(result));
	}

	return solution_list;
}

list<Solution *> *DatabaseInterface::searchSolutionsByUser(string user_name) {

	stringstream query;
	query << "	SELECT" << solution_attributes << "	FROM Solution"
			"	WHERE creator_user_name LIKE BINARY ?";

	result result = database_handler << query.str() << user_name;

	list<Solution *> *solution_list = new list<Solution *>();

	while (result.next()) {
		solution_list->push_back(fetchSolution(result));
	}

	return solution_list;
}

ErrorCode * DatabaseInterface::insertSolution(Solution *solution, string problem_id) {
	string query = "	CALL insert_solution("
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << problem_id << solution->content << solution->creator_user_name << solution->description
			<< solution->id << solution->is_anonymous << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode * DatabaseInterface::deleteSolution(string id) {
	string query = "CALL delete_solution(?)";
	database_handler << query << id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

list<Proposal *> *DatabaseInterface::searchProposals(string solution_id) {
	string query = "	SELECT"
			"		Proposal.content AS content,"
			"		UNIX_TIMESTAMP(Proposal.creation_datetime) AS creation_datetime,"
			"		Proposal.creator_user_name AS creator_user_name,"
			"		HEX(Proposal.id) AS id,"
			"		Proposal.is_anonymous AS is_anonymous,"
			"		UNIX_TIMESTAMP(Proposal.last_edition_datetime) AS last_edition_datetime,"
			"		Proposal.vote_balance"
			"	FROM"
			"		Solution"
			"		JOIN"
			"		solution_proposals"
			"		JOIN"
			"		Proposal"
			"	ON"
			"		Solution.id = solution_proposals.solution_id"
			"		AND"
			"		Proposal.id = solution_proposals.proposal_id"
			"	WHERE Solution.id = UNHEX(?)";

	result result = database_handler << query << solution_id;

	list<Proposal *> *proposal_list = new list<Proposal *>();

	while (result.next()) {
		proposal_list->push_back(fetchProposal(result));
	}

	return proposal_list;
}

list<Proposal *> *DatabaseInterface::searchProposalsByUser(string user_name) {

	stringstream query;
	query << "	SELECT" << proposal_attributes << "	FROM Proposal"
			"	WHERE creator_user_name LIKE BINARY ?";

	result result = database_handler << query.str() << user_name;

	list<Proposal *> *proposal_list = new list<Proposal *>();

	while (result.next()) {
		proposal_list->push_back(fetchProposal(result));
	}

	return proposal_list;
}

ErrorCode *DatabaseInterface::insertProposal(Proposal *proposal, string solution_id) {
	string query = "	CALL insert_proposal("
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << solution_id << proposal->content << proposal->creator_user_name << proposal->id
			<< proposal->is_anonymous << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *DatabaseInterface::deleteProposal(string id) {
	string query = "CALL delete_proposal(?)";
	database_handler << query << id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

list<Clarification *> *DatabaseInterface::searchClarifications(string associated_publication_id) {

	stringstream query;
	query << "	SELECT" << clarification_attributes << "	FROM Clarification"
			"	WHERE associated_publication_id = UNHEX(?)";

	result result = database_handler << query.str() << associated_publication_id;

	list<Clarification *> *clarification_list = new list<Clarification *>();

	while (result.next()) {
		clarification_list->push_back(fetchClarification(result));
	}

	return clarification_list;
}

ErrorCode * DatabaseInterface::insertClarification(Clarification *clarification) {
	string query = "	CALL insert_clarification("
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << clarification->associated_publication_id << clarification->creator_user_name
			<< clarification->id << clarification->question << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode * DatabaseInterface::deleteClarification(string id) {
	string query = "CALL delete_clarification(?)";
	database_handler << query << id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

int DatabaseInterface::numberOfSolutionsByUser(string user_name) {
	string query = ""
			"	SELECT"
			"		count(1) AS num_solutions"
			"	FROM"
			"		Solution"
			"	WHERE"
			"		creator_user_name = ?";

	result result = database_handler << query << user_name;

	int to_return;
	result.next();
	result.fetch("num_solutions", to_return);

	return to_return;
}

int DatabaseInterface::numberOfProblemsByUser(string user_name) {
	string query = ""
			"	SELECT"
			"		count(1) AS num_problems"
			"	FROM"
			"		Problem"
			"	WHERE"
			"		creator_user_name = ?";

	result result = database_handler << query << user_name;

	int to_return;
	result.next();
	result.fetch("num_problems", to_return);

	return to_return;
}

int DatabaseInterface::numberOfAcceptedSolutionsByUser(string user_name) {
	int number = 0;

	string query = ""
			"	SELECT"
			"		count(1) AS num_accepted_solutions"
			"	FROM"
			"		Solution"
			"		JOIN"
			"		problem_solved"
			"		ON Solution.id = problem_solved.solution_id"
			"	WHERE"
			"	Solution.creator_user_name = ?";

	result result = database_handler << query << user_name;

	if (!result.next())
		return 0;

	result.fetch("num_accepted_solutions", number);

	return number;
}

// TODO: Parametrize amount
list<Publication *> * DatabaseInterface::getRecentActivityByUser(string user_name) {

	stringstream problem_query;
	problem_query << ""
			"	SELECT"
			"		" << problem_attributes << ""
			"	FROM"
			"		Problem"
			"	WHERE"
			"		creator_user_name = ?"
			"	ORDER BY last_edition_datetime DESC"
			"	LIMIT 10";
	stringstream solution_query;
	solution_query << ""
			"	SELECT"
			"		" << solution_attributes << ""
			"	FROM"
			"		Solution"
			"	WHERE"
			"		creator_user_name = ?"
			"	ORDER BY last_edition_datetime DESC"
			"	LIMIT 10";

	result problem_result = database_handler << problem_query.str() << user_name;
	result solution_result = database_handler << solution_query.str() << user_name;

	list<Publication *>* publication_list = new list<Publication*>();

	while (problem_result.next()) {
		publication_list->push_back(fetchProblem(problem_result));
	}

	while (solution_result.next()) {
		publication_list->push_back(fetchSolution(solution_result));
	}

	publication_list->sort(&Publication::publicationComparator);

	// FIXME: Unefficient? WARN: It's also used in other problem searches
	while (publication_list->size() > 10) {
		publication_list->pop_back();
	}

	return publication_list;
}

Clarification* DatabaseInterface::fetchClarification(result result) {

	Clarification *clarification = new Clarification();
	try {
		result.fetch("answer", clarification->answer);
		result.fetch("associated_publication_id", clarification->associated_publication_id);
		result.fetch("creator_user_name", clarification->creator_user_name);
		result.fetch("id", clarification->id);
		result.fetch("question", clarification->question);
	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in fetchClarification" << endl;
		return NULL;
	}

	return clarification;
}

Problem* DatabaseInterface::fetchProblem(result result) {

	Problem *problem = new Problem();
	try {
		time_t timestamp;

		result.fetch("content", problem->content);
		result.fetch("creation_datetime", timestamp);
		problem->creation_datetime = new Datetime(timestamp);
		result.fetch("creator_user_name", problem->creator_user_name);
		result.fetch("description", problem->description);
		result.fetch("id", problem->id);
		result.fetch("is_anonymous", problem->is_anonymous);
		result.fetch("is_solved", problem->is_solved);
		result.fetch("last_edition_datetime", timestamp);
		problem->last_edition_datetime = new Datetime(timestamp);
		result.fetch("vote_balance", problem->vote_balance);

	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in fetchProblem" << endl;
		return NULL;
	}

	return problem;
}

Solution* DatabaseInterface::fetchSolution(result result) {

	Solution *solution = new Solution();
	try {
		time_t timestamp;

		result.fetch("content", solution->content);
		result.fetch("creation_datetime", timestamp);
		solution->creation_datetime = new Datetime(timestamp);
		result.fetch("creator_user_name", solution->creator_user_name);
		result.fetch("description", solution->description);
		result.fetch("id", solution->id);
		result.fetch("is_anonymous", solution->is_anonymous);
		result.fetch("last_edition_datetime", timestamp);
		solution->last_edition_datetime = new Datetime(timestamp);
		result.fetch("vote_balance", solution->vote_balance);

	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in fetchSolution" << endl;
		return NULL;
	}

	return solution;
}

Proposal *DatabaseInterface::fetchProposal(result result) {
	Proposal *proposal = new Proposal();
	try {
		time_t timestamp;

		result.fetch("content", proposal->content);
		result.fetch("creation_datetime", timestamp);
		proposal->creation_datetime = new Datetime(timestamp);
		result.fetch("creator_user_name", proposal->creator_user_name);
		result.fetch("id", proposal->id);
		result.fetch("is_anonymous", proposal->is_anonymous);
		result.fetch("last_edition_datetime", timestamp);
		proposal->last_edition_datetime = new Datetime(timestamp);
		result.fetch("vote_balance", proposal->vote_balance);
		//Description always is null ('cause proposal doesn't have)
		proposal->description = "";

	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in fetchSolution" << endl;
		return NULL;
	}

	return proposal;
}

ErrorCode* DatabaseInterface::voteProblem(string problem_id, string user_name, bool is_positive) {
	string query = "	CALL vote_problem("
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << problem_id << user_name << is_positive << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode* DatabaseInterface::setAcceptedSolution(string problem_id, string solution_id) {
	string query = "	CALL set_accepted_solution("
			"		?,"
			"		?"
			"	)";

	database_handler << query << problem_id << solution_id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode* DatabaseInterface::unsetAcceptedSolution(string problem_id) {
	string query = "	CALL unset_accepted_solution("
			"		?"
			"	)";

	database_handler << query << problem_id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

int DatabaseInterface::getProblemVoteBalance(string problem_id) {
	int vote_balance;
	string query = ""
			"SELECT"
			"	vote_balance"
			"FROM"
			"	Problem"
			"WHERE"
			"	id = UNEX(?)";

	result result = database_handler << query << problem_id;

	if(!result.next())
		return 0;

	result.fetch("vote_balance", vote_balance);

	return vote_balance;
}

int DatabaseInterface::getSolutionVoteBalance(string solution_id) {
	int vote_balance;
	string query = ""
			"SELECT"
			"	vote_balance"
			"FROM"
			"	Solution"
			"WHERE"
			"	id = UNEX(?)";

	result result = database_handler << query << solution_id;

	if(!result.next())
		return 0;

	result.fetch("vote_balance", vote_balance);

	return vote_balance;
}

User* DatabaseInterface::fetchUser(result result) {

	User *user = new User();
	try {
		string formatted_date;
		time_t timestamp;

		result.fetch("birth_date", formatted_date);
		user->birth_date = new Date("%Y-%m-%d", formatted_date);
		result.fetch("email", user->email);
		result.fetch("first_name", user->first_name);
		result.fetch("genre", user->genre);
		result.fetch("last_name", user->last_name);
		result.fetch("location", user->location);
		result.fetch("sign_up_datetime", timestamp);
		user->sign_up_datetime = new Datetime(timestamp);

		result.fetch("user_name", user->user_name);

		result.fetch("rank", user->rank);
		result.fetch("profile_content", user->profile_content);
		result.fetch("preferences", user->preferences);

		result.fetch("profile_picture_url", user->profile_picture_url);

	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in fetchUser" << endl;
		return NULL;
	}

	return user;
}

