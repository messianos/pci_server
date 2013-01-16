
// Includes
#include "Server.h"

// Namespaces
using namespace ViewContent;
using namespace cppcms;
using namespace std;

Server::Server(cppcms::service &service) : application(service) {

	dispatcher().assign("", &Server::welcome, this);
	mapper().assign("");

	dispatcher().assign("/sign_in", &Server::signIn, this);
	mapper().assign("sign_in", "/sign_in");

	dispatcher().assign("/problems", &Server::problems, this);
	mapper().assign("problems", "/problems");

	dispatcher().assign("/problem/(50\\w{32,32})", &Server::problem, this, 1);
	mapper().assign("problem", "/problem/{1}");

	dispatcher().assign("/solution/(53\\w{32,32})", &Server::solution, this, 1);
	mapper().assign("solution", "/solution/{1}");

	dispatcher().assign("/ideas", &Server::ideas, this);
	mapper().assign("ideas", "/ideas");

	mapper().root("/pci");
}

Server::~Server() {}

void Server::welcome() {
	WelcomeContent content;
	content.page_title = "Welcome";
	render("welcome_view", content);
}

void Server::signIn() {
	SignInContent content;
	content.page_title = "Sign in";
	render("sign_in_view", content);
}

void Server::problems() {
	ProblemsContent content;
	content.page_title = "Problems";
	content.problems = DatabaseInterface::searchProblemsRandom(10);
	render("problems_view", content);
}

void Server::problem(string id) {
	ProblemContent content;

	content.page_title = "Problem " + id;
	Problem *problem = DatabaseInterface::searchProblem(id);
	content.problem = problem;
	if (problem->is_solved)
		content.accepted_solution = DatabaseInterface::searchSolution(problem->accepted_solution_id);
	else
		content.accepted_solution = NULL;
	content.solutions = DatabaseInterface::searchSolutions(id);
	content.clarifications = DatabaseInterface::searchClarifications(id);

	render("problem_view", content);
}

void Server::solution(string id) {
	SolutionContent content;

	content.page_title = "Solution " + id;
	content.solution = DatabaseInterface::searchSolution(id);
	content.clarifications = DatabaseInterface::searchClarifications(id);

	render("solution_view", content);
}

void Server::ideas() {
	IdeasContent content;
	content.page_title = "Ideas";
	render("ideas_view", content);
}
