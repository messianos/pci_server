
#ifndef SERVER_H_
#define SERVER_H_

// Includes
#include "DatabaseInterface.h"
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
	void setSessionProperties(ViewContent::TemplateContent& content);
	void ideas();
	void index();
	void newProblem();
	void problem(std::string id);
	void problems();
	void signIn();
	void signOut();
	void signUp();
	void solution(std::string id);
	void user(std::string user_name);
};

#endif /* SERVER_H_ */
