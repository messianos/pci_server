
// Includes
#include "Main.h"

// Namespaces
using namespace cppcms;
using namespace std;


// TODO: To be removed, debugging purposes
/***************************************/
#include "../service/DatabaseInterface.h"
#include <iostream>

void database_operations_tester(){
	cerr << "/**********************************************/" << endl;
	cerr << "	Database tester enabled" << endl;
	cerr << "/**********************************************/" << endl;
	cerr << "Output >>" << endl;
	cerr << "/**********************************************/" << endl;
}
/***************************************/

int main(int argc, char **argv) {
	try {
		service service(argc, argv);
		service.applications_pool().mount(applications_factory<Server>());
		cerr << "Server started!" << endl;

		//database_operations_tester();

		service.run();

	} catch (exception const &e) {
		cerr << e.what() << endl;
	}
}
