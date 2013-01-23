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

	// FIXME: Index removed, until it has content
	dispatcher().assign("", &Server::problems, this);
	mapper().assign("");

	dispatcher().assign("/problem/(50\\w{32,32})", &Server::problem, this, 1);
	mapper().assign("problem", "/problem/{1}");

	dispatcher().assign("/problems", &Server::problems, this);
	mapper().assign("problems", "/problems");

	dispatcher().assign("/sign_in", &Server::signIn, this);
	mapper().assign("sign_in", "/sign_in");

	dispatcher().assign("/sign_up", &Server::signUp, this);
	mapper().assign("sign_up", "/sign_up");

	dispatcher().assign("/sign_out", &Server::signOut, this);
	mapper().assign("sign_out", "/sign_out");

	dispatcher().assign("/solution/(53\\w{32,32})", &Server::solution, this, 1);
	mapper().assign("solution", "/solution/{1}");

	mapper().root("/pci");
}

Server::~Server() {
}

void Server::ideas() {
	IdeasContent content;
	content.page_title = "Ideas";

	set_header_properties(content);

	render("ideas_view", content);
}

void Server::index() {
	IndexContent content;
	content.page_title = "PCI";

	set_header_properties(content);

	render("index_view", content);
}

void Server::problem(string id) {
	ProblemContent content;

	set_header_properties(content);

	content.page_title = "Problem " + id;
	Problem *problem = DatabaseInterface::searchProblem(id);
	content.problem = problem;
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

	set_header_properties(content);

	content.page_title = "Problems";
	content.problems = DatabaseInterface::searchProblemsRandom(40);
	render("problems_view", content);
}

void Server::set_header_properties(TemplateContent& content) {

	content.user_logged = session().is_set("signed_in");
	content.user_name = session()["user_name"];
}

void Server::signIn() {

	// TODO: check session security and config options http://cppcms.com/wikipp/en/page/cppcms_1x_sessions

	if (session().is_set("signed_in")) {

		response().set_redirect_header(url(""));
		return;

	} else {

		SignInContent content;
		content.page_title = "Sign in";

		// This lead to the major error of the forms:
		// SignInFormInfo form_info = content.form_info;
		// This is the correct way, because forms are non-copyable:
		SignInFormInfo* form_info = &content.form_info;

		if (request().request_method() == "POST") {

			// POST message received
			form_info->load(context());

			if (form_info->validate()) {

				// Input validated
				string user_name = form_info->user_name.value();
				string encrypted_password = PasswordManager::encryptPassword(
						form_info->password.value());

				if (DatabaseInterface::signInUser(user_name,
						encrypted_password)) {
					// User name and password are valid
					session()["signed_in"] = "";

					// TODO: Store the user object in some place
					User* user = DatabaseInterface::searchUser(user_name);

					session()["user_name"] = user->first_name;

					cerr << "successful login!" << endl;
					response().set_redirect_header(url(""));
					return;

				} else {
					cerr << "unsuccessful login !!" << endl; // TODO: else ---> deberia mostrar mensaje especial de invalidez
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

	set_header_properties(content);
	content.page_title = "Registrar";

	SignUpFormInfo* form_info = &content.form_info;

	if (request().request_method() == "POST") {

		// POST message received
		form_info->load(context());

		if (form_info->validate()) {

			// TODO: Make deeper validation: email correctness, etc.

			// Input validated
			string user_name = form_info->user_name.value();
			string encrypted_password = PasswordManager::encryptPassword(
					form_info->password.value());

			User* new_user = new User();

			// TODO: Should we use Boost's lib date?
			stringstream out;
			out << form_info->year.selected() << "-"
					<< form_info->month.selected() << "-"
					<< form_info->day.selected();
			new_user->birth_date = new Date("%Y-%M-%D", out.str());

			new_user->email = form_info->email.value();
			new_user->first_name = form_info->first_name.value();
			new_user->genre = "M"; // TODO: Ask for it
			new_user->last_name = form_info->last_name.value();
			new_user->location = "bahia"; // TODO: Ask for it
			new_user->sign_up_datetime = time(NULL);
			new_user->user_name = user_name;

			DatabaseInterface::signUpUser(new_user, encrypted_password);

			cerr << "successful registration!" << endl;
			response().set_redirect_header(url(""));
			return;

		} else {
			cerr << "unsuccessful registration !!" << endl; // TODO: else ---> deberia mostrar mensaje especial de invalidez
		}
	}

	render("sign_up_view", content);
}

void Server::solution(string id) {
	SolutionContent content;

	set_header_properties(content);

	content.page_title = "Solution " + id;
	content.solution = DatabaseInterface::searchSolution(id);
	content.clarifications = DatabaseInterface::searchClarifications(id);

	render("solution_view", content);
}
