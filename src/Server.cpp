/*
 * Server.cpp
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#include "Server.h"
#include "main_screen_content.h"
using namespace std;

Server::Server(cppcms::service &srv) :
		cppcms::application(srv) {
	dispatcher().assign("", &Server::welcome, this);
	mapper().assign("");

	dispatcher().assign("/problemsHome", &Server::problems_home, this);
	mapper().assign("problemsHome", "/problemsHome");

	dispatcher().assign("/ideasHome", &Server::ideas_home, this);
	mapper().assign("ideasHome", "/ideasHome");

	dispatcher().assign("/problem", &Server::problem, this);
	mapper().assign("problem", "/problem");

	dispatcher().assign("/solution", &Server::solution, this);
	mapper().assign("solution", "/solution");

	mapper().root("/pci");
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

void Server::welcome() {
	main_screen_content::content c;
	c.user_id = "Anonimo";
	render("welcome", c);
}

void Server::problems_home() {
	main_screen_content::problemsHome ph;

	for (int i = 0; i < 10; ++i) {
		Problem p;
		p.setID(i);
		ph.problems.push_back(p);
	}

	render("problemsHome", ph);
}

void Server::ideas_home() {
	response().out() << "Ideas Home";
}

void Server::problem() {
	response().out() << "Problem";
}

void Server::solution() {
	response().out() << "Solution";
}

int main(int argc, char ** argv) {
	try {
		cppcms::service srv(argc, argv);
		srv.applications_pool().mount(cppcms::applications_factory<Server>());

		cerr << "Server started!" << endl;
		srv.run();
	} catch (std::exception const &e) {
		cerr << e.what() << std::endl;
	}
}
