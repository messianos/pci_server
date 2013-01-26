// Includes
#include "Server.h"

// Namespaces
using namespace ViewContent;
using namespace cppcms;
using namespace std;

Server::Server(cppcms::service &service) :
		application(service) {

	dispatcher().assign("/ideas", &Server::ideas, this);
	mapper().assign("ideas", "/ideas");

	// TODO: NO BORRES LO QUE HICE SI LO VAS A DEJAR IGUAL
	dispatcher().assign("", &Server::problems, this);
	mapper().assign("");

	dispatcher().assign("/new_problem", &Server::newProblem, this);
	mapper().assign("new_problem", "/new_problem");

	dispatcher().assign("/new_solution/(50\\w{32,32})", &Server::newSolution, this, 1);
	mapper().assign("new_solution", "/new_solution/{1}");

	dispatcher().assign("/problem/(50\\w{32,32})", &Server::problem, this, 1);
	mapper().assign("problem", "/problem/{1}");

	dispatcher().assign("/problems", &Server::problems, this);
	mapper().assign("problems", "/problems");

	dispatcher().assign("/sign_in", &Server::signIn, this);
	mapper().assign("sign_in", "/sign_in");

	dispatcher().assign("/sign_out", &Server::signOut, this);
	mapper().assign("sign_out", "/sign_out");

	dispatcher().assign("/sign_up", &Server::signUp, this);
	mapper().assign("sign_up", "/sign_up");

	dispatcher().assign("/solution/(53\\w{32,32})", &Server::solution, this, 1);
	mapper().assign("solution", "/solution/{1}");

	dispatcher().assign("/user/(\\w+)", &Server::user, this, 1);
	mapper().assign("user", "/user/{1}");

	mapper().root("/pci");
}

Server::~Server() {
}

void Server::setSessionProperties(TemplateContent& content) {
	content.user_signed_in = session().is_set("signed_in");
	content.user_name = session()["user_name"];
	content.user_first_name = session()["user_first_name"];
	content.user_last_name = session()["user_last_name"];
}

void Server::ideas() {
	IdeasContent content;

	setSessionProperties(content);
	content.page_title = "PCI - Ideas";

	render("ideas_view", content);
}

void Server::index() {
	IndexContent content;

	setSessionProperties(content);
	content.page_title = "PCI";

	render("index_view", content);
}

void Server::newProblem() {
	NewProblemContent content;

	setSessionProperties(content);
	content.page_title = "Nuevo problema";

	NewProblemFormInfo* form_info = &content.form_info;
	if (request().request_method() == "POST") {
		// POST message received
		form_info->load(context());

		ErrorCode *error_code;

		error_code = InputValidator::validateNewProblemInput(form_info);
		if (error_code->isAnError()) {
			// Invalid input
			content.successful_submit = false;
			content.error_description = error_code->getErrorDescription();
		} else {
			// Valid input

			Problem *problem = new Problem();
			problem->content = form_info->content.value();
			problem->creator_user_name = session()["user_name"];
			problem->description = form_info->description.value();
			problem->id = IDManager::generateProblemID();
			problem->is_anonymous = form_info->is_anonymous.value();

			error_code = DatabaseInterface::insertProblem(problem);
			if (error_code->isAnError()) {
				content.successful_submit = false;
				content.error_description = error_code->getErrorDescription();
			} else
				content.successful_submit = true;

			// TODO: Redirect
		}
	}

	render("new_problem_view", content);
}

void Server::newSolution(string problem_id) {
	NewSolutionContent content;

	setSessionProperties(content);
	content.page_title = "Nueva Solucion";

	NewSolutionFormInfo* form_info = &content.form_info;
	if (request().request_method() == "POST") {
		// POST message received
		form_info->load(context());

		ErrorCode *error_code;

		error_code = InputValidator::validateNewSolutionInput(form_info);
		if (error_code->isAnError()) {
			// Invalid input
			content.successful_submit = false;
			content.error_description = error_code->getErrorDescription();
		} else {
			// Valid input

			Solution *solution = new Solution();
			solution->content = form_info->content.value();
			solution->creator_user_name = session()["user_name"];
			solution->description = form_info->description.value();
			solution->id = IDManager::generateSolutionID();
			solution->is_anonymous = form_info->is_anonymous.value();

			error_code = DatabaseInterface::insertSolution(solution, problem_id);
			if (error_code->isAnError()) {
				content.successful_submit = false;
				content.error_description = error_code->getErrorDescription();
			} else
				content.successful_submit = true;

			// TODO: Redirect to problem
		}
	}

	render("new_solution_view", content);
}

void Server::problem(string id) {
	ProblemContent content;

	setSessionProperties(content);

	Problem *problem = DatabaseInterface::searchProblem(id);
	content.problem = problem;

	content.page_title = "PCI - " + problem->description;

	if (problem->is_solved)
		content.accepted_solution = DatabaseInterface::searchSolution(
				problem->accepted_solution_id);
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
	content.problems = DatabaseInterface::searchProblemsRandom(40);

	render("problems_view", content);
}

void Server::signIn() {

	// TODO: check session security and config options http://cppcms.com/wikipp/en/page/cppcms_1x_sessions

	if (session().is_set("signed_in")) {
		response().set_redirect_header(url(""));
		return;
	} else {
		// User not signed in

		SignInContent content;
		content.page_title = "PCI - Ingresar";

		SignInFormInfo* form_info = &content.form_info;
		if (request().request_method() == "POST") {
			// POST message received
			form_info->load(context());

			ErrorCode *error_code;

			error_code = InputValidator::validateSignInInput(form_info);
			if (error_code->isAnError()) {
				// Invalid input
				content.successful_submit = false;
				content.error_description = error_code->getErrorDescription();
			} else {
				// Valid input

				string user_name = form_info->user_name.value();
				string encrypted_password = PasswordManager::encryptPassword(
						form_info->password.value());

				error_code = DatabaseInterface::signInUser(user_name,
						encrypted_password);
				if (error_code->isAnError()) {
					content.successful_submit = false;
					content.error_description =
							error_code->getErrorDescription();
				} else {
					// User and password are valid
					content.successful_submit = true;

					User *user = DatabaseInterface::searchUser(user_name);
					session()["signed_in"] = "";
					session()["user_name"] = user_name;
					session()["user_first_name"] = user->first_name;
					session()["user_last_name"] = user->last_name;

					response().set_redirect_header(url(""));
					return;
				}
			}
		}

		render("sign_in_view", content);
	}
}

void Server::signOut() {
	session().erase("signed_in");
	session().erase("user_name");
	response().set_redirect_header(url(""));
}

void Server::signUp() {
	SignUpContent content;

	setSessionProperties(content);
	content.page_title = "PCI - Registrar";

	SignUpFormInfo* form_info = &content.form_info;
	if (request().request_method() == "POST") {
		// POST message received
		form_info->load(context());

		ErrorCode *error_code;

		error_code = InputValidator::validateSignUpInput(form_info);
		if (error_code->isAnError()) {
			// Invalid input
			content.successful_submit = false;
			content.error_description = error_code->getErrorDescription();
		} else {
			// Valid input

			short int day = form_info->day.selected();
			short int month = form_info->month.selected();
			int current_year = 2013; // TODO: auto calculate it
			short int year = current_year - form_info->year.selected() + 1;
			User* user = new User();
			user->birth_date = new Date(day, month, year);
			user->email = form_info->email.value();
			user->first_name = form_info->first_name.value();
			user->genre = form_info->genre.selected() == 0 ? "F" : "M";
			user->last_name = form_info->last_name.value();
			user->location = ""; // TODO: add location widget to form
			user->user_name = form_info->user_name.value();
			string encrypted_password = PasswordManager::encryptPassword(
					form_info->password.value());

			error_code = DatabaseInterface::signUpUser(user,
					encrypted_password);
			if (error_code->isAnError()) {
				content.successful_submit = false;
				content.error_description = error_code->getErrorDescription();
			} else {
				content.successful_submit = true;

				response().set_redirect_header(url(""));
				return;
			}
		}
	}

	render("sign_up_view", content);
}

void Server::solution(string id) {
	SolutionContent content;

	setSessionProperties(content);
	content.page_title = "PCI - Solución " + id;
	content.solution = DatabaseInterface::searchSolution(id);
	content.clarifications = DatabaseInterface::searchClarifications(id);

	render("solution_view", content);
}

void Server::user(string user_name) {
	UserContent content;

	setSessionProperties(content);
	content.page_title = "PCI - Perfil de " + user_name;
	content.user = DatabaseInterface::searchUser(user_name);

	// TODO: si el usuario no fue encontrado, enviar a pagina especial

	render("user_view", content);
}
