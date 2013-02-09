// Includes
#include "Server.h"
#include <iostream>// TODO: remove this (debugging purposes)
// Namespaces
using namespace ViewContent;
using namespace cppcms;
using namespace std;

Server::Server(cppcms::service &service) :
		application(service) {

	dispatcher().assign("/ideas", &Server::ideas, this);
	mapper().assign("ideas", "/ideas");

	dispatcher().assign("", &Server::index, this);
	mapper().assign("");

	dispatcher().assign("/new_clarification_answer", &Server::newClarificationAnswer, this);
	mapper().assign("new_clarification_answer", "/new_clarification_answer");

	dispatcher().assign("/new_problem", &Server::newProblem, this);
	mapper().assign("new_problem", "/new_problem");

	dispatcher().assign("/new_solution/(50\\w{32,32})", &Server::newSolution, this, 1);
	mapper().assign("new_solution", "/new_solution/{1}");

	dispatcher().assign("/publication/(50\\w{32,32})", &Server::problem, this, 1);
	mapper().assign("publication", "/publication/{1}");

	dispatcher().assign("/problems", &Server::problems, this);
	mapper().assign("problems", "/problems");

	dispatcher().assign("/sign_out", &Server::signOut, this);
	mapper().assign("sign_out", "/sign_out");

	dispatcher().assign("/publication/(50\\w{32,32})/(53\\w{32,32})", &Server::solution, this, 1, 2);
	mapper().assign("publication", "/publication/{1}/{2}");

	dispatcher().assign("/user/(\\w+)", &Server::user, this, 1);
	mapper().assign("user", "/user/{1}");

	mapper().root("/pci");
}

Server::~Server() {
}

void Server::setSessionProperties(TemplateContent &content) {
	content.user_signed_in = session().is_set("user_signed_in");
	content.user_name = session()["user_name"];
	content.user_first_name = session()["user_first_name"];
	content.user_last_name = session()["user_last_name"];
}

ErrorCode *Server::processNewProblemPost(ViewContent::NewProblemFormInfo &form_info) {
	ErrorCode *error_code;

	form_info.load(context());
	error_code = InputValidator::validateNewProblemInput(&form_info);
	if (!error_code->isAnError()) {
		// Valid input
		Problem *problem = new Problem();
		problem->content = form_info.content.value();
		problem->creator_user_name = session()["user_name"];
		problem->description = form_info.description.value();
		problem->id = IDManager::generateProblemID();
		problem->is_anonymous = form_info.is_anonymous.value();

		error_code = DatabaseInterface::insertProblem(problem);
		if (!error_code->isAnError())
			response().set_redirect_header(url("/publication", problem->id));
	}

	return error_code;
}

ErrorCode *Server::processNewSolutionPost(ViewContent::NewSolutionFormInfo &form_info, string problem_id) {
	ErrorCode *error_code;

	form_info.load(context());
	error_code = InputValidator::validateNewSolutionInput(&form_info);
	if (!error_code->isAnError()) {
		// Valid input
		Solution *solution = new Solution();
		solution->content = form_info.content.value();
		solution->creator_user_name = session()["user_name"];
		solution->description = form_info.description.value();
		solution->id = IDManager::generateSolutionID();
		solution->is_anonymous = form_info.is_anonymous.value();

		error_code = DatabaseInterface::insertSolution(solution, problem_id);
		if (!error_code->isAnError())
			response().set_redirect_header(url("/publication", problem_id));
	}

	return error_code;
}

ErrorCode *Server::processSignInPost(SignInFormInfo &form_info) {
	ErrorCode *error_code;

	form_info.load(context());
	error_code = InputValidator::validateSignInInput(&form_info);
	if (!error_code->isAnError()) {
		// Valid input
		string user_name = form_info.user_name.value();
		string encrypted_password = PasswordManager::encryptPassword(form_info.password.value());
		error_code = DatabaseInterface::signInUser(user_name, encrypted_password);
		if (!error_code->isAnError()) {
			// User and password are valid
			User *user = DatabaseInterface::searchUser(user_name);
			session()["user_signed_in"] = "";
			session()["user_name"] = user_name;
			session()["user_first_name"] = user->first_name;
			session()["user_last_name"] = user->last_name;
			response().set_redirect_header(url("/"));
		}
	}

	return error_code;
}

ErrorCode *Server::processSignUpPost(SignUpFormInfo &form_info) {
	ErrorCode *error_code;

	form_info.load(context());
	error_code = InputValidator::validateSignUpInput(&form_info);
	if (!error_code->isAnError()) {
		// Valid input
		User* user = new User();
		user->birth_date = new Date("%d-%m-%Y", form_info.birth_date.value().c_str());
		user->email = form_info.email.value();
		user->first_name = form_info.first_name.value();
		user->genre = form_info.genre.selected() == 0 ? "F" : "M";
		user->last_name = form_info.last_name.value();
		user->location = ""; // TODO: add location widget to form
		user->user_name = form_info.user_name.value();
		string encrypted_password = PasswordManager::encryptPassword(form_info.password.value());

		error_code = DatabaseInterface::signUpUser(user, encrypted_password);
		if (!error_code->isAnError())
			response().set_redirect_header(url("/"));
	}

	return error_code;
}

void Server::ideas() {
	IdeasContent content;

	setSessionProperties(content);
	content.page_title = "PCI - Ideas";

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);

		if (!content.error_code->isAnError())
			return;
	}

	render("ideas_view", content);
}

void Server::index() {
	IndexContent content;

	setSessionProperties(content);
	content.page_title = "PCI";

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);
		else if (form_name.compare("sign_up_form") == 0)
			content.error_code = processSignUpPost(content.sign_up_form_info);

		if (!content.error_code->isAnError())
			return;
	}

	render("index_view", content);
}

#include <iostream>
// TODO
void Server::newClarificationAnswer() {

	// TODO: security measurements ---> only the creator can answer a question

	if (request().request_method() == "POST") {
		// TODO
		cout << "Dumb method newClarificationAnswer() invoked with:" << endl;
		cout << "Clarification ID: " << request().post("id") << endl;
		cout << "Clarification answer: " << request().post("answer") << endl;
		cout << "You need to actual implement this method" << endl;
	}
}

void Server::newProblem() {
	NewProblemContent content;

	setSessionProperties(content);
	content.page_title = "Nuevo problema";

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);
		else if (form_name.compare("new_problem_form") == 0)
			content.error_code = processNewProblemPost(content.new_problem_form_info);

		if (!content.error_code->isAnError())
			return;
	}

	render("new_problem_view", content);
}

void Server::newSolution(string problem_id) {
	NewSolutionContent content;

	setSessionProperties(content);
	content.page_title = "Nueva solución";

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);
		else if (form_name.compare("new_solution_form") == 0)
			content.error_code = processNewSolutionPost(content.new_solution_form_info, problem_id);

		if (!content.error_code->isAnError())
			return;
	}

	render("new_solution_view", content);
}

void Server::problem(string id) {
	ProblemContent content;

	setSessionProperties(content);

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);

		if (!content.error_code->isAnError())
			return;
	}

	Problem *problem = DatabaseInterface::searchProblem(id);
	content.problem = problem;
	content.page_title = "PCI - " + problem->description;

	if (problem->is_solved)
		content.accepted_solution = DatabaseInterface::searchAcceptedSolution(problem->id);
	else
		content.accepted_solution = NULL;

	content.solutions = DatabaseInterface::searchSolutions(id);
	content.clarifications = DatabaseInterface::searchClarifications(id);

	render("problem_view", content);
}

void Server::problems() {
	ProblemsContent content;

	setSessionProperties(content);

	content.page_title = "Problemas";

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);

		if (!content.error_code->isAnError())
			return;
	}

	content.problems = DatabaseInterface::searchProblemsRandom(40);

	render("problems_view", content);
}

void Server::signOut() {
	session().erase("user_signed_in");
	session().erase("user_name");
	session().erase("user_first_name");
	session().erase("user_last_name");
	response().set_redirect_header(url("/"));
}

void Server::solution(string problem_id, string solution_id) {
	SolutionContent content;

	setSessionProperties(content);

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);

		if (!content.error_code->isAnError())
			return;
	}

	content.page_title = "PCI - Solución " + solution_id;
	content.solution = DatabaseInterface::searchSolution(solution_id);
	content.clarifications = DatabaseInterface::searchClarifications(solution_id);
	content.problem_id = problem_id;

	render("solution_view", content);
}

void Server::user(string user_name) {
	UserContent content;

	setSessionProperties(content);

	if (request().request_method() == "POST") {
		// POST message received
		string form_name = request().post("form_name");
		if (form_name.compare("sign_in_form") == 0)
			content.error_code = processSignInPost(content.sign_in_form_info);

		if (!content.error_code->isAnError())
			return;
	}

	content.page_title = "PCI - Perfil de " + user_name;
	content.user = DatabaseInterface::searchUser(user_name);
	content.number_of_solutions = DatabaseInterface::numberOfSolutionsByUser(user_name);
	content.number_of_problems = DatabaseInterface::numberOfProblemsByUser(user_name);
	content.number_of_publications = content.number_of_solutions + content.number_of_problems;

	content.number_of_accepted_solutions = DatabaseInterface::numberOfAcceptedSolutionsByUser(user_name);

	content.recent_activity = DatabaseInterface::getRecentActivityByUser(user_name);

	// TODO: si el usuario no fue encontrado, enviar a pagina especial

	render("user_view", content);
}
