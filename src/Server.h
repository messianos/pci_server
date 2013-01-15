
#ifndef SERVER_H_
#define SERVER_H_

// Includes
#include "ViewContent.h"
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>

class Server {

public:
	Server(cppcms::service &service);
	virtual ~Server();
	void welcome();
};

#endif /* SERVER_H_ */
