#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>

// For DB
#include <cppdb/frontend.h>
#include <ctime>

// For Template
#include "main_screen_content.h"

using namespace std;

class pci: public cppcms::application {
public:
	pci(cppcms::service &srv) :
			cppcms::application(srv) {
	}
	virtual void main(std::string url);
};

void pci::main(std::string /*url*/) {

	cerr << "Hello world!" << endl;

	main_screen_content::content c;
	// For DB
	try {
		// Scheme mysql:database=test;user=joe;password='secret'
		cppdb::session sql(
				"mysql:database=cppcms;user=cpp_user;password='cpp_user'");

		cppdb::result res = sql
				<< "SELECT name FROM fruit ORDER BY RAND() LIMIT 1";

		while (res.next()) {
			string name;
			res >> name;
			c.user_id = name;
		}
	} catch (exception const &e) {
		cerr << "ERROR: " << e.what() << endl;
	}

	render("welcome", c);
}

int main(int argc, char ** argv) {
	try {
		cppcms::service srv(argc, argv);
		srv.applications_pool().mount(cppcms::applications_factory<pci>());

		cerr << "Server started!" << endl;
		srv.run();
	} catch (std::exception const &e) {
		cerr << e.what() << std::endl;
	}
}
