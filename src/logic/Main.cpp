
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

	Notification* notification = new Notification();
	notification->user_name = "nicoocho";
	notification->seen = 0;
	notification->url = "/publication/5099218C4F6FB04F1F9C5C5632C15E672A";
	notification->message = "Notificacion de prueba";

	DatabaseInterface::insertNotification(notification);

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
