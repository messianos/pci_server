#include "DatabaseInterface.h"

void DatabaseInterface::connectToDatabase() {
	databaseHandler = cppdb::session("mysql: database=pci_database; user=pci_user; password='pci_password'");
}

DatabaseInterface::DatabaseInterface() {
	connectToDatabase();
}

DatabaseInterface::~DatabaseInterface() {
	// TODO Auto-generated destructor stub}
	databaseHandler.~session();
}

Problem DatabaseInterface::getProblem(long id) {

	Problem problem;

	cppdb::result result = databaseHandler << "SELECT * FROM Problem WHERE id = ?" << id;
	problem = new Problem();
	// TODO: set the problem attributes

	return problem;
}

list<Problem> DatabaseInterface::searchProblems(/* TODO: define parameters */) {
	// TODO
}

Solution DatabaseInterface::getSolution(long id) {

	Solution solution;

	cppdb::result result = databaseHandler << "SELECT * FROM Solution WHERE id = ?" << id;
	solution = new Solution();
	// TODO: set the solution attributes

	return solution;
}

list<Solution> DatabaseInterface::searchSolutions(long problem_id) {
	// TODO
}

Clarification DatabaseInterface::getClarification(long id) {

	Clarification clarification;

	cppdb::result result = databaseHandler << "SELECT * FROM Clarification WHERE id = ?" << id;
	clarification = new Clarification();
	// TODO: set the clarification attributes

	return clarification;
}

list<Clarification> DatabaseInterface::searchClarifications(long associated_publication_id) {
	// TODO
}

User DatabaseInterface::getUser(long user_name) {
	// TODO
}
