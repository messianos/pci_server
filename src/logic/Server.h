
#ifndef SERVER_H_
#define SERVER_H_

// Includes
#include "../auxiliar/EntityLinker.h"
#include "../auxiliar/ServerError.h"
#include "../entity/Clarification.h"
#include "../entity/Notification.h"
#include "../entity/Problem.h"
#include "../entity/Proposal.h"
#include "../entity/Solution.h"
#include "../entity/User.h"
#include "../service/DatabaseInterface.h"
#include "../service/IdManager.h"
#include "../service/InputValidator.h"
#include "../service/PasswordManager.h"
#include "ViewContent.h"
#include <boost/algorithm/string.hpp>
#include <cppcms/application.h>
#include <cppcms/http_context.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <cppcms/service.h>
#include <cppcms/session_interface.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <exception>
#include <list>
#include <string>

class Server : public cppcms::application {

private:
	bool getRequestReceived();
	bool postRequestReceived();
	std::string fetchPostData(std::string parameter);
	bool isSessionDataSet(std::string parameter);
	std::string fetchSessionData(std::string parameter);
	void setSessionData(std::string parameter);
	void setSessionData(std::string parameter, std::string value);
	void clearSessionData();
	void clearSessionData(std::string parameter);
	void setSessionDataOnViewContent(ViewContent::SessionContent &content);
	void renderErrorPage(int http_error_code, std::string server_error_code);
	void writeJsonResponse(cppcms::json::value json_response);
	void setSuccessResponseStatus();
	void setErrorResponseStatus(int http_error_code, std::string server_error_code);

public:
	Server(cppcms::service &service);
	virtual ~Server();
	void main(std::string url);
	void signIn();
	void signOut();
	void toggleAnonymousMode();
	void userExists();
	void unseenNotifications();
	void signUp();
	void publicateProblem();
	void editProblem();
	void makeProblemCreatorVisible();
	void voteProblem();
	void setAcceptedSolution();
	void unsetAcceptedSolution();
	void publicateSolution();
	void editSolution();
	void makeSolutionCreatorVisible();
	void voteSolution();
	void askClarification();
	void answerClarification();
	void publicateProposal();
	void editProposal();
	void makeProposalCreatorVisible();
	void voteProposal();
	void fetchMainPage();
	void fetchUserPage(std::string user_name);
	void fetchProblemsPage();
	void fetchProblemPage(std::string problem_id);
	void fetchSolutionPage(std::string solution_id);
	void fetchNewProblemPage();
	void fetchNewSolutionPage(std::string problem_id);
	void fetchIdeasPage();
};

#endif /* SERVER_H_ */
