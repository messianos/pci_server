
#ifndef SERVER_H_
#define SERVER_H_

// Includes
#include "Clarification.h"
#include "DatabaseInterface.h"
#include "IDManager.h"
#include "InputValidator.h"
#include "PasswordManager.h"
#include "ViewContent.h"
#include <boost/algorithm/string.hpp>
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <cppcms/service.h>
#include <cppcms/session_interface.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <string>

class Server : public cppcms::application {

private:
	bool getRequestReceived();
	bool postRequestReceived();
	std::string postRequestData(std::string name);
	void setSessionProperties(ViewContent::TemplateContent &content);

public:
	Server(cppcms::service &service);
	virtual ~Server();
	void debug(); // TODO: remove this (debugging purposes)
	void postSignIn();
	void postSignOut();
	void postCreateUser();
	//void postDeleteUser();
	void postCreateProblem();
	void postEditProblem();
	//void postDeleteProblem();
	void postVoteProblem();
	void postSetAcceptedSolution();
	void postUnsetAcceptedSolution();
	void postCreateSolution();
	void postEditSolution();
	//void postDeleteSolution();
	void postVoteSolution();
	void postCreateClarification();
	void postEditClarification();
	//void postDeleteClarification();
	void getFetchMainPage();
	void getFetchUserPage(std::string user_name);
	void getFetchProblemsPage();
	void getFetchProblemPage(std::string problem_id);
	void getFetchSolutionPage(std::string problem_id, std::string solution_id);
	void getFetchNewProblemPage();
	void getFetchNewSolutionPage(std::string problem_id);
	void getFetchIdeasPage();
};

#endif /* SERVER_H_ */
