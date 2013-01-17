
#ifndef SERVER_H_
#define SERVER_H_

// Includes
#include "DatabaseInterface.h"
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
	void welcome();
	void signIn();
	void problems();
	void problem(std::string id);
	void solution(std::string id);
	void ideas();
};

#endif /* SERVER_H_ */
