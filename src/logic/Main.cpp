
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

	cerr << DatabaseInterface::getUserVoteOnProblem("nicoocho", "50FA183967B4F849F596A214679AFC66C3") << endl;
	cerr << DatabaseInterface::getUserVoteOnProblem("nicoocho", "5095FA872A43A44C929AE056853A2F740B") << endl;
	cerr << DatabaseInterface::getUserVoteOnSolution("nicoocho", "53A50334E85EF943E19EA4996E62D16F2F") << endl;

	cerr << DatabaseInterface::getProblemVoteBalance("5095FA872A43A44C929AE056853A2F740B") << endl;

	cerr << "/**********************************************/" << endl;
}
/***************************************/

int main(int argc, char **argv) {
	try {
		service service(argc, argv);
		service.applications_pool().mount(applications_factory<Server>());
		cerr << "Server started!" << endl;

		database_operations_tester();

		service.run();

	} catch (exception const &e) {
		cerr << e.what() << endl;
	}
}
