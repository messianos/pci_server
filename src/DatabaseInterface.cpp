#include "DatabaseInterface.h"

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
	result.fetch("content", problem->content);
	result.fetch("creation_datetime", problem->creation_datetime);
	result.fetch("creator_user_name", problem->creator_user_name);
	result.fetch("description", problem->description);
	result.fetch("id", problem->id);

	short int boolean;
	result.fetch("is_anonymous", boolean);
	problem->is_anonymous = boolean;
	result.fetch("is_solved", boolean);
	problem->is_solved = boolean;
	result.fetch("last_edition_datetime", problem->last_edition_datetime);

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
	result.fetch("creation_datetime", solution->creation_datetime);
	result.fetch("creator_user_name", solution->creator_user_name);
	result.fetch("description", solution->description);
	result.fetch("id", solution->id);

	short int boolean;
	result.fetch("is_anonymous", boolean);
	solution->is_anonymous = boolean;
	result.fetch("last_edition_datetime", solution->last_edition_datetime);

	return solution;
}

list<Solution*>* DatabaseInterface::searchSolutions(long problem_id) {
	// TODO
	return new list<Solution*> ;
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
			<< "SELECT * FROM Clarification WHERE id = ?"
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
	// TODO
	return 0;
}

void DatabaseInterface::insertProblem(Problem problem) {
	cppdb::statement statement;
	statement =
			databaseHandler
					<< "INSERT INTO Problem (accepted_solution_id,content,creation_datetime, creation_user_name, description, id, is_anonymous, is_solve, last_edition) "

}
