#include "DatabaseInterface.h"
#include "DateClass.h"
#include <sstream>
#include <string>
#include <iostream>

// TODO: Fix Datetime attributes fetching, now they're commented

DatabaseInterface::DatabaseInterface() {
	databaseHandler =
			cppdb::session(
					"mysql: database=pci_database; user=pci_user; password='pci_password'");
}

DatabaseInterface::~DatabaseInterface() {
	// TODO Auto-generated destructor stub
	databaseHandler.~session();
}

Problem *DatabaseInterface::getProblem(long searched_id) {

	Problem *problem;

	cppdb::result result = databaseHandler
			<< "SELECT * FROM Problem WHERE id = ?" << searched_id;
	problem = new Problem();

	result.next();

	result.fetch("accepted_solution_id", problem->accepted_solution_id);
	//result.fetch("creation_datetime", problem->creation_datetime);
	result.fetch("creator_user_name", problem->creator_user_name);
	result.fetch("description", problem->description);
	result.fetch("id", problem->id);

	short int boolean;
	result.fetch("is_anonymous", boolean);
	problem->is_anonymous = boolean;
	result.fetch("is_solved", boolean);
	problem->is_solved = boolean;
	result.fetch("content", problem->content);
	//result.fetch("last_edition_datetime", problem->last_edition_datetime);

	return problem;
}

list<Problem*>* DatabaseInterface::searchProblems(/* TODO: define parameters */) {
	// TODO
	return new list<Problem*> ;
}

Solution *DatabaseInterface::getSolution(long searched_id) {

	Solution *solution;

	cppdb::result result = databaseHandler
			<< "SELECT * FROM Solution WHERE id = ?" << searched_id;
	solution = new Solution();

	result.next();

	result.fetch("content", solution->content);
	//result.fetch("creation_datetime", solution->creation_datetime);
	result.fetch("creator_user_name", solution->creator_user_name);
	result.fetch("description", solution->description);
	result.fetch("id", solution->id);

	short int boolean;
	result.fetch("is_anonymous", boolean);
	solution->is_anonymous = boolean;
	//result.fetch("last_edition_datetime", solution->last_edition_datetime);

	return solution;
}

list<Solution*>* DatabaseInterface::searchSolutions(long problem_id) {
	list<Solution*>* lista = new list<Solution*>();

	cppdb::result result = databaseHandler
			<< "SELECT * FROM problem_solutions WHERE problem_id = ?"
			<< problem_id;
	// TODO: Should a join be maked instead of N solutions search by id?

	while (result.next()) {
		long solution_id;
		result.fetch("solution_id", solution_id);
		lista->push_back(getSolution(solution_id));
	}

	return lista;
}

Clarification *DatabaseInterface::getClarification(long searched_id) {

	Clarification *clarification;

	cppdb::result result = databaseHandler
			<< "SELECT * FROM Clarification WHERE id = ?" << searched_id;
	clarification = new Clarification();

	result.next();

	result.fetch("answer", clarification->answer);
	result.fetch("creator_user_name", clarification->creator_user_name);
	result.fetch("id", clarification->id);
	result.fetch("question", clarification->question);

	return clarification;
}

list<Clarification*>* DatabaseInterface::searchClarifications(
		long associated_publication_id) {

	list<Clarification*>* lista = new list<Clarification*>();

	cppdb::result result = databaseHandler
			<< "SELECT * FROM Clarification WHERE associated_publication_id = ?"
			<< associated_publication_id;

	while (result.next()) {
		Clarification *clarification = new Clarification();

		result.fetch("answer", clarification->answer);
		result.fetch("creator_user_name", clarification->creator_user_name);
		result.fetch("id", clarification->id);
		result.fetch("question", clarification->question);

		lista->push_back(clarification);
	}

	return lista;
}

User *DatabaseInterface::getUser(long user_name) {
	User *user;

	cppdb::result result = databaseHandler << "SELECT * FROM User WHERE id = ?"
			<< user_name;
	user = new User();

	result.next();

	string birth_date;
	int day, month, year;
	result.fetch("birth_date ", birth_date);
	stringstream s(birth_date);
	s >> year >> month >> day;

	DateClass date(day, month, year);
	user->birth_date = date;

	result.fetch("email", user->email);
	result.fetch("first_name", user->first_name);
	result.fetch("genre", user->genre);
	result.fetch("last_name", user->last_name);
	result.fetch("location", user->location);
	result.fetch("password", user->password);
	result.fetch("signup_date", user->signup_date);
	result.fetch("user_name", user->user_name);

	return user;
}

void DatabaseInterface::insertProblem(Problem *problem) {
	databaseHandler
			<< "INSERT INTO Problem (accepted_solution_id,content,creation_datetime, creation_user_name, description, is_anonymous, is_solve, last_edition)"
					" VALUES (?,?,?,?,?,?,?,?,?"
			<< problem->accepted_solution_id << problem->content
			<< problem->creation_datetime << problem->creator_user_name
			<< problem->description << problem->is_anonymous
			<< problem->is_solved << problem->last_edition_datetime
			<< cppdb::exec;
}

void DatabaseInterface::insertSolution(Solution *solution) {
	databaseHandler
			<< "INSERT INTO Solution (content ,creation_datetime,creator_user_name ,description,is_anonymous ,last_edition_datetime )"
					" VALUES (?,?,?,?,?,?,?,?,?" << solution->content
			<< solution->creation_datetime << solution->creator_user_name
			<< solution->description << solution->is_anonymous
			<< solution->last_edition_datetime << cppdb::exec;
}

void DatabaseInterface::insertClarification(Clarification *clarification) {
	databaseHandler
			<< "INSERT INTO Clarification (answer,associated_publication_id,creator_user_name ,question)"
					" VALUES (?,?,?,?,?,?,?,?,?" << clarification->answer
			<< clarification->associated_publication_id
			<< clarification->creator_user_name << clarification->question
			<< cppdb::exec;
}

void DatabaseInterface::insertUser(User *user) {
	stringstream s;
	s << user->birth_date.year << "-" << user->birth_date.month << "-"
			<< user->birth_date.day;
	string birth_date = s.str();
	databaseHandler
			<< "INSERT INTO Problem (birth_date ,email ,first_name ,genre,last_name ,location ,	password , signup_date ,user_name)"
					" VALUES (?,?,?,?,?,?,?,?,?" << birth_date << user->email
			<< user->first_name << user->genre << user->last_name
			<< user->password << user->signup_date << user->user_name
			<< cppdb::exec;
}

void DatabaseInterface::removeProblem(long deleted_id) {
	databaseHandler << "DELETE from Problem WHERE id = '?' " << deleted_id
			<< cppdb::exec;
}

void DatabaseInterface::removeSolution(long deleted_id) {
	databaseHandler << "DELETE from Solution WHERE id = '?' " << deleted_id
			<< cppdb::exec;
}

void DatabaseInterface::removeClarification(long deleted_id) {
	databaseHandler << "DELETE from Clarification WHERE id = '?' " << deleted_id
			<< cppdb::exec;
}

list<Problem*>* DatabaseInterface::searchProblemsbyUser(string user) {
	list<Problem*>* lista = new list<Problem*>();

	cppdb::result result = databaseHandler
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

	return lista;
}

list<Solution*>* DatabaseInterface::searchSolutionsbyUser(string user) {
	list<Solution*>* lista = new list<Solution*>();

	cppdb::result result = databaseHandler
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

	return lista;
}

list<Problem*>* DatabaseInterface::searchProblemsRandom(int number) {
	list<Problem*>* lista = new list<Problem*>();

	cppdb::result result = databaseHandler
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

	return lista;
}

