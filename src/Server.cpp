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
	db = new DatabaseInterface();

	dispatcher().assign("", &Server::welcome, this);
	mapper().assign("");

	dispatcher().assign("/problemsHome", &Server::problems_home, this);
	mapper().assign("problemsHome", "/problemsHome");

	dispatcher().assign("/ideasHome", &Server::ideas_home, this);
	mapper().assign("ideasHome", "/ideasHome");

	dispatcher().assign("/problem/(\\d+)", &Server::problem, this, 1);
	mapper().assign("problem", "/problem/{1}");

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

	for (int i = 0; i < 1; ++i) {
		Problem* p = db->getProblem(1000);
		ph.problems.push_back(p);
	}

	render("problemsHome", ph);
}

void Server::ideas_home() {
	response().out() << "Ideas Home";
}

void Server::problem(string problem_id) {
	int p_id = atoi(problem_id.c_str());
	main_screen_content::problemInfo problem_info;

	Problem* problem = db->getProblem(p_id);
	problem_info.problem = problem;
	if(problem->is_solved){
		problem_info.accepted_solution = db->getSolution(
					problem->accepted_solution_id);
	}

	render("problemInfo", problem_info);
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

