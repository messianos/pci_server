// Includes
#include "DatabaseInterface.h"
#include <boost/cast.hpp>
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
		"		HEX(publication_id) AS publication_id,"
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
		"		HEX(problem_id) AS problem_id,"
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

const string notification_attributes = ""
		"		user_name,"
		"		seen,"
		"		originator_user_name,"
		"		url,"
		"		event_code";

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
void DatabaseInterface::signUpUser(User *user, string encrypted_password) {
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
	}
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
			"		HEX(Solution.problem_id) AS problem_id,"
			"		Solution.vote_balance AS vote_balance"
			"	FROM"
			"		problem_solved"
			"		JOIN"
			"		Solution"
			"	ON problem_solved.solution_id = Solution.id"
			"	WHERE"
			"		problem_solved.problem_id = UNHEX(?)";

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

	while (problem_list->size() > (unsigned int) amount) {
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

void  DatabaseInterface::insertProblem(Problem *problem) {
	string query = "	CALL insert_problem("
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << problem->content << problem->creator_user_name << problem->description << problem->id
			<< problem->is_anonymous << exec;
}

void  DatabaseInterface::deleteProblem(string id) {
	string query = "CALL delete_problem(?)";
	database_handler << query << id << exec;
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
			"		HEX(Solution.problem_id) AS problem_id,"
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

void  DatabaseInterface::insertSolution(Solution *solution, string problem_id) {
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
}

void  DatabaseInterface::deleteSolution(string id) {
	string query = "CALL delete_solution(?)";
	database_handler << query << id << exec;
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

void DatabaseInterface::insertProposal(Proposal *proposal, string solution_id) {
	string query = "	CALL insert_proposal("
			"		?,"
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << solution_id << proposal->content << proposal->creator_user_name << proposal->id
			<< proposal->is_anonymous << exec;
}

void DatabaseInterface::deleteProposal(string id) {
	string query = "CALL delete_proposal(?)";
	database_handler << query << id << exec;
}

list<Clarification *> *DatabaseInterface::searchClarifications(string publication_id) {

	stringstream query;
	query << "	SELECT" << clarification_attributes << "	FROM Clarification"
			"	WHERE publication_id = UNHEX(?)";

	result result = database_handler << query.str() << publication_id;

	list<Clarification *> *clarification_list = new list<Clarification *>();

	while (result.next()) {
		clarification_list->push_back(fetchClarification(result));
	}

	return clarification_list;
}

void  DatabaseInterface::insertClarification(Clarification *clarification) {
	string query = "	CALL insert_clarification("
			"		?,"
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << clarification->publication_id << clarification->creator_user_name << clarification->id
			<< clarification->question << exec;
}

void  DatabaseInterface::deleteClarification(string id) {
	string query = "CALL delete_clarification(?)";
	database_handler << query << id << exec;
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
		result.fetch("publication_id", clarification->publication_id);
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
		result.fetch("problem_id", solution->problem_id);
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
		result.fetch("solution_id", proposal->solution_id);
		result.fetch("vote_balance", proposal->vote_balance);

	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in fetchSolution" << endl;
		return NULL;
	}

	return proposal;
}

void DatabaseInterface::voteProblem(string problem_id, string user_name, bool is_positive) {
	string query = "	CALL vote_problem("
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << problem_id << user_name << is_positive << exec;
}

void DatabaseInterface::setAcceptedSolution(string problem_id, string solution_id) {
	string query = "	CALL set_accepted_solution("
			"		?,"
			"		?"
			"	)";

	database_handler << query << problem_id << solution_id << exec;
}

void DatabaseInterface::unsetAcceptedSolution(string problem_id) {
	string query = "	CALL unset_accepted_solution("
			"		?"
			"	)";

	database_handler << query << problem_id << exec;
}

int DatabaseInterface::getProblemVoteBalance(string problem_id) {
	int vote_balance;
	string query = ""
			"	SELECT"
			"		vote_balance"
			"	FROM"
			"		Problem"
			"	WHERE"
			"		id = UNHEX(?)";

	result result = database_handler << query << problem_id;

	if (!result.next())
		// FIXME: Throw exception?
		return 0;

	result.fetch("vote_balance", vote_balance);

	return vote_balance;
}

int DatabaseInterface::getSolutionVoteBalance(string solution_id) {
	int vote_balance;
	string query = ""
			"	SELECT"
			"		vote_balance"
			"	FROM"
			"		Solution"
			"	WHERE"
			"		id = UNHEX(?)";

	result result = database_handler << query << solution_id;

	if (!result.next())
		// TODO: Throw exception?
		return 0;

	result.fetch("vote_balance", vote_balance);

	return vote_balance;
}

int DatabaseInterface::getUserVoteOnProblem(string user_name, string problem_id) {
	string query = ""
			"	SELECT"
			"		is_positive"
			"	FROM"
			"		problem_votes"
			"	WHERE"
			"		problem_id = UNHEX(?) AND username LIKE BINARY ?";

	result result = database_handler << query << problem_id << user_name;

	if (!result.next())
		return 0;

	int is_positive;
	result.fetch("is_positive", is_positive);

	return is_positive ? 1 : -1;
}

int DatabaseInterface::getUserVoteOnSolution(string user_name, string solution_id) {
	string query = ""
			"	SELECT"
			"		is_positive"
			"	FROM"
			"		solution_votes"
			"	WHERE"
			"		solution_id = UNHEX(?) AND username LIKE BINARY ?";
	result result = database_handler << query << solution_id << user_name;

	if (!result.next())
		return 0;

	int is_positive;
	result.fetch("is_positive", is_positive);

	return is_positive ? 1 : -1;
}

Publication* DatabaseInterface::searchPublication(string publication_id) {
	if (publication_id[1] == '3')
		// Publication is a Solution
		return searchSolution(publication_id);
	else
		// Publication is a Problem
		return searchProblem(publication_id);
}

void DatabaseInterface::answerClarification(string id, string answer) {
	string query = ""
			"	UPDATE"
			"		Clarification"
			"	SET"
			"		answer = ?"
			"	WHERE"
			"		id = UNHEX(?)";

	database_handler << query << answer << id << exec;
}

void DatabaseInterface::voteSolution(string solution_id, string user_name, bool is_positive) {
	string query = "	CALL vote_solution("
			"		?,"
			"		?,"
			"		?"
			"	)";

	database_handler << query << solution_id << user_name << is_positive << exec;
}

std::list<Clarification*>* DatabaseInterface::searchAnsweredClarifications(std::string problem_id) {

	stringstream query;
	query << "	SELECT" << clarification_attributes << "	FROM Clarification"
			"	WHERE publication_id = UNHEX(?) AND answer IS NOT NULL";

	result result = database_handler << query.str() << problem_id;

	list<Clarification *> *clarification_list = new list<Clarification *>();

	while (result.next()) {
		clarification_list->push_back(fetchClarification(result));
	}

	return clarification_list;

}

std::list<Clarification*>* DatabaseInterface::searchAnsweredClarifications(std::string problem_id,
		std::string user_name) {

	stringstream query;
	query << "	SELECT" << clarification_attributes << ""
			"	FROM"
			"		Clarification"
			"	WHERE"
			"		publication_id = UNHEX(?) AND "
			"		( answer IS NOT NULL OR "
			"		creator_user_name LIKE BINARY ? )";

	result result = database_handler << query.str() << problem_id << user_name;

	list<Clarification *> *clarification_list = new list<Clarification *>();

	while (result.next()) {
		clarification_list->push_back(fetchClarification(result));
	}

	return clarification_list;
}

void DatabaseInterface::insertNotification(Notification* notification) {

	string query = ""
			"	INSERT INTO"
			"		Notification(event_code, user_name, originator_user_name, seen, url)"
			"	VALUES"
			"		(?, ?, ?, ?, ?)";

	database_handler << query << notification->event_code << notification->user_name
			<< notification->originator_user_name << "0" << notification->url << exec;
}

list<Notification *> *DatabaseInterface::getUnseenNotifications(string user_name) {
	stringstream query;
	query << " SELECT " << notification_attributes << "	FROM"
			"		Notification "
			"	WHERE user_name LIKE BINARY ?"
			"		AND seen = 0";

	result result = database_handler << query.str() << user_name;

	list<Notification *> *notification_list = new list<Notification *>();

	while (result.next()) {
		notification_list->push_back(fetchNotification(result));
	}

	return notification_list;
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

void DatabaseInterface::updateProblemContent(std::string id, std::string content) {
	string query = ""
			"	UPDATE"
			"		Problem"
			"	SET"
			"		content = ?"
			"	WHERE"
			"		id = UNHEX(?)";

	database_handler << query << content << id << exec;
}

int DatabaseInterface::numberOfSolutions(std::string problem_id) {
	string query = "	SELECT"
			"		count(*) AS number_of_solutions"
			"	FROM"
			"		problem_solutions"
			"	WHERE"
			"		problem_id = UNHEX(?)";

	result result = database_handler << query << problem_id;

	if (!result.next())
		// TODO
		return 0;

	int number_of_solutions;

	result.fetch("number_of_solutions", number_of_solutions);

	return number_of_solutions;
}

Notification* DatabaseInterface::fetchNotification(result result) {

	Notification *notification = new Notification();
	try {

		result.fetch("event_code", notification->event_code);
		result.fetch("user_name", notification->user_name);
		result.fetch("originator_user_name", notification->originator_user_name);
		result.fetch("seen", notification->seen);
		result.fetch("url", notification->url);

	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << " in fetchNotification" << endl;
		return NULL;
	}

	return notification;
}

list<string>* DatabaseInterface::searchProblemVoters(string problem_id) {
	string query = ""
			"	SELECT username"
			"	FROM problem_votes"
			"	WHERE problem_id = UNHEX(?) AND is_positive = 1";

	result result = database_handler << query << problem_id;

	list<string>* problem_voters = new list<string>();

	while (result.next()) {
		string user_name;
		result.fetch("username", user_name);
		problem_voters->push_back(user_name);
	}

	return problem_voters;
}

list<string>* DatabaseInterface::searchSolutionVoters(string solution_id) {
	string query = ""
			"	SELECT username"
			"	FROM solution_votes"
			"	WHERE solution_id = UNHEX(?) AND is_positive = 1";

	result result = database_handler << query << solution_id;

	list<string>* solution_voters = new list<string>();

	while (result.next()) {
		string user_name;
		result.fetch("username", user_name);
		solution_voters->push_back(user_name);
	}

	return solution_voters;
}

list<string>* DatabaseInterface::searchProposalVoters(string proposal_id) {
	string query = ""
			"	SELECT username"
			"	FROM proposal_votes"
			"	WHERE proposal_id = UNHEX(?) AND is_positive = 1";

	result result = database_handler << query << proposal_id;

	list<string>* proposal_voters = new list<string>();

	while (result.next()) {
		string user_name;
		result.fetch("username", user_name);
		proposal_voters->push_back(user_name);
	}

	return proposal_voters;
}
