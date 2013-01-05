#include "DatabaseInterface.h"


DatabaseInterface::DatabaseInterface() {
	databaseHandler = cppdb::session("mysql: database=pci_database; user=pci_user; password=pci_password");
}

DatabaseInterface::~DatabaseInterface() {
	// TODO Auto-generated destructor stub
	databaseHandler.~session();
}

Problem *DatabaseInterface::getProblem(long id) {

	Problem *problem;

	cppdb::result result = databaseHandler << "SELECT * FROM Problem WHERE id = ?" << id;
	problem = new Problem();
	// TODO: set the problem attributes

	return problem;
}

list<Problem>* DatabaseInterface::searchProblems(/* TODO: define parameters */) {
	// TODO
	return new list<Problem>;
}

Solution *DatabaseInterface::getSolution(long id) {

	Solution *solution;

	cppdb::result result = databaseHandler << "SELECT * FROM Solution WHERE id = ?" << id;
	solution = new Solution();
	// TODO: set the solution attributes

	return solution;
}

list<Solution>* DatabaseInterface::searchSolutions(long problem_id) {
	// TODO
	return new list<Solution>;
}

Clarification *DatabaseInterface::getClarification(long id) {

	Clarification *clarification;

	cppdb::result result = databaseHandler << "SELECT * FROM Clarification WHERE id = ?" << id;
	clarification = new Clarification();
	// TODO: set the clarification attributes

	return clarification;
}

list<Clarification>* DatabaseInterface::searchClarifications(long associated_publication_id) {
	// TODO
	list<Clarification>* lista = new list<Clarification>();
	Clarification *clarification;
	string answer;
	string creator_user_name;
	long id;
	string question;

	cppdb::result result = databaseHandler << "SELECT * FROM Clarification WHERE id = ?" << associated_publication_id;

	while (result.next()) {
		result.fetch("answer", answer);
		result.fetch("user_name", creator_user_name);
		result.fetch("id", id);
		result.fetch("question", question);

		// TODO: check attribute setters
		clarification = new Clarification();
		clarification->setAnswer(answer);
		clarification->setId(id);
		clarification->setQuestion(question);
		lista->push_back(*clarification);
	}

	return lista;
}

User *DatabaseInterface::getUser(long user_name) {
	// TODO
	return 0;
}
