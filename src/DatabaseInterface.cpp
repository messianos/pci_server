
// Includes
#include "DatabaseInterface.h"

// Namespaces
using namespace cppdb;
using namespace std;

// Initializations
session DatabaseInterface::database_handler = session("mysql: host=pci-server.no-ip.org; database=pci_database; user=pci_user; password=pci_password");

// TODO: Define share mode on SELECT statements

User *DatabaseInterface::searchUser(string user_name) {

	string query =
	"	SELECT"
	"		birth_date,"
	"		email,"
	"		first_name,"
	"		genre,"
	"		last_name,"
	"		location,"
	"		UNIX_TIMESTAMP(sign_up_datetime) AS sign_up_datetime,"
	"		user_name"
	"	FROM User"
	"	WHERE user_name LIKE BINARY ?"
	"	LIMIT 1";

	result result = database_handler << query << user_name;
	if (! result.next())
		// User not found
		return NULL;

	User *user = new User();
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

	return user;
}

ErrorCode *DatabaseInterface::signInUser(string user_name, string encrypted_password) {
	string query;

	query =
	"	CALL sign_in_user("
	"		?,"
	"		?,"
	"		@out_success"
	"	)";

	database_handler
		<< query
		<< user_name
		<< encrypted_password
		<< exec;

	query = "SELECT @out_success";

	result result = database_handler << query;
	result.next();

	short int sign_in_success;
	result.fetch("@out_success", sign_in_success);
	if (! sign_in_success)
		return new ErrorCode(ErrorCode::CODE_INVALID_SIGN_IN);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

// FIXME: This may return success or fail
ErrorCode *DatabaseInterface::signUpUser(User *user, string encrypted_password) {
	string query =
	"	CALL sign_up_user("
	"		?,"
	"		?,"
	"		?,"
	"		?,"
	"		?,"
	"		?,"
	"		?,"
	"		?"
	"	)";

	database_handler
		<< query
		<< user->birth_date->toString("%Y-%m-%d")
		<< user->email
		<< user->first_name
		<< user->genre
		<< user->last_name
		<< user->location
		<< user->user_name
		<< encrypted_password
		<< exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

Problem *DatabaseInterface::searchProblem(string id) {

	string query =
	"	SELECT"
	"		HEX(accepted_solution_id) AS accepted_solution_id,"
	"		content,"
	"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
	"		creator_user_name,"
	"		description,"
	"		HEX(id) AS id,"
	"		is_anonymous,"
	"		is_solved,"
	"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime"
	"	FROM Problem"
	"	WHERE id = UNHEX(?)"
	"	LIMIT 1";

	result result = database_handler << query << id;
	if (! result.next())
		// Problem not found
		return NULL;

	Problem *problem = new Problem();
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

	return problem;
}

list<Problem *> *DatabaseInterface::searchProblems(/* TODO: define parameters */) {
	// TODO
	return NULL;
}

list<Problem *> *DatabaseInterface::searchProblemsByUser(string user_name) {

	string query =
	"	SELECT"
	"		HEX(accepted_solution_id) AS accepted_solution_id,"
	"		content,"
	"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
	"		creator_user_name,"
	"		description,"
	"		HEX(id) AS id,"
	"		is_anonymous,"
	"		is_solved,"
	"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime"
	"	FROM Problem"
	"	WHERE creator_user_name LIKE BINARY ?";

	result result = database_handler << query << user_name;

	list<Problem *> *problem_list = new list<Problem *>();

	while (result.next()) {

		Problem *problem = new Problem();
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

		problem_list->push_back(problem);
	}

	return problem_list;
}

list<Problem *> *DatabaseInterface::searchProblemsRandom(int amount) {

	string query =
	"	SELECT"
	"		HEX(accepted_solution_id) AS accepted_solution_id,"
	"		content,"
	"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
	"		creator_user_name,"
	"		description,"
	"		HEX(id) AS id,"
	"		is_anonymous,"
	"		is_solved,"
	"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime"
	"	FROM Problem"
	"	ORDER BY RAND()"
	"	LIMIT ?";

	result result = database_handler << query << amount;

	list<Problem *> *problem_list = new list<Problem *>();

	while (result.next()) {

		Problem *problem = new Problem();
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

		problem_list->push_back(problem);
	}

	return problem_list;
}

ErrorCode * DatabaseInterface::insertProblem(Problem *problem) {
	string query =
	"	CALL insert_problem("
	"		?,"
	"		?,"
	"		?,"
	"		?,"
	"		?"
	"	)";

	database_handler
		<< query
		<< problem->content
		<< problem->creator_user_name
		<< problem->description
		<< problem->id
		<< problem->is_anonymous
		<< exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode * DatabaseInterface::deleteProblem(string id) {
	string query = "CALL delete_problem(?)";
	database_handler << query << id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

Solution *DatabaseInterface::searchSolution(string id) {

	string query =
	"	SELECT"
	"		content,"
	"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
	"		creator_user_name,"
	"		description,"
	"		HEX(id) AS id,"
	"		is_anonymous,"
	"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime"
	"	FROM Solution"
	"	WHERE id = UNHEX(?)"
	"	LIMIT 1";

	result result = database_handler << query << id;
	if (! result.next())
		// Solution not found
		return NULL;

	Solution *solution = new Solution();
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

	return solution;
}

Solution *DatabaseInterface::searchAcceptedSolution(string problem_id) {

	string query =
	"	SELECT"
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
	if (! result.next())
		// Solution not found
		return NULL;

	Solution *solution = new Solution();
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

	return solution;
}

list<Solution *> *DatabaseInterface::searchSolutions(string problem_id) {

	string query =
	"	SELECT"
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

		Solution *solution = new Solution();
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

		solution_list->push_back(solution);
	}

	return solution_list;
}

list<Solution *> *DatabaseInterface::searchSolutionsByUser(string user_name) {

	string query =
	"	SELECT"
	"		content,"
	"		UNIX_TIMESTAMP(creation_datetime) AS creation_datetime,"
	"		creator_user_name,"
	"		description,"
	"		HEX(Solution.id) AS id,"
	"		is_anonymous,"
	"		UNIX_TIMESTAMP(last_edition_datetime) AS last_edition_datetime"
	"	FROM Solution"
	"	WHERE creator_user_name LIKE BINARY ?";

	result result = database_handler << query << user_name;

	list<Solution *> *solution_list = new list<Solution *>();

	while (result.next()) {

		Solution *solution = new Solution();
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

		solution_list->push_back(solution);
	}

	return solution_list;
}

ErrorCode * DatabaseInterface::insertSolution(Solution *solution, string problem_id) {
	string query =
	"	CALL insert_solution("
	"		?,"
	"		?,"
	"		?,"
	"		?,"
	"		?,"
	"		?"
	"	)";

	database_handler
		<< query
		<< problem_id
		<< solution->content
		<< solution->creator_user_name
		<< solution->description
		<< solution->id
		<< solution->is_anonymous
		<< exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode * DatabaseInterface::deleteSolution(string id) {
	string query = "CALL delete_solution(?)";
	database_handler << query << id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

Clarification *DatabaseInterface::searchClarification(string id) {

	string query =
	"	SELECT"
	"		answer,"
	"		HEX(associated_publication_id) AS associated_publication_id,"
	"		creator_user_name,"
	"		HEX(id) AS id,"
	"		question"
	"	FROM Clarification"
	"	WHERE id = UNHEX(?)"
	"	LIMIT 1";

	result result = database_handler << query << id;
	if (! result.next())
		// Clarification not found
		return NULL;

	Clarification *clarification = new Clarification();

	result.fetch("answer", clarification->answer);
	result.fetch("associated_publication_id", clarification->associated_publication_id);
	result.fetch("creator_user_name", clarification->creator_user_name);
	result.fetch("id", clarification->id);
	result.fetch("question", clarification->question);

	return clarification;
}

list<Clarification *> *DatabaseInterface::searchClarifications(string associated_publication_id) {

	string query =
	"	SELECT"
	"		answer,"
	"		HEX(associated_publication_id) AS associated_publication_id,"
	"		creator_user_name,"
	"		HEX(id) AS id,"
	"		question"
	"	FROM Clarification"
	"	WHERE associated_publication_id = UNHEX(?)";

	result result = database_handler << query << associated_publication_id;

	list<Clarification *> *clarification_list = new list<Clarification *>();

	while (result.next()) {

		Clarification *clarification = new Clarification();

		result.fetch("answer", clarification->answer);
		result.fetch("associated_publication_id", clarification->associated_publication_id);
		result.fetch("creator_user_name", clarification->creator_user_name);
		result.fetch("id", clarification->id);
		result.fetch("question", clarification->question);

		clarification_list->push_back(clarification);
	}

	return clarification_list;
}

ErrorCode * DatabaseInterface::insertClarification(Clarification *clarification) {
	string query =
	"	CALL insert_clarification("
	"		?,"
	"		?,"
	"		?,"
	"		?"
	"	)";

	database_handler
		<< query
		<< clarification->associated_publication_id
		<< clarification->creator_user_name
		<< clarification->id
		<< clarification->question
		<< exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode * DatabaseInterface::deleteClarification(string id) {
	string query = "CALL delete_clarification(?)";
	database_handler << query << id << exec;

	// TODO
	return new ErrorCode(ErrorCode::CODE_NONE);
}
