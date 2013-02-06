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
const string clarification_attributes = "		answer,"
		"		HEX(associated_publication_id) AS associated_publication_id,"
		"		creator_user_name,"
		"		HEX(id) AS id,"
		"		question";

const string problem_attributes = "		HEX(accepted_solution_id) AS accepted_solution_id,"
		"		content,"
		"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
		"		creator_user_name,"
		"		description,"
		"		HEX(id) AS id,"
		"		is_anonymous,"
		"		is_solved,"
		"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime";

const string solution_attributes = "		content,"
		"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
		"		creator_user_name,"
		"		description,"
		"		HEX(id) AS id,"
		"		is_anonymous,"
		"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime";

const string user_attributes = "		birth_date,"
		"		email,"
		"		first_name,"
		"		genre,"
		"		last_name,"
		"		location,"
		"		UNIX_TIMESTAMP(sign_up_datetime) AS sign_up_datetime,"
		"		user_name";

// TODO: Define share mode on SELECT statements

ErrorCode *DatabaseInterface::signInUser(string user_name, string encrypted_password) {
	string query;

	query = "	CALL sign_in_user("
			"		?,"
			"		?,"
			"		@out_success"
			"	)";

	database_handler << query << user_name << encrypted_password << exec;

	query = "SELECT @out_success";

	result result = database_handler << query;
	result.next();

	short int sign_in_success;
	result.fetch("@out_success", sign_in_success);
	if (!sign_in_success)
		return new ErrorCode(ErrorCode::CODE_INVALID_SIGN_IN);

	return new ErrorCode(ErrorCode::CODE_NONE);
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

	database_handler << query << user->birth_date->toString("%Y-%m-%d") << user->email << user->first_name
			<< user->genre << user->last_name << user->location << user->user_name << encrypted_password << exec;

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

	string query = "	SELECT"
			"		Solution.content AS content,"
			"		UNIX_TIMESTAMP(Solution.creation_datetime) AS creation_datetime,"
			"		Solution.creator_user_name AS creator_user_name,"
			"		Solution.description AS description,"
			"		HEX(Solution.id) AS id,"
			"		Solution.is_anonymous AS is_anonymous,"
			"		UNIX_TIMESTAMP(Solution.last_edition_datetime) AS last_edition_datetime"
			"	FROM"
			"		Problem"
			"		JOIN"
			"		Solution"
			"	ON Problem.accepted_solution_id = Solution.id"
			"	WHERE Problem.id = UNHEX(?)"
			"	LIMIT 1";

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

list<Solution *> *DatabaseInterface::searchSolutions(string problem_id) {

	string query = "	SELECT"
			"		Solution.content AS content,"
			"		UNIX_TIMESTAMP(Solution.creation_datetime) AS creation_datetime,"
			"		Solution.creator_user_name AS creator_user_name,"
			"		Solution.description AS description,"
			"		HEX(Solution.id) AS id,"
			"		Solution.is_anonymous AS is_anonymous,"
			"		UNIX_TIMESTAMP(Solution.last_edition_datetime) AS last_edition_datetime"
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

int DatabaseInterface::numberOfSolutionsByUser(std::string user_name) {
	string query = "	SELECT"
			"	count(*) AS num_solutions"
			"	FROM"
			"	Solution"
			"	WHERE"
			"	creator_user_name = ?";

	result result = database_handler << query << user_name;

	int to_return;
	result.next();
	result.fetch("num_solutions", to_return);

	return to_return;
}

int DatabaseInterface::numberOfProblemsByUser(std::string user_name) {
	string query = "	SELECT"
			"	count(*) AS num_problems"
			"	FROM"
			"	Problem"
			"	WHERE"
			"	creator_user_name = ?";

	result result = database_handler << query << user_name;

	int to_return;
	result.next();
	result.fetch("num_problems", to_return);

	return to_return;
}

int DatabaseInterface::numberOfAcceptedSolutionsByUser(std::string user_name) {
	//TODO
	return 0;
}

list<Publication *> * DatabaseInterface::getRecentActivityByUser(std::string user_name) {

	stringstream problem_query;
	problem_query << "	SELECT" << problem_attributes << "	FROM"
			"	Problem"
			"	WHERE"
			"	creator_user_name = ?"
			"	ORDER BY last_edition_datetime DESC"
			"	LIMIT 10";
	stringstream solution_query;
	solution_query << "	SELECT" << solution_attributes << "	FROM"
			"	Solution"
			"	WHERE"
			"	creator_user_name = ?"
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

	publication_list->sort();
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
	} catch (std::exception const &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return NULL;
	}

	return clarification;
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
	} catch (std::exception const &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return NULL;
	}

	return solution;
}

Problem* DatabaseInterface::fetchProblem(result result) {

	Problem *problem = new Problem();
	try {
		time_t timestamp;

		result.fetch("accepted_solution_id", problem->accepted_solution_id);
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

	} catch (std::exception const &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return NULL;
	}

	return problem;
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
	} catch (std::exception const &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return NULL;
	}

	return user;
}

