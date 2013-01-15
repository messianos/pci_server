
// Includes
#include "Server.h"
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <iostream>

// Namespaces
using namespace cppcms;
using namespace std;

int main(int argc, char **argv) {
	try {

		service service(argc, argv);
		service.applications_pool().mount(applications_factory<Server>());

		cerr << "Server started!" << endl;
		service.run();

	} catch (exception const &e) {
		cerr << e.what() << endl;
	}
}
