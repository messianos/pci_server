
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

string Server::fetchPostData(string parameter) {
	return request().post(parameter);
}

bool Server::isSessionDataSet(string parameter) {
	return session().is_set(parameter);
}

string Server::fetchSessionData(string parameter) {
	return session()[parameter];
}

void Server::setSessionData(string parameter) {
	session()[parameter] = "";
}

void Server::setSessionData(string parameter, string value) {
	session()[parameter] = value;
}

void Server::clearSessionData() {
	session().clear();
}

void Server::clearSessionData(string parameter) {
	session().erase(parameter);
}

void Server::setSessionDataOnViewContent(SessionContent &content) {
	content.signed_in = isSessionDataSet("signed_in");
	content.user_name = fetchSessionData("user_name");
	content.anonymous_mode = isSessionDataSet("anonymous_mode");
	content.first_name = fetchSessionData("first_name");
	content.last_name = fetchSessionData("last_name");
}

void Server::renderErrorPage(int http_error_code, string server_error_code) {
	ErrorPageContent content;
	setSessionDataOnViewContent(content);
	content.http_error_code = http_error_code;
	content.server_error_code = server_error_code;
	render("error_view", content);
}

void Server::writeJsonResponse(json::value json_response) {
	response().out() << json_response;
}

void Server::setSuccessResponseStatus() {
	response().status(http::response::ok);
}

void Server::setErrorResponseStatus(int http_error_code, string server_error_code) {
	response().status(http_error_code, server_error_code);
}

Server::Server(cppcms::service &service) : application(service) {

	// Session services
	dispatcher().assign("/sign_in", &Server::signIn, this);
	mapper().assign("sign_in", "/sign_in");
	dispatcher().assign("/sign_out", &Server::signOut, this);
	mapper().assign("sign_out", "/sign_out");
	dispatcher().assign("/toggle_anonymous_mode", &Server::toggleAnonymousMode, this);
	mapper().assign("toggle_anonymous_mode", "/toggle_anonymous_mode");

	// Database-querying services
	dispatcher().assign("/user_exists", &Server::userExists, this);
	mapper().assign("user_exists", "/user_exists");
	dispatcher().assign("/unseen_notifications", &Server::unseenNotifications, this);
	mapper().assign("unseen_notifications", "/unseen_notifications");

	// Database-updating services
	dispatcher().assign("/sign_up", &Server::signUp, this);
	mapper().assign("sign_up", "/sign_up");
	dispatcher().assign("/publicate_problem", &Server::publicateProblem, this);
	mapper().assign("publicate_problem", "/publicate_problem");
	dispatcher().assign("/edit_problem", &Server::editProblem, this);
	mapper().assign("edit_problem", "/edit_problem");
	dispatcher().assign("/make_problem_creator_visible", &Server::makeProblemCreatorVisible, this);
	mapper().assign("make_problem_creator_visible", "/make_problem_creator_visible");
	dispatcher().assign("/vote_problem", &Server::voteProblem, this);
	mapper().assign("vote_problem", "/vote_problem");
	dispatcher().assign("/set_accepted_solution", &Server::setAcceptedSolution, this);
	mapper().assign("set_accepted_solution", "/set_accepted_solution");
	dispatcher().assign("/unset_accepted_solution", &Server::unsetAcceptedSolution, this);
	mapper().assign("unset_accepted_solution", "/unset_accepted_solution");
	dispatcher().assign("/publicate_solution", &Server::publicateSolution, this);
	mapper().assign("publicate_solution", "/publicate_solution");
	dispatcher().assign("/edit_solution", &Server::editSolution, this);
	mapper().assign("edit_solution", "/edit_solution");
	dispatcher().assign("/make_solution_creator_visible", &Server::makeSolutionCreatorVisible, this);
	mapper().assign("make_solution_creator_visible", "/make_solution_creator_visible");
	dispatcher().assign("/vote_solution", &Server::voteSolution, this);
	mapper().assign("vote_solution", "/vote_solution");
	dispatcher().assign("/ask_clarification", &Server::askClarification, this);
	mapper().assign("ask_clarification", "/ask_clarification");
	dispatcher().assign("/answer_clarification", &Server::answerClarification, this);
	mapper().assign("answer_clarification", "/answer_clarification");
	dispatcher().assign("/publicate_proposal", &Server::publicateProposal, this);
	mapper().assign("publicate_proposal", "/publicate_proposal");
	dispatcher().assign("/edit_proposal", &Server::editProposal, this);
	mapper().assign("edit_proposal", "/edit_proposal");
	dispatcher().assign("/make_proposal_creator_visible", &Server::makeProposalCreatorVisible, this);
	mapper().assign("make_proposal_creator_visible", "/make_proposal_creator_visible");
	dispatcher().assign("/vote_proposal", &Server::voteProposal, this);
	mapper().assign("vote_proposal", "/vote_proposal");

	// Page-fetching services
	dispatcher().assign("", &Server::fetchMainPage, this);
	mapper().assign("");
	dispatcher().assign("/user/(/^[A-Z][A-Z0-9_]{3,30}$/i)", &Server::fetchUserPage, this, 1);
	mapper().assign("user", "/user/{1}");
	dispatcher().assign("/problems", &Server::fetchProblemsPage, this);
	mapper().assign("problems", "/problems");
	dispatcher().assign("/publication/(/^50[A-F0-9]{32,32}$/i)", &Server::fetchProblemPage, this, 1);
	mapper().assign("publication", "/publication/{1}");
	dispatcher().assign("/publication/(/^53[A-F0-9]{32,32}$/i)", &Server::fetchSolutionPage, this, 1);
	mapper().assign("publication", "/publication/{1}");
	dispatcher().assign("/new_problem", &Server::fetchNewProblemPage, this);
	mapper().assign("new_problem", "/new_problem");
	dispatcher().assign("/new_solution/(/^50[A-F0-9]{32,32}$/i)", &Server::fetchNewSolutionPage, this, 1);
	mapper().assign("new_solution", "/new_solution/{1}");
	dispatcher().assign("/ideas", &Server::fetchIdeasPage, this);
	mapper().assign("ideas", "/ideas");

	mapper().root("/pci"); // TODO: when ready, change this to "/"
}

Server::~Server() {}

void Server::main(string url) {
	if (! dispatcher().dispatch(url)) {
		renderErrorPage(http::response::not_found, ServerError::BAD_URL);
		setErrorResponseStatus(http::response::not_found, ServerError::BAD_URL);
	}
}

void Server::signIn() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		// TODO: password should be send using HTTPS (does that change this method?)
		string password = fetchPostData("password");
		string user_name = fetchPostData("user_name");

		if (! InputValidator::isValidSignInInput(password, user_name)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		string encrypted_password = PasswordManager::encryptPassword(password);

		json::value json_response = json::value();
		if (! DatabaseInterface::signInUser(user_name, encrypted_password)) // TODO: check
			json_response["signed_in"] = false;
		else {
			json_response["signed_in"] = true;
			
			User *user = DatabaseInterface::searchUser(user_name); // TODO: check

			//setSessionData("anonymous_mode"); TODO --> SET or NOT this key according to user preferences
			setSessionData("signed_in");
			setSessionData("first_name", user->first_name);
			setSessionData("last_name", user->last_name);
			setSessionData("user_name", user_name);
		}

		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::signOut() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		clearSessionData();
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::toggleAnonymousMode() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}

		json::value json_response = json::value();
		if (isSessionDataSet("anonymous_mode")) {
			clearSessionData("anonymous_mode");
			json_response["anonymous_mode"] = false;
		} else {
			setSessionData("anonymous_mode");
			json_response["anonymous_mode"] = true;
		}

		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::userExists() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		string user_name = fetchPostData("user_name");

		if (! InputValidator::isValidUserExistsInput(user_name)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		json::value json_response = json::value();
		json_response["user_exists"] = DatabaseInterface::userExists(user_name); // TODO: check
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::unseenNotifications() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		list<Notification *> *notifications = DatabaseInterface::getUnseenNotifications(user_name); // TODO: check

		json::value json_response = json::value();
		json_response["notification_count"] = notifications->size();
		int i = 0;
		for (list<Notification *>::const_iterator it = notifications->begin(); it != notifications->end(); ++it) {
			json_response["notifications"][i]["event_code"] = (*it)->event_code;
			json_response["notifications"][i]["url"] = (*it)->url;
			i++;
		}

		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::signUp() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		// TODO: password should be send using HTTPS (does that change this method?)
		string birth_date = fetchPostData("birth_date");
		string email = fetchPostData("email");
		string first_name = fetchPostData("first_name");
		trim(first_name);
		string genre = fetchPostData("genre");
		string last_name = fetchPostData("last_name");
		trim(last_name);
		string location = fetchPostData("location");
		trim(location);
		string password = fetchPostData("password");
		string user_name = fetchPostData("user_name");
		
		if (! InputValidator::isValidSignUpInput(birth_date, email, first_name, genre, last_name, location, password, user_name)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		if (DatabaseInterface::userExists(user_name)) { // TODO: check
			setErrorResponseStatus(http::response::forbidden, ServerError::EXISTING_USER);
			return;
		}
		
		// TODO: check
		User *user = new User();
		user->birth_date = new Date("%d/%m/%Y", birth_date);
		user->email = email;
		user->first_name = first_name;
		user->genre = genre;
		user->last_name = last_name;
		user->location = location;
		user->user_name = user_name;
		string encrypted_password = PasswordManager::encryptPassword(password);
		DatabaseInterface::signUpUser(user, encrypted_password); // TODO: CHECK

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::publicateProblem() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		bool is_anonymous = isSessionDataSet("anonymous_mode");
		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string content = fetchPostData("content");
		trim(content);
		string description = fetchPostData("description");
		trim(description);
		
		if (! InputValidator::isValidPublicateProblemInput(content, description)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Problem *problem = new Problem();
		problem->content = content;
		problem->creator_user_name = user_name;
		problem->description = description;
		problem->id = IdManager::generateProblemID();
		problem->is_anonymous = is_anonymous;
		DatabaseInterface::insertProblem(problem); // TODO: check

		json::value json_response = json::value();
		json_response["problem_id"] = problem->id;
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::editProblem() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string content = fetchPostData("content");
		trim(content);
		string description = fetchPostData("description");
		trim(description);
		string problem_id = fetchPostData("problem_id");
		
		if (! InputValidator::isValidEditProblemInput(content, description, problem_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check

		if (problem == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}
		
		if (user_name.compare(problem->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::editProblem(problem_id, description, content); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::makeProblemCreatorVisible() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string problem_id = fetchPostData("problem_id");
		
		if (! InputValidator::isValidMakeProblemCreatorVisibleInput(problem_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}

		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check

		if (problem == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}
		
		if (user_name.compare(problem->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::makeProblemCreatorVisible(problem_id); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::voteProblem() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string is_positive = fetchPostData("is_positive");
		string problem_id = fetchPostData("problem_id");

		if (! InputValidator::isValidVoteProblemInput(is_positive, problem_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check

		if (problem == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}
		
		if (user_name.compare(problem->creator_user_name) == 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::voteProblem(problem_id, user_name, is_positive.compare("true") == 0); // TODO: check
		
		// TODO: NOTIFICATIONS
		
		json::value json_response = json::value();
		json_response["vote_balance"] = DatabaseInterface::getProblemVoteBalance(problem_id); // TODO: check
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::setAcceptedSolution() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}

		string problem_id = fetchPostData("problem_id");
		string solution_id = fetchPostData("solution_id");
		
		if (! InputValidator::isValidSetAcceptedSolutionInput(problem_id, solution_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check
		
		if (problem == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}
		
		Solution *solution = DatabaseInterface::searchSolution(solution_id); // TODO: check
		
		if (solution == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
			return;
		}
		
		if (user_name.compare(problem->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::setAcceptedSolution(problem_id, solution_id); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::unsetAcceptedSolution() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}

		string problem_id = fetchPostData("problem_id");
		
		if (! InputValidator::isValidUnsetAcceptedSolutionInput(problem_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check
		
		if (problem == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}
		
		if (user_name.compare(problem->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::unsetAcceptedSolution(problem_id, solution_id); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::publicateSolution() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		bool is_anonymous = isSessionDataSet("anonymous_mode");
		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string content = fetchPostData("content");
		trim(content);
		string description = fetchPostData("description");
		trim(description);
		string problem_id = fetchPostData("problem_id");
		
		if (! InputValidator::isValidPublicateSolutionInput(content, description, problem_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check
		
		if (problem == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}
		
		Solution *solution = new Solution();
		solution->content = content;
		solution->creator_user_name = user_name;
		solution->description = description;
		solution->id = IdManager::generateSolutionID();
		solution->is_anonymous = is_anonymous;
		DatabaseInterface::insertSolution(solution, problem_id); // TODO: check

		// TODO: NOTIFICATION
		
		json::value json_response = json::value();
		json_response["solution_id"] = solution->id;
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::editSolution() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string content = fetchPostData("content");
		trim(content);
		string description = fetchPostData("description");
		trim(description);
		string solution_id = fetchPostData("solution_id");
		
		if (! InputValidator::isValidEditSolutionInput(content, description, solution_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Solution *solution = DatabaseInterface::searchSolution(solution_id); // TODO: check

		if (solution == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
			return;
		}
		
		if (user_name.compare(solution->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::editSolution(solution_id, description, content); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::makeSolutionCreatorVisible() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string solution_id = fetchPostData("solution_id");
		
		if (! InputValidator::isValidMakeSolutionCreatorVisibleInput(solution_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}

		Solution *solution = DatabaseInterface::searchSolution(solution_id); // TODO: check

		if (solution == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
			return;
		}
		
		if (user_name.compare(solution->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::makeSolutionCreatorVisible(solution_id); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::voteSolution() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string is_positive = fetchPostData("is_positive");
		string solution_id = fetchPostData("solution_id");

		if (! InputValidator::isValidVoteSolutionInput(is_positive, solution_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Solution *solution = DatabaseInterface::searchSolution(solution_id); // TODO: check

		if (solution == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
			return;
		}
		
		if (user_name.compare(solution->creator_user_name) == 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::voteSolution(solution_id, user_name, is_positive.compare("true") == 0); // TODO: check
		
		// TODO: NOTIFICATIONS
		
		json::value json_response = json::value();
		json_response["vote_balance"] = DatabaseInterface::getSolutionVoteBalance(solution_id); // TODO: check
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::askClarification() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string publication_id = fetchPostData("publication_id");
		string question = fetchPostData("question");
		trim(question);

		if (! InputValidator::isValidAskClarificationInput(publication_id, question)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		if (publication_id[1] == '0') {
			Problem *publication = DatabaseInterface::searchProblem(publication_id); // TODO: check
			
			if (publication == NULL) {
				setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
				return;
			}
		} else {
			Solution *publication = DatabaseInterface::searchSolution(publication_id); // TODO: check
			
			if (publication == NULL) {
				setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
				return;
			}
		}
		
		if (user_name.compare(publication->creator_user_name) == 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		Clarification *clarification = new Clarification();
		clarification->creator_user_name = user_name;
		clarification->id = IdManager::generateClarificationID();
		clarification->question = question;
		clarification->publication_id = publication_id;
		DatabaseInterface::insertClarification(clarification); // TODO: check
		
		// TODO: NOTIFICATIONS

		json::value json_response = json::value();
		json_response["clarification_id"] = clarification->id;
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::answerClarification() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string answer = fetchPostData("answer");
		trim(answer);
		string clarification_id = fetchPostData("clarification_id");

		if (! InputValidator::isValidAnswerClarificationInput(answer, clarification_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Clarification *clarification = DatabaseInterface::searchClarification(clarification_id); // TODO: check
		
		if (clarification == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_CLARIFICATION);
			return;
		}

		string publication_id = clarification->publication_id;
		
		if (publication_id[1] == '0')
			Problem *publication = DatabaseInterface::searchProblem(publication_id); // TODO: check
		else
			Solution *publication = DatabaseInterface::searchSolution(publication_id); // TODO: check
		
		if (user_name.compare(publication->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::publicateProposal() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		bool is_anonymous = isSessionDataSet("anonymous_mode");
		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string content = fetchPostData("content");
		trim(content);
		string solution_id = fetchPostData("solution_id");
		
		if (! InputValidator::isValidPublicateProposalInput(content, solution_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Solution *solution = DatabaseInterface::searchSolution(solution_id); // TODO: check
		
		if (solution == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
			return;
		}
		
		if (user_name.compare(solution->creator_user_name) == 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		Proposal *proposal = new Proposal();
		proposal->content = content;
		proposal->creator_user_name = user_name;
		proposal->id = IdManager::generateProposalID();
		proposal->is_anonymous = is_anonymous;
		DatabaseInterface::insertProposal(proposal, solution_id); // TODO: check

		// TODO: NOTIFICATION
		
		json::value json_response = json::value();
		json_response["proposal_id"] = proposal->id;
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::editProposal() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string content = fetchPostData("content");
		trim(content);
		string proposal_id = fetchPostData("proposal_id");
		
		if (! InputValidator::isValidEditProposalInput(content, proposal_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Proposal *proposal = DatabaseInterface::searchProposal(proposal_id); // TODO: check

		if (proposal == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROPOSAL);
			return;
		}
		
		if (user_name.compare(proposal->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::editProposal(proposal_id, content); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::makeProposalCreatorVisible() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");

		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string proposal_id = fetchPostData("proposal_id");
		
		if (! InputValidator::isValidMakeProposalCreatorVisibleInput(proposal_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}

		Proposal *proposal = DatabaseInterface::searchProposal(proposal_id); // TODO: check

		if (proposal == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROPOSAL);
			return;
		}
		
		if (user_name.compare(proposal->creator_user_name) != 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::makeProposalCreatorVisible(proposal_id); // TODO: check
		
		// TODO: NOTIFICATIONS

		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::voteProposal() {
	try {
		if (! postRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		string user_name = fetchSessionData("user_name");
		
		if (! isSessionDataSet("signed_in")) {
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		string is_positive = fetchPostData("is_positive");
		string proposal_id = fetchPostData("proposal_id");

		if (! InputValidator::isValidVoteProposalInput(is_positive, proposal_id)) {
			setErrorResponseStatus(http::response::bad_request, ServerError::INVALID_PARAMETERS);
			return;
		}
		
		Proposal *proposal = DatabaseInterface::searchProposal(proposal_id); // TODO: check

		if (proposal == NULL) {
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROPOSAL);
			return;
		}
		
		if (user_name.compare(proposal->creator_user_name) == 0) {
			setErrorResponseStatus(http::response::forbidden, ServerError::UNAUTHORIZED_USER);
			return;
		}
		
		DatabaseInterface::voteProposal(proposal_id, user_name, is_positive.compare("true") == 0); // TODO: check
		
		// TODO: NOTIFICATIONS
		
		json::value json_response = json::value();
		json_response["vote_balance"] = DatabaseInterface::getProposalVoteBalance(proposal_id); // TODO: check
		writeJsonResponse(json_response);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchMainPage() {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		SessionContent content;
		setSessionDataOnViewContent(content);
		// TODO: maybe fork this: a view for the main_view when the user is signed in, and other when is not
		// TODO: maybe render another existent view when the user is signed in (according to user preferences).
		//       example: render Problems as default
		render("main_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchUserPage(string user_name) {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		User *user = DatabaseInterface::searchUser(user_name); // TODO: check
		
		if (user == NULL) {
			renderErrorPage(http::response::not_found, ServerError::NONEXISTENT_USER);
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_USER);
			return;
		}

		UserContent content;
		setSessionDataOnViewContent(content);
		// TODO: set content attributes
		/*
			User* user;
			int publication_count;
			int problem_count;
			int solution_count;
			int accepted_solution_count;
			std::list<Publication *> *recent_publications;
		*/
		render("user_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchProblemsPage() {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		EntityLinker *entityLinker = new EntityLinker();
		int i;
		
		list<Problem *> *random_problems = DatabaseInterface::searchRandomProblems(20); // TODO: check
		i = 0;
		for (list<Problem *>::const_iterator it = random_problems->begin(); it != random_problems->end(); ++it) {
			Problem *problem = *it;
			entityLinker->insert(problem);
			entityLinker->insert(DatabaseInterface::searchUser(problem->creator_user_name)); // TODO: check
			i++;
		}
		
		list<Problem *> *latest_problems = DatabaseInterface::searchLatestProblems(20); // TODO: check
		i = 0;
		for (list<Problem *>::const_iterator it = latest_problems->begin(); it != latest_problems->end(); ++it) {
			Problem *problem = *it;
			entityLinker->insert(problem);
			entityLinker->insert(DatabaseInterface::searchUser(problem->creator_user_name)); // TODO: check
			i++;
		}
		
		list<Problem *> *unsolved_problems = DatabaseInterface::searchUnsolvedProblems(20); // TODO: check
		i = 0;
		for (list<Problem *>::const_iterator it = unsolved_problems->begin(); it != unsolved_problems->end(); ++it) {
			Problem *problem = *it;
			entityLinker->insert(problem);
			entityLinker->insert(DatabaseInterface::searchUser(problem->creator_user_name)); // TODO: check
			i++;
		}
		
		entityLinker->linkEntities();
		
		ProblemsContent content;
		setSessionDataOnViewContent(content);
		content.random_problems = random_problems;
		content.latest_problems = latest_problems;
		content.unsolved_problems = unsolved_problems;
		render("problems_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchProblemPage(string problem_id) {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check
		
		if (problem == NULL) {
			renderErrorPage(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}

		ProblemContent content;
		setSessionDataOnViewContent(content);
		// TODO: set content attributes
		/*
			Problem *problem;
			Solution *accepted_solution;
			std::list<Solution *> *solutions;
			std::list<Clarification *> *clarifications;
			int user_vote;
		*/
		render("problem_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchSolutionPage(string solution_id) {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		Solution *solution = DatabaseInterface::searchSolution(solution_id); // TODO: check
		
		if (solution == NULL) {
			renderErrorPage(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_SOLUTION);
			return;
		}

		SolutionContent content;
		setSessionDataOnViewContent(content);
		// TODO: set content attributes
		/*
			Solution *solution;
			std::list<Clarification *> *clarifications;
		*/
		render("solution_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchNewProblemPage() {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		if (! isSessionDataSet("signed_in")) {
			renderErrorPage(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		SessionContent content; // TODO: check (IdeasContent?)
		setSessionDataOnViewContent(content);
		render("new_problem_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchNewSolutionPage(string problem_id) {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}

		if (! isSessionDataSet("signed_in")) {
			renderErrorPage(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			setErrorResponseStatus(http::response::unauthorized, ServerError::NOT_SIGNED_IN);
			return;
		}
		
		Problem *problem = DatabaseInterface::searchProblem(problem_id); // TODO: check
		
		if (problem == NULL) {
			renderErrorPage(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			setErrorResponseStatus(http::response::not_found, ServerError::NONEXISTENT_PROBLEM);
			return;
		}
		
		NewSolutionContent content;
		setSessionDataOnViewContent(content);
		content.problem_id = problem_id;
		render("new_solution_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}

void Server::fetchIdeasPage() {
	try {
		if (! getRequestReceived()) {
			setErrorResponseStatus(http::response::method_not_allowed, ServerError::METHOD_NOT_ALLOWED);
			return;
		}
		
		SessionContent content; // TODO: check (IdeasContent?)
		setSessionDataOnViewContent(content);
		render("ideas_view", content);
		setSuccessResponseStatus();
		
	} catch (exception &e) {
		renderErrorPage(http::response::internal_server_error, ServerError::UNKNOWN);
		setErrorResponseStatus(http::response::internal_server_error, ServerError::UNKNOWN);
	}
}
