/*
 * Server.h
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <stdlib.h>
#include <iostream>
#include "DatabaseInterface.h"

using namespace std;

class Server : public cppcms::application {
private:
	DatabaseInterface* db;
public:
	Server();
	Server(cppcms::service &srv);
	virtual ~Server();
	void welcome();
	void problems_home();
	void ideas_home();
	void problem();
	void solution();
};

#endif /* SERVER_H_ */
