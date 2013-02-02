
#ifndef SERVER_H_
#define SERVER_H_

// Includes
#include "DatabaseInterface.h"
#include "Date.h"
#include "ErrorCode.h"
#include "IDManager.h"
#include "InputValidator.h"
#include "PasswordManager.h"
#include "Problem.h"
#include "ViewContent.h"
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <string>

class Server : public cppcms::application {

public:
	Server(cppcms::service &service);
	virtual ~Server();
	void setSessionProperties(ViewContent::TemplateContent &content);
	ErrorCode *processNewProblemPost(ViewContent::NewProblemFormInfo &form_info);
	ErrorCode *processNewSolutionPost(ViewContent::NewSolutionFormInfo &form_info, std::string problem_id);
	ErrorCode *processSignInPost(ViewContent::SignInFormInfo &form_info);
	ErrorCode *processSignUpPost(ViewContent::SignUpFormInfo &form_info);
	void ideas();
	void index();
	void newProblem();
	void newSolution(std::string problem_id);
	void problem(std::string id);
	void problems();
	void signOut();
	void solution(std::string problem_id, std::string solution_id);
	void user(std::string user_name);
};

#endif /* SERVER_H_ */
