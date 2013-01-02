/*
 * Server.cpp
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#include "Server.h"


using namespace std;

Server::Server(cppcms::service &srv) :
					cppcms::application(srv)  {
	dispatcher().assign()

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

void Server::main(string url){
	cerr << "hello world!";
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
