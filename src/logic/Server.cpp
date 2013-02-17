// Includes
#include "Server.h"

// Namespaces
using namespace boost;
using namespace cppcms;
using namespace std;
using namespace ViewContent;

bool Server::getRequestReceived() {
	return request().request_method() == "GET";
}

bool Server::postRequestReceived() {
	return request().request_method() == "POST";
}

string Server::postRequestData(string name) {
	return request().post(name);
}

void Server::setSessionProperties(TemplateContent &content) {
	content.user_signed_in = session().is_set("session_user_signed_in");
	content.anonymous_mode = session().is_set("session_anonymous_mode");
	content.user_name = session()["session_user_name"];
	content.user_first_name = session()["session_first_name"];
	content.user_last_name = session()["session_last_name"];
}

void Server::debug() {
	ViewContent::TemplateContent content;
	render("debug_view", content);
}

Server::Server(cppcms::service &service) :
		application(service) {

	/* TODO: remove this (debugging purposes) */
	dispatcher().assign("/debug", &Server::debug, this);
	mapper().assign("debug", "/debug");

	// Session services
	dispatcher().assign("/sign_in", &Server::postSignIn, this);
	mapper().assign("sign_in", "/sign_in");
	dispatcher().assign("/sign_out", &Server::postSignOut, this);
	mapper().assign("sign_out", "/sign_out");
	dispatcher().assign("/toggle_anonymous_mode", &Server::postToggleAnonymousMode, this);
	mapper().assign("toggle_anonymous_mode", "/toggle_anonymous_mode");

	// Database-querying services

	// Database-updating services
	dispatcher().assign("/create_user", &Server::postCreateUser, this);
	mapper().assign("create_user", "/create_user");
	/*dispatcher().assign("/delete_user", &Server::postDeleteUser, this);
	mapper().assign("delete_user", "/delete_user");*/
	dispatcher().assign("/create_problem", &Server::postCreateProblem, this);
	mapper().assign("create_problem", "/create_problem");
	dispatcher().assign("/edit_problem", &Server::postEditProblem, this);
	mapper().assign("edit_problem", "/edit_problem");
	/*dispatcher().assign("/delete_problem", &Server::postDeleteProblem, this);
	mapper().assign("delete_problem", "/delete_problem");*/
	dispatcher().assign("/vote_problem", &Server::postVoteProblem, this);
	mapper().assign("vote_problem", "/vote_problem");
	dispatcher().assign("/create_solution", &Server::postCreateSolution, this);
	mapper().assign("create_solution", "/create_solution");
	dispatcher().assign("/edit_solution", &Server::postEditSolution, this);
	mapper().assign("edit_solution", "/edit_solution");
	/*dispatcher().assign("/delete_solution", &Server::postDeleteSolution, this);
	mapper().assign("delete_solution", "/delete_solution");*/
	dispatcher().assign("/vote_solution", &Server::postVoteSolution, this);
	mapper().assign("vote_solution", "/vote_solution");
	dispatcher().assign("/create_clarification", &Server::postCreateClarification, this);
	mapper().assign("create_clarification", "/create_clarification");
	dispatcher().assign("/answer_clarification", &Server::postAnswerClarification, this);
	mapper().assign("answer_clarification", "/answer_clarification");
	/*dispatcher().assign("/delete_clarification", &Server::postDeleteClarification, this);
	mapper().assign("delete_clarification", "/delete_clarification");*/

	dispatcher().assign("/set_accepted_solution", &Server::postSetAcceptedSolution, this);
	mapper().assign("set_accepted_solution", "/set_accepted_solution");

	dispatcher().assign("/unset_accepted_solution", &Server::postUnsetAcceptedSolution, this);
	mapper().assign("unset_accepted_solution", "/unset_accepted_solution");


	// Page-fetching services
	dispatcher().assign("", &Server::getFetchMainPage, this);
	mapper().assign("");
	dispatcher().assign("/user/(\\w+)", &Server::getFetchUserPage, this, 1);
	mapper().assign("user", "/user/{1}");
	dispatcher().assign("/problems", &Server::getFetchProblemsPage, this);
	mapper().assign("problems", "/problems");
	dispatcher().assign("/publication/(50\\w{32,32})", &Server::getFetchProblemPage, this, 1);
	mapper().assign("publication", "/publication/{1}");
	dispatcher().assign("/publication/(50\\w{32,32})/(53\\w{32,32})", &Server::getFetchSolutionPage, this, 1, 2);
	mapper().assign("publication", "/publication/{1}/{2}");
	dispatcher().assign("/new_problem", &Server::getFetchNewProblemPage, this);
	mapper().assign("new_problem", "/new_problem");
	dispatcher().assign("/new_solution/(50\\w{32,32})", &Server::getFetchNewSolutionPage, this, 1);
	mapper().assign("new_solution", "/new_solution/{1}");
	dispatcher().assign("/ideas", &Server::getFetchIdeasPage, this);
	mapper().assign("ideas", "/ideas");

	mapper().root("/pci");
}

Server::~Server() {
}

#include <iostream> // TODO: remove this
void Server::postSignIn() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		// TODO: password should be send using HTTPS (does that change this method?)
		string user_name = postRequestData("user_name");
		string password = postRequestData("password");

		ErrorCode *error_code;
		error_code = InputValidator::validateSignInInput(user_name, password);
		if (error_code->isAnError())
			response().status(http::response::bad_request, error_code->getErrorDescription());
		else {
			string encrypted_password = PasswordManager::encryptPassword(password);

			/*
			 * A sign in failed attempt is not a HTTP error.
			 * Instead of responding with a HTTP error code, the
			 * server sends a specific message to the client.
			 */

			json::value json_response = json::value();
			if (!DatabaseInterface::signInUser(user_name, encrypted_password)) {
				json_response["user_signed_in"] = false;
			} else {
				User *user = DatabaseInterface::searchUser(user_name);
				session()["session_user_signed_in"] = "";
				//session()["session_anonymous_mode"] = ""; TODO --> SET or NOT this key according to user preferences
				session()["session_user_name"] = user_name;
				session()["session_first_name"] = user->first_name;
				session()["session_last_name"] = user->last_name;
				json_response["user_signed_in"] = true;
			}

			response().out() << json_response;
			response().status(http::response::ok);
		}
	}
}

void Server::postSignOut() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else
		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			session().clear();
			response().status(http::response::ok);
		}
}

void Server::postToggleAnonymousMode() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else
		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			json::value json_response = json::value();

			if (session().is_set("session_anonymous_mode")) {
				session().erase("session_anonymous_mode");
				json_response["anonymous_mode"] = false;
			} else {
				session()["session_anonymous_mode"] = "";
				json_response["anonymous_mode"] = true;
			}

			response().out() << json_response;
			response().status(http::response::ok);
		}
}

void Server::postCreateUser() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		// TODO: password should be send using HTTPS (does that change this method?)
		string birth_date = postRequestData("birth_date");
		string email = postRequestData("email");
		string first_name = postRequestData("first_name");
		trim(first_name);
		string genre = postRequestData("genre");
		string last_name = postRequestData("last_name");
		trim(last_name);
		string location = postRequestData("location");
		trim(location);
		string password = postRequestData("password");
		string user_name = postRequestData("user_name");

		ErrorCode *error_code;
		error_code = InputValidator::validateCreateUserInput(birth_date, email, first_name, genre, last_name, location,
				password, user_name);
		if (error_code->isAnError())
			response().status(http::response::bad_request, error_code->getErrorDescription());
		else {
			User *user = new User();
			user->birth_date = new Date("%d/%m/%Y", birth_date);
			user->email = email;
			user->first_name = first_name;
			user->genre = genre;
			user->last_name = last_name;
			user->location = location;
			user->user_name = user_name;
			string encrypted_password = PasswordManager::encryptPassword(password);

			error_code = DatabaseInterface::signUpUser(user, encrypted_password);
			if (error_code->isAnError())
				response().status(http::response::internal_server_error, error_code->getErrorDescription());
			else
				response().status(http::response::ok);
		}
	}
}

/*void Server::postDeleteUser() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		// TODO
	}
}*/

void Server::postCreateProblem() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		bool is_anonymous = session().is_set("session_anonymous_mode");
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string content = postRequestData("content");
			trim(content);
			string description = postRequestData("description");
			trim(description);

			ErrorCode *error_code;
			error_code = InputValidator::validateCreateProblemInput(content, description);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Problem *problem = new Problem();
				problem->content = content;
				problem->creator_user_name = user_name;
				problem->description = description;
				problem->id = IdManager::generateProblemID();
				problem->is_anonymous = is_anonymous;

				error_code = DatabaseInterface::insertProblem(problem);
				if (error_code->isAnError())
					response().status(http::response::internal_server_error, error_code->getErrorDescription());
				else {
					json::value json_response = json::value();
					json_response["problem_id"] = problem->id;
					response().out() << json_response;
					response().status(http::response::ok);
				}
			}
		}
	}
}

void Server::postEditProblem() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		// TODO
	}
}

/*void Server::postDeleteProblem() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string problem_id = postRequestData("problem_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateDeleteProblemInput(problem_id);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Problem *problem = DatabaseInterface::searchProblem(problem_id);

				if (problem == NULL || user_name.compare(problem->creator_user_name) != 0)
					response().status(http::response::forbidden);
				else {
					error_code = DatabaseInterface::deleteProblem(problem_id);
					if (error_code->isAnError())
						response().status(http::response::internal_server_error, error_code->getErrorDescription());
					else
						response().status(http::response::ok);
				}
			}
		}
	}
}*/

void Server::postVoteProblem() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {

			/*
			 * TODO: DOUBTS
			 * Can a user vote it's own publication?
			 * Does the SQL stored procedure checks whether the user has already voted the publication?
			 */

			string is_positive = postRequestData("is_positive");
			string problem_id = postRequestData("problem_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateVoteProblemInput(is_positive, problem_id);

			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				bool is_positive_boolean = is_positive.compare("true") == 0;

				error_code = DatabaseInterface::voteProblem(problem_id, user_name, is_positive_boolean);
				if (error_code->isAnError())
					response().status(http::response::internal_server_error, error_code->getErrorDescription());
				else {
					json::value json_response = json::value();
					json_response["vote_balance"] = 5; // FIXME: get actual vote_balance ---> NEED DATABASEINTERFACE METHOD
					response().out() << json_response;
					response().status(http::response::ok);
				}
			}
		}
	}
}

void Server::postSetAcceptedSolution() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string problem_id = postRequestData("problem_id");
			string solution_id = postRequestData("solution_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateSetAcceptedSolutionInput(problem_id, solution_id);
			cerr << error_code->getErrorDescription() << endl;
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Problem *problem = DatabaseInterface::searchProblem(problem_id);

				// TODO: what to do in case of NULL?? BAD_REQUEST??? CHECK THIS !!!

				if (problem == NULL || user_name.compare(problem->creator_user_name) != 0)
					response().status(http::response::forbidden);
				else {
					error_code = DatabaseInterface::setAcceptedSolution(problem_id, solution_id);
					if (error_code->isAnError())
						response().status(http::response::internal_server_error, error_code->getErrorDescription());
					else
						response().status(http::response::ok);
				}
			}
		}
	}
}

void Server::postUnsetAcceptedSolution() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string problem_id = postRequestData("problem_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateUnsetAcceptedSolutionInput(problem_id);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Problem *problem = DatabaseInterface::searchProblem(problem_id);

				// TODO: what to do in case of NULL?? BAD_REQUEST??? CHECK THIS !!!

				if (problem == NULL || user_name.compare(problem->creator_user_name) != 0)
					response().status(http::response::forbidden);
				else {
					error_code = DatabaseInterface::unsetAcceptedSolution(problem_id);
					if (error_code->isAnError())
						response().status(http::response::internal_server_error, error_code->getErrorDescription());
					else
						response().status(http::response::ok);
				}
			}
		}
	}
}

void Server::postCreateSolution() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		bool is_anonymous = session().is_set("session_anonymous_mode");
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string content = postRequestData("content");
			trim(content);
			string description = postRequestData("description");
			trim(description);
			string problem_id = postRequestData("problem_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateCreateSolutionInput(content, description, problem_id);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Solution *solution = new Solution();
				solution->content = content;
				solution->creator_user_name = user_name;
				solution->description = description;
				solution->id = IdManager::generateSolutionID();
				solution->is_anonymous = is_anonymous;

				error_code = DatabaseInterface::insertSolution(solution, problem_id);
				if (error_code->isAnError())
					response().status(http::response::internal_server_error, error_code->getErrorDescription());
				else {
					json::value json_response = json::value();
					json_response["solution_id"] = solution->id;
					response().out() << json_response;
					response().status(http::response::ok);
				}
			}
		}
	}
}

void Server::postEditSolution() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		// TODO
	}
}

/*void Server::postDeleteSolution() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string solution_id = postRequestData("solution_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateDeleteSolutionInput(solution_id);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Solution *solution = DatabaseInterface::searchSolution(solution_id);

				if (solution == NULL || user_name.compare(solution->creator_user_name) != 0)
					response().status(http::response::forbidden);
				else {

					error_code = DatabaseInterface::deleteSolution(solution_id);
					if (error_code->isAnError())
						response().status(http::response::internal_server_error, error_code->getErrorDescription());
					else
						response().status(http::response::ok);
				}
			}
		}
	}
}*/

void Server::postVoteSolution() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {

			/*
			 * TODO: DOUBTS
			 * Can a user vote it's own publication?
			 * Does the SQL stored procedure checks whether the user has already voted the publication?
			 */

			string is_positive = postRequestData("is_positive");
			string solution_id = postRequestData("solution_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateVoteSolutionInput(is_positive, solution_id);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				bool is_positive_boolean = is_positive.compare("true") == 0;

				//error_code = DatabaseInterface::voteSolution(solution_id, user_name, is_positive_boolean); FIXME----> NEED THE METHOD
				if (error_code->isAnError())
					response().status(http::response::internal_server_error, error_code->getErrorDescription());
				else {
					json::value json_response = json::value();
					json_response["vote_balance"] = 5; // FIXME: get actual vote_balance ---> NEED DATABASEINTERFACE METHOD
					response().out() << json_response;
					response().status(http::response::ok);
				}
			}
		}
	}
}

void Server::postCreateClarification() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string associated_publication_id = postRequestData("associated_publication_id");
			string question = postRequestData("question");
			trim(question);

			ErrorCode *error_code;
			error_code = InputValidator::validateCreateClarificationInput(associated_publication_id, question);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Clarification *clarification = new Clarification();
				clarification->associated_publication_id = associated_publication_id;
				clarification->creator_user_name = user_name;
				clarification->id = IdManager::generateClarificationID();
				clarification->question = question;

				error_code = DatabaseInterface::insertClarification(clarification);
				if (error_code->isAnError())
					response().status(http::response::internal_server_error, error_code->getErrorDescription());
				else
					response().status(http::response::ok);
			}
		}
	}
}

void Server::postAnswerClarification() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string answer = postRequestData("answer");
			trim(answer);
			string clarification_id = postRequestData("clarification_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateAnswerClarificationInput(answer, clarification_id);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Clarification *clarification = DatabaseInterface::searchClarification(clarification_id);

				if (clarification == NULL)
					; // TODO: DO SOMETHING !!! PREVENT CRASHES FROM NULL POINTER
				else {
					//Publication *publication = DatabaseInterface::searchPublication(clarification->associated_publication_id);  TODO --> NEED THIS METHOD
					/*
					if (user_name.compare(publication->creator_user_name) != 0)
						response().status(http::response::forbidden);
					else {
						//error_code = DatabaseInterface::(clarification_id, answer); TODO --> NEED THIS METHOD
						if (error_code->isAnError())
							response().status(http::response::internal_server_error, error_code->getErrorDescription());
						else
							response().status(http::response::ok);
					}
					*/
				}
			}
		}
	}
}

/*void Server::postDeleteClarification() {
	if (!postRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		string user_name = session()["session_user_name"];

		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			string clarification_id = postRequestData("clarification_id");

			ErrorCode *error_code;
			error_code = InputValidator::validateDeleteClarificationInput(clarification_id);
			if (error_code->isAnError())
				response().status(http::response::bad_request, error_code->getErrorDescription());
			else {
				Clarification *clarification = DatabaseInterface::searchClarification(clarification_id);

				if (clarification == NULL || user_name.compare(clarification->creator_user_name) != 0)
					response().status(http::response::forbidden);
				else {
					error_code = DatabaseInterface::deleteClarification(clarification_id);
					if (error_code->isAnError())
						response().status(http::response::internal_server_error, error_code->getErrorDescription());
					else
						response().status(http::response::ok);
				}
			}
		}
	}
}*/

void Server::getFetchMainPage() {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		IndexContent content;

		setSessionProperties(content);
		content.page_title = "PCI";

		render("index_view", content);
	}
}

void Server::getFetchUserPage(string user_name) {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		UserContent content;

		setSessionProperties(content);

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
}

void Server::getFetchProblemsPage() {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		ProblemsContent content;

		setSessionProperties(content);

		content.page_title = "Problemas";

		content.random_problems = DatabaseInterface::searchProblemsRandom(20);
		content.unsolved_problems = DatabaseInterface::searchProblemsUnsolved(20);
		content.latest_problems = DatabaseInterface::searchProblemsLatest(20);

		render("problems_view", content);
	}
}

void Server::getFetchProblemPage(string problem_id) {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		ProblemContent content;

		setSessionProperties(content);

		Problem *problem = DatabaseInterface::searchProblem(problem_id);
		content.problem = problem;
		content.page_title = "PCI - " + problem->description;

		if (problem->is_solved)
			content.accepted_solution = DatabaseInterface::searchAcceptedSolution(problem->id);
		else
			content.accepted_solution = NULL;

		content.solutions = DatabaseInterface::searchSolutions(problem_id);
		content.clarifications = DatabaseInterface::searchClarifications(problem_id);

		render("problem_view", content);
	}
}

void Server::getFetchSolutionPage(string problem_id, string solution_id) {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		SolutionContent content;

		setSessionProperties(content);

		content.page_title = "PCI - Solución " + solution_id;
		content.solution = DatabaseInterface::searchSolution(solution_id);
		content.clarifications = DatabaseInterface::searchClarifications(solution_id);
		content.problem_id = problem_id;

		render("solution_view", content);
	}
}

void Server::getFetchNewProblemPage() {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else
		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			NewProblemContent content;

			setSessionProperties(content);
			content.page_title = "Nuevo problema";

			render("new_problem_view", content);
		}
}

void Server::getFetchNewSolutionPage(string problem_id) {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else
		if (!session().is_set("session_user_signed_in"))
			response().status(http::response::unauthorized);
		else {
			NewSolutionContent content;

			setSessionProperties(content);
			content.page_title = "Nueva solución";
			content.problem_id = problem_id;

			render("new_solution_view", content);
		}
}

void Server::getFetchIdeasPage() {
	if (!getRequestReceived())
		response().status(http::response::method_not_allowed);
	else {
		IdeasContent content;

		setSessionProperties(content);
		content.page_title = "PCI - Ideas";

		render("ideas_view", content);
	}
}
