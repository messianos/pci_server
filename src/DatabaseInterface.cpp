
// Includes
#include "DatabaseInterface.h"

// Namespaces
using namespace cppdb;
using namespace std;

// Initializations
session DatabaseInterface::database_handler = session("mysql: database=pci_database; user=pci_user; password=pci_password");

// TODO: Fix Datetime attributes fetching, now they're commented
// TODO: Define share mode on SELECT statements
// TODO: convert SELECTED ids to hexa

User *DatabaseInterface::searchUser(string user_name) {

	string query =
		"SELECT *"
		"FROM User_no_password_view"
		"WHERE user_name LIKE BINARY ?"
		"LIMIT 1";

	result result = database_handler << query << user_name;
	if (! result.next())
		// User not found
		return NULL;

	User *user = new User();

	// TODO
	/*
	tm birth_date;
	int day, month, year;
	result.fetch("birth_date", birth_date);
	stringstream s(birth_date);
	s >> year >> month >> day;
	DateClass date(day, month, year);
	user->birth_date = date;*/
	result.fetch("email", user->email);
	result.fetch("first_name", user->first_name);
	result.fetch("genre", user->genre);
	result.fetch("last_name", user->last_name);
	result.fetch("location", user->location);
	// result.fetch("sign_up_date", user->sign_up_date); // TODO
	result.fetch("user_name", user->user_name);

	return user;
}

Problem *DatabaseInterface::searchProblem(string id) {

	string query =
		"SELECT"
		"	HEX(accepted_solution_id),"
		"	content,"
		"	creation_datetime,"
		"	creator_user_name,"
		"	description,"
		"	HEX(id),"
		"	is_anonymous,"
		"	is_solved,"
		"	last_edition_datetime"
		"FROM Problem"
		"WHERE id LIKE UNHEX('?')"
		"LIMIT 1";

	result result = database_handler << query << id;
	if (! result.next())
		// Problem not found
		return NULL;

	Problem *problem = new Problem();
	short int boolean;

	result.fetch("HEX(accepted_solution_id)", problem->accepted_solution_id);
	result.fetch("content", problem->content);
	//result.fetch("creation_datetime", problem->creation_datetime); // TODO
	result.fetch("creator_user_name", problem->creator_user_name);
	result.fetch("description", problem->description);
	result.fetch("HEX(id)", problem->id);
	result.fetch("is_anonymous", boolean);
	problem->is_anonymous = boolean;
	result.fetch("is_solved", boolean);
	problem->is_solved = boolean;
	//result.fetch("last_edition_datetime", problem->last_edition_datetime); // TODO

	return problem;
}

list<Problem *> *DatabaseInterface::searchProblems(/* TODO: define parameters */) {
	// TODO
	return NULL;
}

Solution *DatabaseInterface::searchSolution(string id) {

	string query =
		"SELECT"
		"	content,"
		"	creation_datetime,"
		"	creator_user_name,"
		"	description,"
		"	HEX(id),"
		"	is_anonymous,"
		"	last_edition_datetime"
		"FROM Solution"
		"WHERE id LIKE UNHEX('?')"
		"LIMIT 1";

	result result = database_handler << query << id;
	if (! result.next())
		// Solution not found
		return NULL;

	Solution *solution = new Solution();
	short int boolean;

	result.fetch("content", solution->content);
	//result.fetch("creation_datetime", solution->creation_datetime); // TODO
	result.fetch("creator_user_name", solution->creator_user_name);
	result.fetch("description", solution->description);
	result.fetch("HEX(id)", solution->id);
	result.fetch("is_anonymous", boolean);
	solution->is_anonymous = boolean;
	//result.fetch("last_edition_datetime", solution->last_edition_datetime); // TODO

	return solution;
}

Solution *DatabaseInterface::searchAcceptedSolution(string problem_id) {

	string query =
		"SELECT"
		"	Solution.content,"
		"	Solution.creation_datetime,"
		"	Solution.creator_user_name,"
		"	Solution.description,"
		"	HEX(Solution.id),"
		"	Solution.is_anonymous,"
		"	Solution.last_edition_datetime"
		"FROM"
		"	Problem"
		"	JOIN"
		"	Solution"
		"ON Problem.accepted_solution_id LIKE Solution.id"
		"WHERE Problem.id LIKE UNHEX('?')"
		"LIMIT 1";

	result result = database_handler << query << problem_id;
	if (! result.next())
		// Solution not found
		return NULL;

	Solution *solution = new Solution();
	short int boolean;

	result.fetch("Solution.content", solution->content);
	//result.fetch("Solution.creation_datetime", solution->creation_datetime); // TODO
	result.fetch("Solution.creator_user_name", solution->creator_user_name);
	result.fetch("Solution.description", solution->description);
	result.fetch("HEX(Solution.id)", solution->id);
	result.fetch("Solution.is_anonymous", boolean);
	solution->is_anonymous = boolean;
	//result.fetch("Solution.last_edition_datetime", solution->last_edition_datetime); // TODO

	return solution;
}

list<Solution *> *DatabaseInterface::searchSolutions(string problem_id) {

	string query =
		"SELECT"
		"	Solution.content,"
		"	Solution.creation_datetime,"
		"	Solution.creator_user_name,"
		"	Solution.description,"
		"	HEX(Solution.id),"
		"	Solution.is_anonymous,"
		"	Solution.last_edition_datetime"
		"FROM"
		"	Problem"
		"	JOIN"
		"	problem_solutions"
		"	JOIN"
		"	Solution"
		"ON"
		"	Problem.id LIKE problem_solutions.problem_id"
		"	AND"
		"	Solution.id LIKE problem_solutions.solution_id"
		"WHERE Problem.id LIKE UNHEX('?')";

	result result = database_handler << query << problem_id;

	list<Solution *> *solution_list = new list<Solution *>();

	while (result.next()) {

		Solution *solution = new Solution();
		short int boolean;

		result.fetch("Solution.content", solution->content);
		//result.fetch("Solution.creation_datetime", solution->); TODO
		result.fetch("Solution.creator_user_name", solution->creator_user_name);
		result.fetch("Solution.description", solution->description);
		result.fetch("HEX(Solution.id)", solution->id);
		result.fetch("Solution.is_anonymous", boolean);
		solution->id = boolean;
		//result.fetch("Solution.last_edition_datetime", solution->); TODO

		solution_list->push_back(solution);
	}

	return solution_list;
}

Clarification *DatabaseInterface::searchClarification(string id) {

	string query =
		"SELECT"
		"	answer,"
		"	HEX(associated_publication_id),"
		"	creator_user_name,"
		"	HEX(id),"
		"	question"
		"FROM Clarification"
		"WHERE id LIKE UNHEX('?')"
		"LIMIT 1";

	result result = database_handler << query << id;
	if (! result.next())
		// Clarification not found
		return NULL;

	Clarification *clarification = new Clarification();

	result.fetch("answer", clarification->answer);
	result.fetch("HEX(associated_publication_id)", clarification->associated_publication_id);
	result.fetch("creator_user_name", clarification->creator_user_name);
	result.fetch("HEX(id)", clarification->id);
	result.fetch("question", clarification->question);

	return clarification;
}

list<Clarification *> *DatabaseInterface::searchClarifications(string associated_publication_id) {

	string query =
		"SELECT"
		"	answer,"
		"	HEX(associated_publication_id),"
		"	creator_user_name,"
		"	HEX(id),"
		"	question"
		"FROM Clarification"
		"WHERE associated_publication_id LIKE UNHEX('?')";

	result result = database_handler << query << associated_publication_id;

	list<Clarification *> *clarification_list = new list<Clarification *>();

	while (result.next()) {

		Clarification *clarification = new Clarification();

		result.fetch("answer", clarification->answer);
		result.fetch("HEX(associated_publication_id)", clarification->associated_publication_id);
		result.fetch("creator_user_name", clarification->creator_user_name);
		result.fetch("HEX(id)", clarification->id);
		result.fetch("question", clarification->question);

		clarification_list->push_back(clarification);
	}

	return clarification_list;
}
















list<Problem*>* DatabaseInterface::searchProblemsByUser(string user) {
	/*list<Problem*>* lista = new list<Problem*>();

	result result = database_handler
			<< "SELECT * FROM Clarification WHERE creator_user_name = ?"
			<< user;
	while (result.next()) {
		Problem *problem = new Problem();

		result.fetch("accepted_solution_id", problem->accepted_solution_id);
		result.fetch("content", problem->content);
		result.fetch("creation_datetime", problem->creation_datetime);
		result.fetch("creation_user_name", problem->creator_user_name);
		result.fetch("description", problem->description);
		result.fetch("id", problem->id);

		short int boolean;
		result.fetch("is_anonymous", boolean);
		problem->is_anonymous = boolean;
		result.fetch("is_solve", boolean);
		problem->is_solved = boolean;
		result.fetch("last_edition", problem->last_edition_datetime);

		lista->push_back(problem);
	}

	return lista;*/
	// TODO
	return NULL;
}

list<Solution*>* DatabaseInterface::searchSolutionsByUser(string user) {
	/*list<Solution*>* lista = new list<Solution*>();

	result result = database_handler
			<< "SELECT * FROM Clarification WHERE creator_user_name = ?"
			<< user;

	while (result.next()) {
		Solution *solution = new Solution();

		result.fetch("content", solution->content);
		result.fetch("creation_datetime", solution->creation_datetime);
		result.fetch("creator_user_name", solution->creator_user_name);
		result.fetch("description", solution->description);
		result.fetch("id", solution->id);

		short int boolean;
		result.fetch("is_anonymous", boolean);
		solution->is_anonymous = boolean;
		result.fetch("last_edition_datetime", solution->last_edition_datetime);

		lista->push_back(solution);
	}

	return lista;*/
	// TODO
	return NULL;
}

list<Problem*>* DatabaseInterface::searchProblemsRandom(int number) {
	/*
	list<Problem*>* lista = new list<Problem*>();

	result result = database_handler
			<< "SELECT * FROM Problem ORDER BY RAND() LIMIT ?" << number;
	while (result.next()) {
		Problem *problem = new Problem();

		result.fetch("accepted_solution_id", problem->accepted_solution_id);
		result.fetch("content", problem->content);
		//result.fetch("creation_datetime", problem->creation_datetime);
		result.fetch("creator_user_name", problem->creator_user_name);
		result.fetch("description", problem->description);
		result.fetch("id", problem->id);

		short int boolean;
		result.fetch("is_anonymous", boolean);
		problem->is_anonymous = boolean;
		result.fetch("is_solved", boolean);
		problem->is_solved = boolean;
		//result.fetch("last_edition_datetime", problem->last_edition_datetime);

		lista->push_back(problem);
	}

	return lista;*/
	// TODO
	return NULL;
}




void DatabaseInterface::insertUser(User *user) {
	// TODO
}

void DatabaseInterface::insertProblem(Problem *problem) {
	string query =
		"CALL insert_problem("
		"	'?',"
		//"	'?',"
		"	'?',"
		"	'?',"
		"	'?',"
		"	?"
		")";

	database_handler
		<< query
		<< problem->content
		//<< problem->creation_datetime
		<< problem->creator_user_name
		<< problem->description
		<< problem->id
		<< problem->is_anonymous // TODO: decidir sobre booleanos
		<< exec;
}

void DatabaseInterface::insertSolution(Solution *solution) {
	// TODO
}

void DatabaseInterface::insertClarification(Clarification *clarification) {
	// TODO
}

void DatabaseInterface::deleteProblem(std::string id) {
	string query = "CALL delete_problem('?')";
	database_handler << query << id << exec;
}

void DatabaseInterface::deleteSolution(std::string id) {
	string query = "CALL delete_solution('?')";
	database_handler << query << id << exec;
}

void DatabaseInterface::deleteClarification(std::string id) {
	string query = "CALL delete_clarification('?')";
	database_handler << query << id << exec;
}
